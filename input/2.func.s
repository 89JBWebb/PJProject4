	.section	.rodata
	.string_const0: .string "%s\n"
	.string_const1: .string "inside function"
	.string_const2: .string "%d\n"
	.text
	.globl t
	.type t,@function
t:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $4, %rsp
	movl $0, %eax
	leaq .string_const0(%rip), %rdi
	leaq .string_const1(%rip), %rsi
	call printf@PLT
	movq %rbp, %rbx
	subq $4, %rbx
	movl $10, %ecx
	movl %ecx, (%rbx)
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %ecx
	movl $5, %ebx
	addl %ebx, %ecx
	movl %ecx, %eax
	movq %rbp, %rsp
	popq %rbp
	ret
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $4, %rsp
	movq %rbp, %rbx
	subq $4, %rbx
	push %rbx
	call t
	pop %rbx
	movl %eax, %ecx
	movl %ecx, (%rbx)
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %ecx
	leaq .string_const2(%rip), %rdi
	movl %ecx, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret
