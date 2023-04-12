	.section	.rodata
	.comm _gp, 4, 4
	.string_const0: .string "%d"
	.string_const1: .string "%s\n"
	.string_const2: .string "Your code should not reach here!"
	.text
	.globl hacked
	.type hacked,@function
hacked:	nop
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
	call foo
	movl %eax, %ecx
	movl %ecx, (%rbx)
	movl $7, %ebx
	movq %rbp, %r8
	subq $16, %r8
	subq $1, %rbx
	imulq $4, %rbx
	addq %rbx, %r8
	leaq .string_const0(%rip), %rdi
	movq %r8, %rsi
	movl $0, %eax
	call scanf@PLT
	movl $8, %ebx
	movq %rbp, %r9
	subq $16, %r9
	subq $1, %rbx
	imulq $4, %rbx
	addq %rbx, %r9
	leaq .string_const0(%rip), %rdi
	movq %r9, %rsi
	movl $0, %eax
	call scanf@PLT
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movl (%rbx), %r9d
	movl %r9d, %eax
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
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	call hacked
	movl %eax, %ecx
	movl %ecx, (%rbx)
	movl $0, %eax
	leaq .string_const1(%rip), %rdi
	leaq .string_const2(%rip), %rsi
	call printf@PLT
	leave
	ret
