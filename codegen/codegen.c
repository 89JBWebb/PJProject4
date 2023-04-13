#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <util/string_utils.h>
#include <util/symtab.h>
#include <util/symtab_stack.h>
#include <util/dlink.h>
#include "reg.h"
#include "codegen.h"
#include "types.h"
#include "symfields.h"

extern SymTable globalSymtab;
extern SymtabStack localSymStack;
//functions should link to their parent
//variables should link to their scope and offset
extern int globalOffset;
extern int localOffset;
extern int dataSize;
extern int isGlobal;

static void printDataDeclaration(DNode decl);
static void printInstruction(DNode inst);
static char* makeDataDeclaration(DList dataList, char *str);
static int emitBinaryExpression(DList instList, int leftOperand, int rightOperand, char* opcode);
static int emitBinaryCompareExpression(DList instList, int leftOperand, int rightOperand,
				       char *opcode);
static void makeLabel(char label[20]);

/**
 * Print a data declaration to stdout. This function is called by dlinkApply only.
 *
 * @param decl a DNode containing a data declaration
 */
static void printDataDeclaration(DNode decl) {
	printf("\t%s\n",(char*)dlinkNodeAtom(decl));
}

/**
 * Emit the assembly prologue for a procedure
 * @param instList a list of instructions
 * @param name procedure/function name
 */
void emitProcedurePrologue(DList instList, char* name) {
	char* inst = nssave(2,"\t.globl ",name);
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = nssave(3,"\t.type ",name,",@function");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = nssave(2,name,":\tnop");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = ssave("\tpushq %rbp");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = ssave("\tmovq %rsp, %rbp");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	//free all registers

}

void raiseStack(DList instList){
	char offsetStr[10];
	int offset = (int) SymGetField( currentSymtab( localSymStack ), " ", "offset" );
	char *inst;

	if(offset%16 != 0){
		offset+= 16-(offset%16);
	}

	if(offset != 0){
		snprintf(offsetStr,9,"%d",offset);
		inst = nssave(3,"\tsubq $", offsetStr, ", %rsp");
  		dlinkAppend(instList,dlinkNodeAlloc(inst));
	}

	int *toSave = getCalleeSavedRegisters();
	for(int i = 0; i < 5; i++){
		inst = nssave(2,"\tpushq ", get64bitIntegerRegisterName(toSave[i]));
  		dlinkAppend(instList,dlinkNodeAlloc(inst));
	}

	inst = ssave("\tsubq $8, %rsp");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

}


/**
 * Print the assembly prologue that includes the data section, declare the global area and string consts 
 *
 * @param dataList a list of data declarations (strings)
 */
void emitDataPrologue(DList dataList) {

	printf("\t.section\t.rodata\n");
	if (globalOffset != 0)
		printf("\t.comm _gp, %d, 4\n",globalOffset);  
		                                               
	dlinkApply(dataList,(DLinkApplyFunc)printDataDeclaration);
	printf("\t.text\n");
}

/**
 * Print an assembly instruction to stdout. This function is only called by dlinkApply.
 *
 * @param inst a DNode containing an assembly instruction.
 */
static void printInstruction(DNode inst) {
	printf("%s\n",(char*)dlinkNodeAtom(inst));
}

/**
 * Print all of the assembly instructions for the main routine to stdout.
 *
 * @param instList a DList of assembly instructions.
 */
void emitInstructions(DList instList) {
	dlinkApply(instList,(DLinkApplyFunc)printInstruction);
}

/**
 * Add an instruction that performs an assignment.
 *
 * @param instList a DList of assembly instructions
 * @param lhsRegIndex the register index of the register for the l-value address
 * @param rhsRegIndex the register index of the register for the r-value
 */
void emitAssignment(DList instList, int lhsRegIndex, int rhsRegIndex) {
	char *inst;
	
	inst = nssave(5,  "\tmovl ", getIntegerRegisterName(rhsRegIndex),
			", (", get64bitIntegerRegisterName(lhsRegIndex), ")");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister(lhsRegIndex);
	freeIntegerRegister(rhsRegIndex);
}

void emitJumpPoint(DList instList, int jumpIndex){
	char *inst;
	char num[8];
    sprintf(num, "%d", jumpIndex);
	inst = nssave(3, "j", num, ": nop");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	
}

void emitJump(DList instList, int jumpIndex){
	char *inst;
	char num[8];
   sprintf(num, "%d", jumpIndex);
	inst = nssave(2, "\tjmp j", num);
	dlinkAppend(instList,dlinkNodeAlloc(inst));
}

void emitCJump(DList instList, int regIndex, int jumpIndex){
	char *inst;
   inst = nssave(2, "\tcmpl $1, ", getIntegerRegisterName(regIndex));
   dlinkAppend(instList,dlinkNodeAlloc(inst));
	freeIntegerRegister(regIndex);
	char num[8];
	sprintf(num, "%d", jumpIndex);
	inst = nssave(2, "\tjne j", num);
   dlinkAppend(instList,dlinkNodeAlloc(inst));
}

/**
 * Add the instructions needed to read a variable using the scanf system call.
 *
 * @param instList a DList of instructions
 * @param dataList a Dlist of data declarations
 * @param addrIndex the register index of the register holding the address that is to be read into
 */
void emitReadVariable(DList instList, DList dataList, int addrIndex) {
    char *inst;
    char *fmtLabel = makeDataDeclaration(dataList, "\"%d\"");
	inst = nssave(3,"\tleaq ", fmtLabel, "(%rip), %rdi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	free(fmtLabel);
	 
	inst = nssave(3,"\tmovq ", get64bitIntegerRegisterName(addrIndex), ", %rsi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = ssave("\tmovl $0, %eax");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	emitCallNoReturn(instList, "scanf@PLT");

	freeIntegerRegister(addrIndex);
}


/**
 * Add the instructions needed to write a value using the printf system call.
 *
 * @param instList a Dlist of instructions
 * @param dataList a Dlist of data declarations
 * @param writeType write vs writeln
 * @param regIndex the index of the register to be printed
 * @param length restricted length of the output
 */
void emitWriteExpression(DList instList, DList dataList, int writeType, int regIndex, char *length) {
	char *inst;
	char *fmtLabel;
	char *fmtStr;
	char lenStr[10];

	if (length)		
 	   strcpy(lenStr, length);
	else
	   strcpy(lenStr, "");

	if (writeType == IS_WRITE)
	  fmtStr = nssave(3, "\"%", lenStr, "d\"");  
	else
	  fmtStr = nssave(3, "\"%", lenStr, "d\\n\"");  
	
    fmtLabel = makeDataDeclaration(dataList, fmtStr);
	free(fmtStr);
	  
	inst = nssave(3, "\tleaq ", fmtLabel, "(%rip), %rdi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
    free(fmtLabel);
	
	inst = nssave(3,"\tmovl ", getIntegerRegisterName(regIndex), ", %esi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = ssave("\tmovl $0, %eax");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	freeIntegerRegister(regIndex);
	  
	emitCallNoReturn(instList, "printf@PLT");
}

/**
 * Add the instructions needed to write a string using the printf system call.
 *
 * @param instList a Dlist of instructions
 * @param dataList a Dlist of data declarations
 * @param writeType write vs writeln
 * @param str the string to print
 * @param length restricted length of the output
 */
void emitWriteString(DList instList,  DList dataList, int writeType, char *str, char *length) {
    char *inst;
	char *fmtLabel;
	char *fmtStr;
	char lenStr[10];

	if (length)		
 	   strcpy(lenStr, length);
	else
	   strcpy(lenStr, "");

	if (writeType == IS_WRITE)
	  fmtStr = nssave(3, "\"%", lenStr, "s\"");  
	else
	  fmtStr = nssave(3, "\"%", lenStr, "s\\n\"");  
	
	inst = ssave("\tmovl $0, %eax");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

    fmtLabel = makeDataDeclaration(dataList, fmtStr);
	free(fmtStr);
	inst = nssave(3, "\tleaq ", fmtLabel, "(%rip), %rdi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
    free(fmtLabel);

	char *quotedStr = nssave(3, "\"", str, "\"");
	char *strLabel = makeDataDeclaration(dataList, quotedStr);

	inst = nssave(4,"\tleaq ", strLabel, "(%rip), ", "%rsi");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	free(strLabel);

	emitCallNoReturn(instList, "printf@PLT");
}

/**
 * Add an instruction that performs a binary computation.
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @param opcode the opcode of the x86 assembly instruction
 * @return
 */
static int emitBinaryExpression(DList instList, int leftOperand, int rightOperand, char* opcode) {
	char* leftName = getIntegerRegisterName(leftOperand);
	char* rightName = getIntegerRegisterName(rightOperand);

	char* inst = nssave(6,"\t",opcode," ", rightName,", ",leftName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister(rightOperand);

	return leftOperand;
}

/**
 * Add instructions for logical or
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitOrExpression(DList instList, int leftOperand, int rightOperand) {
	return emitBinaryExpression(instList,leftOperand,rightOperand,"orl");
}

/**
 * Add instructions for logical and
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitAndExpression(DList instList, int leftOperand, int rightOperand) {
	return emitBinaryExpression(instList,leftOperand,rightOperand,"andl");
}

/**
 * Add instructions for logical not
 *
 * @param instList a DList of instructions
 * @param operand the register index of the register holding the operand
 * @return the register index for the result register
 */
int emitNotExpression(DList instList, int operand) {
 	int tmpOp = allocateIntegerRegister();
	char *tmpName = getIntegerRegisterName(tmpOp);
	
	char* inst = nssave(2, "\tmovl $1, ", tmpName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	emitBinaryExpression(instList, operand, tmpOp, "xorl");

	freeIntegerRegister(tmpOp);
	
	return operand;	
}

/**
 * Add instructions that performs a binary comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @param opcode the opcode of the x86 assembly instruction
 * @return the register index for the result register
 */
static int emitBinaryCompareExpression(DList instList, int leftOperand, int rightOperand,
				       char *opcode) {
	leftOperand = emitBinaryExpression(instList,leftOperand,rightOperand,"cmpl");
	freeIntegerRegister(rightOperand);

	char *inst = nssave(2,"\tmovl $0, ", getIntegerRegisterName(leftOperand));
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	int tregIndex = allocateIntegerRegister();

	inst = nssave(2,"\tmovl $1, ", getIntegerRegisterName(tregIndex));
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	return emitBinaryExpression(instList,leftOperand,tregIndex,opcode);
}

/**
 * Add instructions that performs a == comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitEqualExpression(DList instList, int leftOperand, int rightOperand) {
    return emitBinaryCompareExpression(instList,leftOperand,rightOperand,"cmove");
}
/**
 * Add instructions that performs a != comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */

int emitNotEqualExpression(DList instList, int leftOperand, int rightOperand) {
  return emitBinaryCompareExpression(instList,leftOperand,rightOperand,"cmovne");
}

/**
 * Add instructions that performs a <= comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitLessEqualExpression(DList instList, int leftOperand, int rightOperand) {
  return emitBinaryCompareExpression(instList,leftOperand,rightOperand,"cmovle");
}

/**
 * Add instructions that performs a < comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitLessThanExpression(DList instList,int leftOperand, int rightOperand) {
  return emitBinaryCompareExpression(instList,leftOperand,rightOperand,"cmovl");
}

/**
 * Add instructions that performs a >= comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 */
int emitGreaterEqualExpression(DList instList, int leftOperand, int rightOperand) {
  return emitBinaryCompareExpression(instList,leftOperand,rightOperand,"cmovge");
}

/**
 * Add instructions that performs a > comparison
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitGreaterThanExpression(DList instList, int leftOperand, int rightOperand) {
  return emitBinaryCompareExpression(instList,leftOperand,rightOperand,"cmovg");
}


/**
 * Add instructions that performs addtion
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitAddExpression(DList instList, int leftOperand, int rightOperand) {
	return emitBinaryExpression(instList,leftOperand,rightOperand,"addl");
}

/**
 * Add instructions that performs substruction
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitSubtractExpression(DList instList, int leftOperand, int rightOperand) {
	return emitBinaryExpression(instList,leftOperand,rightOperand,"subl");
}

/**
 * Add instructions that performs multiplication
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitMultiplyExpression(DList instList, int leftOperand, int rightOperand) {
	return emitBinaryExpression(instList,leftOperand,rightOperand,"imull");
}

/**
 * Add instructions that performs division
 *
 * @param instList a DList of instructions
 * @param leftOperand the register index of the register holding the left operand
 * @param rightOperand the register index of the register holding the right operand
 * @return the register index for the result register
 */
int emitDivideExpression(DList instList, int leftOperand, int rightOperand) {
        char *inst;
	
	    inst = nssave(3,"\tmovl ", getIntegerRegisterName(leftOperand), ", %eax");
	    dlinkAppend(instList,dlinkNodeAlloc(inst));


		inst = ssave("\tcdq");
		dlinkAppend(instList,dlinkNodeAlloc(inst));

		inst = nssave(2,"\tidivl ", getIntegerRegisterName(rightOperand));
		dlinkAppend(instList,dlinkNodeAlloc(inst));

	    inst = nssave(2,"\tmovl %eax, ", getIntegerRegisterName(leftOperand)); 
		dlinkAppend(instList,dlinkNodeAlloc(inst));


	    freeIntegerRegister(rightOperand);

		return leftOperand;
}

/**
 * Add an instruction to compute the address of a variable.
 *
 * @param instList a Dlist of instructions
 * @param varIndex the register index for a variable
 * @return the register index of the address register
 */
int emitComputeGlobalAddress(DList instList, char *name) {
	
  int addrRegIndex = allocateIntegerRegister();   
  char* addrRegName = (char*)get64bitIntegerRegisterName(addrRegIndex);

  int offset = (int)SymGetField(globalSymtab, name,"offset");
  char offsetStr[10];
  snprintf(offsetStr,9,"%d",offset);

  char *inst; 
  inst = nssave(2,"\tleaq _gp(%rip), ", addrRegName);
  dlinkAppend(instList,dlinkNodeAlloc(inst));
  inst = nssave(4,"\taddq $", offsetStr, ", ", addrRegName);
  dlinkAppend(instList,dlinkNodeAlloc(inst));
  
  return addrRegIndex;
}

/**
 * Add an instruction to compute the address of a variable.
 *
 * @param instList a Dlist of instructions
 * @param varIndex the register index for a variable
 * @return the register index of the address register
 */
int emitComputeLocalAddress(DList instList, char *name) {
	
	int addrRegIndex = allocateIntegerRegister();   
	char* addrRegName = (char*)get64bitIntegerRegisterName(addrRegIndex);

	int backtraces = 0;
	int offset = 0;

	offset = (int)SymGetField( currentSymtab(localSymStack), name, "offset");
	if(offset == -1){
		freeIntegerRegister(addrRegIndex);
		return emitComputeGlobalAddress(instList, name);
	}

	char offsetStr[10];
	snprintf(offsetStr,9,"%d",offset);

	char *inst;

	inst = nssave(2,"\tmovq %rbp, ", addrRegName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	if(offset != 0){
		inst = nssave(4,"\tsubq $", offsetStr, ", ", addrRegName);
		dlinkAppend(instList,dlinkNodeAlloc(inst));
	}
	return addrRegIndex;
}

/**
 * Compute the address of an array element and store it in a register.
 *
 * @param instList a list of instructions
 * @param varIndex the symbol table index of the array variable
 * @param subIndex1 index of the register holding the 1st subscript value
 * @param subIndex2 index of the register holding the 2nd subscript value
 * @return the symbol table index of the register holding the address of the
 * 		   array element.
 */
int emitCompute2DArrayAddress(DList instList, char *name, int subIndex1, int subIndex2) {
	int varTypeIndex = (int)SymGetField(globalSymtab,name,"type");

	int r =  emitComputeLocalAddress(instList, name);
	char *regName = get64bitIntegerRegisterName(r);

	/* compute offset based on subscript */		        
	int tReg = allocateIntegerRegister();
	char* sub1Reg32Name = getIntegerRegisterName(subIndex1);
	char* sub1RegName = get64bitIntegerRegisterName(subIndex1);
	char* tname = get64bitIntegerRegisterName(tReg);
		
	char *inst = nssave(4,"\tmovslq ", sub1Reg32Name, ", ", sub1RegName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	char offsetStr[10];
	int base1 = get1stDimensionbase(varTypeIndex);
	snprintf(offsetStr,9,"%d",base1);
	inst = nssave(4, "\tsubq $", offsetStr, ", ", sub1RegName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	int dim = get2ndDimensionSize(varTypeIndex);
	snprintf(offsetStr,9,"%d",dim);
	inst = nssave(4, "\tmovq $", offsetStr, ", ", tname);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = nssave(4, "\timulq ", tname, ", ", sub1RegName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	freeIntegerRegister(tReg);

	char* sub2Reg32Name = getIntegerRegisterName(subIndex2);
	char* sub2RegName = get64bitIntegerRegisterName(subIndex2);
	
	inst = nssave(4,"\tmovslq ", sub2Reg32Name, ", ", sub2RegName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = nssave(4, "\taddq ", sub2RegName, ", ", sub1RegName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	
	int base2 = get2ndDimensionbase(varTypeIndex);
	snprintf(offsetStr,9,"%d",base2);
	inst = nssave(4, "\tsubq $", offsetStr, ", ", sub1RegName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	// to do: use element size below
	inst = nssave(2,"\timulq $4, ", sub1RegName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	/* compute element address */
	inst = nssave(4,"\taddq ", sub1RegName, ", ", regName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));	 
	
	freeIntegerRegister(subIndex1);
	freeIntegerRegister(subIndex2);
	return r;

}


/**
 * Compute the address of an local array element and store it in a register.
 * If there is no local array then search for it in global symbal table
 *
 * @param instList a list of instructions
 * @param varIndex the symbol table index of the array variable
 * @param subIndex index of the register holding the subscript value
 * @return the symbol table index of the register holding the address of the
 * 		   array element.
 */
int emitComputeLocalArrayAddress(DList instList, char *name, int subIndex) {
	int offset = (int)SymGetField(currentSymtab(localSymStack),name,"offset");
	int type = (int)SymGetField(currentSymtab(localSymStack),name,"type");

	if (offset == -1){
		return emitComputeGlobalArrayAddress(instList, name, subIndex);
	}

	int regIndex = allocateIntegerRegister();
	int reg = emitComputeLocalAddress(instList, name);

	/* compute offset based on subscript */
	char* subReg32Name = getIntegerRegisterName(subIndex);
	char* subRegName = get64bitIntegerRegisterName(subIndex);

	// to do: use element size below
	char offsetStr[20];
	snprintf(offsetStr,9,"%d",get1stDimensionbase(type));
	char *inst = nssave(4,"\tsubq $", offsetStr, ", ", subRegName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = nssave(2,"\timulq $4, ", subRegName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	/* compute element address */
	inst = nssave(4,"\taddq ", subRegName, ", ", get64bitIntegerRegisterName(reg));
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	
	freeIntegerRegister(subIndex);

	return reg;

}

/**
 * Compute the address of an array element and store it in a register.
 *
 * @param instList a list of instructions
 * @param varIndex the symbol table index of the array variable
 * @param subIndex index of the register holding the subscript value
 * @return the symbol table index of the register holding the address of the
 * 		   array element.
 */
int emitComputeGlobalArrayAddress(DList instList, char *name, int subIndex) {
	int regIndex = allocateIntegerRegister();
	int offset = (int)SymGetField(globalSymtab,name,"offset");
	int type = (int)SymGetField(globalSymtab,name,"type");
	int reg = emitComputeLocalAddress(instList, name);

	/* compute offset based on subscript */
	char* subReg32Name = getIntegerRegisterName(subIndex);
	char* subRegName = get64bitIntegerRegisterName(subIndex);

	// to do: use element size below
	char offsetStr[20];
	snprintf(offsetStr,9,"%d",get1stDimensionbase(type));
	char *inst = nssave(4,"\tsubq $", offsetStr, ", ", subRegName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = nssave(2,"\timulq $4, ", subRegName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	/* compute element address */
	inst = nssave(4,"\taddq ", subRegName, ", ", get64bitIntegerRegisterName(reg));
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	
	freeIntegerRegister(subIndex);

	return reg;

}

/**
 * Add an instruction to load a variable from memory.
 *
 * @param instList a Dlist of instructions
 * @param regIndex the register index for the address of a variable
 * @return the register index of the result register
 */
int emitLoadVariable(DList instList, int regIndex) {
	int dstRegIndex = allocateIntegerRegister();
	char* dstRegName = getIntegerRegisterName(dstRegIndex);

	char* srcAddrRegName = get64bitIntegerRegisterName(regIndex);

	char *inst = nssave(4,"\tmovl (",srcAddrRegName,"), ", dstRegName);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister(regIndex);

	return dstRegIndex;
}

/**
 * Add an instruction to load an integer constant
 *
 * @param instList a Dlist of instructions
 * @param intConst the const string of an integer constant
 * @return the register index of the result register holding the const
 */
int emitLoadIntegerConstant(DList instList, char * intConst) {
	int regIndex = allocateIntegerRegister();
	char* regName = (char*)getIntegerRegisterName(regIndex);
	
	char *inst = nssave(4,"\tmovl $", intConst, ", ", regName);

	dlinkAppend(instList,dlinkNodeAlloc(inst));

	return regIndex;
}

/**
 * Add a .asciiz declaration for a string constant if it hasn't been declared
 *
 * @param dataList a DList of data declarations
 * @param str string constant to put into data section
 * @return the label of the string constant
 */
static char* makeDataDeclaration(DList dataList, char* str) {
	static int stringNum = 0;
	int symIndex = SymQueryIndex(globalSymtab, str);
	int labelcount;
	char* strLabel = (char*)malloc(sizeof(char)*15);
		
	if (symIndex == SYM_INVALID_INDEX) {
	   symIndex = SymIndex(globalSymtab, str);
	   labelcount = stringNum++;
           SymPutFieldByIndex(globalSymtab,symIndex,SYMTAB_OFFSET_FIELD, (Generic)labelcount);

	   snprintf(strLabel, 17, ".string_const%d",labelcount);

	   char* decl = nssave(3, strLabel, ": .string ", str);
 	   dlinkAppend(dataList,dlinkNodeAlloc(decl));
	} else {
	   labelcount = (int)SymGetFieldByIndex(globalSymtab,symIndex,SYMTAB_OFFSET_FIELD);
	   snprintf(strLabel,15,".string_const%d",labelcount);
	}

	return strLabel;
}

/**
 * Add an identifier to the symbol table and store its offset in the activation record.
 * This function is called by dlinkApply1.
 *
 * @param node a node on a linked list containing the symbol table index of a variable
 *                delcared in a program
 * @param gtypeid typeid of the variable 
 */
void addIdToSymtab(DNode node, Generic gtypeid) {
	int symIndex = (int)dlinkNodeAtom(node);
	int offset;
	int typeid = (int)gtypeid;
	int typeSize = getTypeSize(typeid);
	SymPutFieldByIndex(globalSymtab, symIndex, SYMTAB_OFFSET_FIELD, (Generic)(globalOffset));
	SymPutFieldByIndex(globalSymtab, symIndex, SYMTAB_TYPE_INDEX_FIELD, (Generic)typeid);
	globalOffset += typeSize;
}

/**
 * Add an identifier to the symbol table and store its offset in the activation record.
 * This function is called by dlinkApply1.
 *
 * @param node a node on a linked list containing the symbol table index of a variable
 *                delcared in a program
 * @param gtypeid typeid of the variable 
 */
void addIdToSymStack(DNode node, Generic gtypeid) {
	char *id = (char *)dlinkNodeAtom(node);
	int offset;
	int typeid = (int)gtypeid;
	int typeSize = getTypeSize(typeid);

	offset = (int) SymGetField( currentSymtab(localSymStack), " ", "offset");

	if(!isGlobal){
		offset+= typeSize;
		SymPutField( currentSymtab(localSymStack), " ", "offset", (Generic) offset);
	}

	SymPutField( currentSymtab(localSymStack), id, "offset", (Generic)(offset));
    SymPutField( currentSymtab(localSymStack), id, "type", (Generic)typeid);
	
	if(isGlobal){
		offset+= typeSize;
		SymPutField( currentSymtab(localSymStack), " ", "offset", (Generic) offset);
	}

}

/**
 * Print out the procedure exit instructios
 *
 * @param instList a DList of instructions
 * @param regIndex the register for which the return value is stored2
 */
void emitProcedureExitWithReturn(DList instList, int regIndex) {
	char *inst = nssave(3, "\tmovl ", getIntegerRegisterName(regIndex), ", %eax");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = ssave("\taddq $8, %rsp");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	int *toSave = getCalleeSavedRegisters();
	for(int i = 4; i >= 0; i--){
		inst = nssave(2,"\tpopq ", get64bitIntegerRegisterName(toSave[i]));
  		dlinkAppend(instList,dlinkNodeAlloc(inst));
	}


	inst = ssave("\tmovq %rbp, %rsp");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = ssave("\tpopq %rbp");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = ssave("\tret");
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	for(int i = 0; i < 10; i++){
		if(isAllocatedIntegerRegister(i)){
			freeIntegerRegister(i);
		}
	}

}

/**
 * Print out the procedure exit instructios
 *
 * @param instList a DList of instructions
 */
void emitProcedureExit(DList instList) {
	char *inst = ssave("\tleave");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
	inst = ssave("\tret");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
}

/**
 * Create a unique label
 * @param label a character array of size 20 in which the label will be stored
 */
static void makeLabel(char label[20]) {
        static int labelCount = 0;
        snprintf(label,19,".L%d",labelCount++);
}

/**
 * Insert instructions to test whether the expression of a if-statement is false, if false, branch around the then-part
 * of the if-statement.
 *
 * @param instList a list of instructions
 * @param regIndex the index of the register holding the rest of the test expression of an if-statement
 * @return the symbol table index of the label that must follow the then-part of an if-statement
 */
int emitIfTest(DList instList, int regIndex) {
	char label[20];
	makeLabel(label);

	int treg = allocateIntegerRegister();
	char *symReg = getIntegerRegisterName(treg);

	char* inst = nssave(2,"\tmovl $-1, ", symReg);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = nssave(4,"\ttestl ", getIntegerRegisterName(regIndex), ", ",symReg);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister(regIndex);
	freeIntegerRegister(treg);

	inst = nssave(2,"\tje ",label); /* jump to false*/
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	return SymIndex(globalSymtab,label);
}

/**
 * Insert a nop as a branch target in the list of instructions.
 *
 * @param instList a list of instructions
 * @param endLabelIndex the symbol table index of the label for the nop
 */
void emitEndBranchTarget(DList instList, int endLabelIndex) {
	char* inst = nssave(2,SymGetFieldByIndex(globalSymtab,endLabelIndex,SYM_NAME_FIELD),":\t nop");
	dlinkAppend(instList, dlinkNodeAlloc(inst));
}

/**
 * Insert a branch to an ending label after the else-part of an if-statement.
 *
 * @param instList a list of instructions
 * @param elseLabelIndex the symbol table index of the label for the beginning of the else-part of an if-statement
 * @return a symbol table index for the end label of an if-statement
 */
int emitThenBranch(DList instList, int elseLabelIndex) {
	char label[20];
	makeLabel(label);
	char* inst = nssave(2,"\tjmp ",label);
	dlinkAppend(instList, dlinkNodeAlloc(inst));
	emitEndBranchTarget(instList, elseLabelIndex);
	return SymIndex(globalSymtab, label);
}
/**
 * Insert a labeled nop to serve as a target of the backwards branch of a while-statement
 *
 * @param instList a list of instructions
 * @return the label for the backwards branch target
 */
int emitWhileLoopLandingPad(DList instList) {
	char label[20];
	makeLabel(label);

	char *inst = nssave(2,label,":\tnop");

	dlinkAppend(instList,dlinkNodeAlloc(inst));

	return SymIndex(globalSymtab,label);
}

/**
 * Insert a test to enter a while loop. If the test is false, branch to a label after the loop.
 *
 * @param instList a list of instructions
 * @param regIndex the index for the register holding the result of the test expression of a while-statement
 * @return a symbol table index for the label at the end of the while-loop
 */
int emitWhileLoopTest(DList instList, int regIndex) {
	char label[20];
	makeLabel(label);

	int treg = allocateIntegerRegister();
	char *symReg = getIntegerRegisterName(treg);

	char* inst = nssave(2,"\tmovl $-1, ", symReg);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = nssave(4,"\ttestl ", getIntegerRegisterName(regIndex), ", ",symReg);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	freeIntegerRegister(regIndex);
	freeIntegerRegister(treg);

	inst = nssave(2,"\tje ",label);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	return SymIndex(globalSymtab,label);
}

/**
 * Insert a branch back to the the landing pad of a while loop, followed by a branch target for loop exit.
 *
 * @param instList a list of instructions
 * @param beginLabelIndex a symbol table index of the label for the while loop landing pad
 * @param endLabelIndex a symbol table index of the label for the exit of the while loop
 */
void emitWhileLoopBackBranch(DList instList, int beginLabelIndex, int endLabelIndex) {
	char *inst = nssave(2,"\tjmp ",(char*)SymGetFieldByIndex(globalSymtab,beginLabelIndex,SYM_NAME_FIELD));
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	inst = nssave(2,(char*)SymGetFieldByIndex(globalSymtab,endLabelIndex,SYM_NAME_FIELD),":\t nop");
	dlinkAppend(instList,dlinkNodeAlloc(inst));
}

/**
 * Emit call thing
 * 
 * @param function_name the name of the function we are calling
*/
int emitCall(DList instList, char *function_name){

	char *inst;
	int *toSave = getCallerSavedRegisters();
	int savedRegs = 0;

	for(int i = 0; i < 5; i++){
		if(isAllocatedIntegerRegister(toSave[i])){
			inst = nssave(2, "\tpush ", get64bitIntegerRegisterName(toSave[i]));
			dlinkAppend(instList,dlinkNodeAlloc(inst));
			savedRegs++;
		}
	}

	if(savedRegs%2){
		inst = ssave("\tsubq $8, %rsp");
		dlinkAppend(instList,dlinkNodeAlloc(inst));
	}

	inst = nssave(2, "\tcall ", function_name);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	if(savedRegs%2){
		inst = ssave("\taddq $8, %rsp");
		dlinkAppend(instList,dlinkNodeAlloc(inst));
	}

	for(int i = 4; i >= 0; i--){
		if(isAllocatedIntegerRegister(toSave[i])){
			inst = nssave(2, "\tpop ", get64bitIntegerRegisterName(toSave[i]));
			dlinkAppend(instList,dlinkNodeAlloc(inst));
		}
	}

	int treg = allocateIntegerRegister();
	inst = nssave(2, "\tmovl %eax, ", getIntegerRegisterName(treg));
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	return treg;

}

void emitCallNoReturn(DList instList, char *function_name){

	char *inst;
	int *toSave = getCalleeSavedRegisters();
	int savedRegs = 0;

	for(int i = 0; i < 5; i++){
		if(isAllocatedIntegerRegister(toSave[i])){
			inst = nssave(2, "\tpush ", get64bitIntegerRegisterName(toSave[i]));
			dlinkAppend(instList,dlinkNodeAlloc(inst));
			savedRegs++;
		}
	}

	if(savedRegs%2){
		inst = ssave("\tsubq $8, %rsp");
		dlinkAppend(instList,dlinkNodeAlloc(inst));
	}

	inst = nssave(2, "\tcall ", function_name);
	dlinkAppend(instList,dlinkNodeAlloc(inst));

	if(savedRegs%2){
		inst = ssave("\taddq $8, %rsp");
		dlinkAppend(instList,dlinkNodeAlloc(inst));
	}

	for(int i = 4; i >= 0; i--){
		if(isAllocatedIntegerRegister(toSave[i])){
			inst = nssave(2, "\tpop ", get64bitIntegerRegisterName(toSave[i]));
			dlinkAppend(instList,dlinkNodeAlloc(inst));
		}
	}

}
