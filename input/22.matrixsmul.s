	.section	.rodata
	.comm _gp, 1760, 4
	.string_const0: .string "%d"
	.string_const1: .string "%s"
	.string_const2: .string "  "
	.string_const3: .string "%s\n"
	.string_const4: .string "*"
	.string_const5: .string "input a factor (2-10):"
	.string_const6: .string "* "
	.string_const7: .string "="
	.string_const8: .string "%d\n"
	.text
	.globl init
	.type init,@function
init:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $896, %rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	subq $8, %rsp
	movq %rbp, %rbx
	subq $884, %rbx
	movl $1, %ecx
	movl %ecx, (%rbx)
j0: nop
	movq %rbp, %rbx
	subq $884, %rbx
	movl (%rbx), %ecx
	movl $20, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovle %ebx, %ecx
	cmpl $1, %ecx
	jne j1
	movq %rbp, %rbx
	subq $888, %rbx
	movl $1, %ecx
	movl %ecx, (%rbx)
j2: nop
	movq %rbp, %rbx
	subq $888, %rbx
	movl (%rbx), %ecx
	movl $11, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovle %ebx, %ecx
	cmpl $1, %ecx
	jne j3
	movq %rbp, %rbx
	subq $884, %rbx
	movl (%rbx), %ecx
	movq %rbp, %rbx
	subq $888, %rbx
	movl (%rbx), %r8d
	movq %rbp, %rbx
	subq $880, %rbx
	movslq %ecx, %rcx
	subq $1, %rcx
	movq $11, %r9
	imulq %r9, %rcx
	movslq %r8d, %r8
	addq %r8, %rcx
	subq $1, %rcx
	imulq $4, %rcx
	addq %rcx, %rbx
	movq %rbp, %rcx
	subq $884, %rcx
	movl (%rcx), %r8d
	movl $11, %ecx
	imull %ecx, %r8d
	movq %rbp, %rcx
	subq $888, %rcx
	movl (%rcx), %r9d
	addl %r9d, %r8d
	movl %r8d, (%rbx)
	movq %rbp, %rbx
	subq $884, %rbx
	movl (%rbx), %ecx
	movq %rbp, %rbx
	subq $888, %rbx
	movl (%rbx), %r8d
	movq %rbp, %rbx
	subq $880, %rbx
	movslq %ecx, %rcx
	subq $1, %rcx
	movq $11, %r9
	imulq %r9, %rcx
	movslq %r8d, %r8
	addq %r8, %rcx
	subq $1, %rcx
	imulq $4, %rcx
	addq %rcx, %rbx
	movl (%rbx), %ecx
	leaq .string_const0(%rip), %rdi
	movl %ecx, %esi
	movl $0, %eax
	call printf@PLT
	movl $0, %eax
	leaq .string_const1(%rip), %rdi
	leaq .string_const2(%rip), %rsi
	call printf@PLT
	movq %rbp, %rbx
	subq $888, %rbx
	movq %rbp, %rcx
	subq $888, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
	jmp j2
j3: nop
	movl $0, %eax
	leaq .string_const3(%rip), %rdi
	leaq .string_const4(%rip), %rsi
	call printf@PLT
	movq %rbp, %rbx
	subq $884, %rbx
	movq %rbp, %rcx
	subq $884, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
	jmp j0
j1: nop
	movl $1, %ebx
	movl %ebx, %eax
	addq $8, %rsp
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
	movq %rbp, %rsp
	popq %rbp
	ret
	.globl compute
	.type compute,@function
compute:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $1776, %rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	subq $8, %rsp
	call init
	movl %eax, %ebx
	movl $1, %ecx
	cmpl %ecx, %ebx
	movl $0, %ebx
	movl $1, %ecx
	cmove %ecx, %ebx
	cmpl $1, %ebx
	jne j4
	movl $0, %eax
	leaq .string_const1(%rip), %rdi
	leaq .string_const5(%rip), %rsi
	call printf@PLT
	movq %rbp, %rbx
	subq $1772, %rbx
	leaq .string_const0(%rip), %rdi
	movq %rbx, %rsi
	movl $0, %eax
	push %rbx
	subq $8, %rsp
	call scanf@PLT
	addq $8, %rsp
	pop %rbx
	movq %rbp, %rbx
	subq $1764, %rbx
	movl $1, %ecx
	movl %ecx, (%rbx)
j5: nop
	movq %rbp, %rbx
	subq $1764, %rbx
	movl (%rbx), %ecx
	movl $20, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovle %ebx, %ecx
	cmpl $1, %ecx
	jne j6
	movq %rbp, %rbx
	subq $1768, %rbx
	movl $1, %ecx
	movl %ecx, (%rbx)
j7: nop
	movq %rbp, %rbx
	subq $1768, %rbx
	movl (%rbx), %ecx
	movl $11, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovle %ebx, %ecx
	cmpl $1, %ecx
	jne j8
	movq %rbp, %rbx
	subq $1764, %rbx
	movl (%rbx), %ecx
	movq %rbp, %rbx
	subq $1768, %rbx
	movl (%rbx), %r8d
	movq %rbp, %rbx
	subq $880, %rbx
	movslq %ecx, %rcx
	subq $1, %rcx
	movq $11, %r9
	imulq %r9, %rcx
	movslq %r8d, %r8
	addq %r8, %rcx
	subq $1, %rcx
	imulq $4, %rcx
	addq %rcx, %rbx
	movq %rbp, %rcx
	subq $1764, %rcx
	movl (%rcx), %r8d
	movq %rbp, %rcx
	subq $1768, %rcx
	movl (%rcx), %r9d
	addl %r9d, %r8d
	movl %r8d, (%rbx)
	movq %rbp, %rbx
	subq $1764, %rbx
	movl (%rbx), %ecx
	movq %rbp, %rbx
	subq $1768, %rbx
	movl (%rbx), %r8d
	movq %rbp, %rbx
	subq $880, %rbx
	movslq %ecx, %rcx
	subq $1, %rcx
	movq $11, %r9
	imulq %r9, %rcx
	movslq %r8d, %r8
	addq %r8, %rcx
	subq $1, %rcx
	imulq $4, %rcx
	addq %rcx, %rbx
	movl (%rbx), %ecx
	leaq .string_const0(%rip), %rdi
	movl %ecx, %esi
	movl $0, %eax
	call printf@PLT
	movl $0, %eax
	leaq .string_const1(%rip), %rdi
	leaq .string_const2(%rip), %rsi
	call printf@PLT
	movq %rbp, %rbx
	subq $1768, %rbx
	movq %rbp, %rcx
	subq $1768, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
	jmp j7
j8: nop
	movl $0, %eax
	leaq .string_const3(%rip), %rdi
	leaq .string_const4(%rip), %rsi
	call printf@PLT
	movq %rbp, %rbx
	subq $1764, %rbx
	movq %rbp, %rcx
	subq $1764, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
	jmp j5
j6: nop
	movl $0, %eax
	leaq .string_const1(%rip), %rdi
	leaq .string_const6(%rip), %rsi
	call printf@PLT
	movq %rbp, %rbx
	subq $1772, %rbx
	movl (%rbx), %ecx
	leaq .string_const0(%rip), %rdi
	movl %ecx, %esi
	movl $0, %eax
	call printf@PLT
	movl $0, %eax
	leaq .string_const3(%rip), %rdi
	leaq .string_const7(%rip), %rsi
	call printf@PLT
	movq %rbp, %rbx
	subq $1764, %rbx
	movl $1, %ecx
	movl %ecx, (%rbx)
j9: nop
	movq %rbp, %rbx
	subq $1764, %rbx
	movl (%rbx), %ecx
	movl $20, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovle %ebx, %ecx
	cmpl $1, %ecx
	jne j10
	movq %rbp, %rbx
	subq $1768, %rbx
	movl $1, %ecx
	movl %ecx, (%rbx)
j11: nop
	movq %rbp, %rbx
	subq $1768, %rbx
	movl (%rbx), %ecx
	movl $11, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovle %ebx, %ecx
	cmpl $1, %ecx
	jne j12
	movq %rbp, %rbx
	subq $1764, %rbx
	movl (%rbx), %ecx
	movq %rbp, %rbx
	subq $1768, %rbx
	movl (%rbx), %r8d
	movq %rbp, %rbx
	subq $1760, %rbx
	movslq %ecx, %rcx
	subq $1, %rcx
	movq $11, %r9
	imulq %r9, %rcx
	movslq %r8d, %r8
	addq %r8, %rcx
	subq $1, %rcx
	imulq $4, %rcx
	addq %rcx, %rbx
	movq %rbp, %rcx
	subq $1764, %rcx
	movl (%rcx), %r8d
	movq %rbp, %rcx
	subq $1768, %rcx
	movl (%rcx), %r9d
	movq %rbp, %rcx
	subq $880, %rcx
	movslq %r8d, %r8
	subq $1, %r8
	movq $11, %r10
	imulq %r10, %r8
	movslq %r9d, %r9
	addq %r9, %r8
	subq $1, %r8
	imulq $4, %r8
	addq %r8, %rcx
	movl (%rcx), %r8d
	movq %rbp, %rcx
	subq $1772, %rcx
	movl (%rcx), %r9d
	imull %r9d, %r8d
	movl %r8d, (%rbx)
	movq %rbp, %rbx
	subq $1764, %rbx
	movl (%rbx), %ecx
	movq %rbp, %rbx
	subq $1768, %rbx
	movl (%rbx), %r8d
	movq %rbp, %rbx
	subq $1760, %rbx
	movslq %ecx, %rcx
	subq $1, %rcx
	movq $11, %r9
	imulq %r9, %rcx
	movslq %r8d, %r8
	addq %r8, %rcx
	subq $1, %rcx
	imulq $4, %rcx
	addq %rcx, %rbx
	movl (%rbx), %ecx
	leaq .string_const0(%rip), %rdi
	movl %ecx, %esi
	movl $0, %eax
	call printf@PLT
	movl $0, %eax
	leaq .string_const1(%rip), %rdi
	leaq .string_const2(%rip), %rsi
	call printf@PLT
	movq %rbp, %rbx
	subq $1768, %rbx
	movq %rbp, %rcx
	subq $1768, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
	jmp j11
j12: nop
	movl $0, %eax
	leaq .string_const3(%rip), %rdi
	leaq .string_const4(%rip), %rsi
	call printf@PLT
	movq %rbp, %rbx
	subq $1764, %rbx
	movq %rbp, %rcx
	subq $1764, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
	jmp j9
j10: nop
	jmp j13
j4: nop
j13: nop
	movl $1, %ebx
	movl %ebx, %eax
	addq $8, %rsp
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
	movq %rbp, %rsp
	popq %rbp
	ret
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	call compute
	movl %eax, %ebx
	leaq .string_const8(%rip), %rdi
	movl %ebx, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret
