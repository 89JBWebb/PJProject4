	.section	.rodata
	.comm _gp, 8, 4
	.string_const0: .string "%s"
	.string_const1: .string "#iterations = "
	.string_const2: .string "%d"
	.string_const3: .string "%d\n"
	.text
	.globl runsums
	.type runsums,@function
runsums:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	subq $8, %rsp
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl $0, %ecx
	movl %ecx, (%rbx)
	movl $0, %eax
	leaq .string_const0(%rip), %rdi
	leaq .string_const1(%rip), %rsi
	call printf@PLT
	movq %rbp, %rbx
	subq $4, %rbx
	leaq .string_const2(%rip), %rdi
	movq %rbx, %rsi
	movl $0, %eax
	push %rbx
	subq $8, %rsp
	call scanf@PLT
	addq $8, %rsp
	pop %rbx
j0: nop
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl (%rbx), %ecx
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %r8d
	cmpl %r8d, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovl %ebx, %ecx
	cmpl $1, %ecx
	jne j1
	call sumI
	movl %eax, %ebx
	leaq .string_const3(%rip), %rdi
	movl %ebx, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	leaq _gp(%rip), %rcx
	addq $0, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
	jmp j0
j1: nop
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl (%rbx), %ecx
	movl %ecx, %eax
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
	call runsums
	movl %eax, %ebx
	leaq .string_const3(%rip), %rdi
	movl %ebx, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret
