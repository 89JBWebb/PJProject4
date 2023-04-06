	.section	.rodata
	.comm _gp, 4, 4
	.string_const0: .string "%s\n"
	.string_const1: .string "inside function"
	.string_const2: .string "%d\n"
	.text
	.globl t
	.type t,@function
t:	nop
	pushq %rbp
	movq %rsp, %rbp
	movl $0, %eax
	leaq .string_const0(%rip), %rdi
	leaq .string_const1(%rip), %rsi
	call printf@PLT
	movl $10, %ebx
	movl %ebx, %eax
	movq %rbp, %rsp
	popq %rbp
	ret
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	leaq _gp(%rip), %rcx
	push %rbx
	push %rcx
	call t
	pop %rbx
	pop %rcx
	movl %eax, %r8d
	movl %r8d, (%rcx)
	leaq _gp(%rip), %rcx
	movl (%rcx), %r8d
	leaq .string_const2(%rip), %rdi
	movl %r8d, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret
