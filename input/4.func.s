	.section	.rodata
	.string_const0: .string "%d\n"
	.text
	.globl t
	.type t,@function
t:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $4, %rsp
	movq %rbp, %rbx
	movq (%rbx), %rbx
	subq $8, %rbx
	movl $5, %ecx
	movl %ecx, (%rbx)
	movq %rbp, %rbx
	subq $4, %rbx
	movl $2, %ecx
	movl %ecx, (%rbx)
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %ecx
	leaq .string_const0(%rip), %rdi
	movl %ecx, %esi
	movl $0, %eax
	call printf@PLT
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %ecx
	movq %rbp, %rbx
	movq (%rbx), %rbx
	subq $8, %rbx
	movl (%rbx), %r8d
	addl %r8d, %ecx
	movl %ecx, %eax
	movq %rbp, %rsp
	popq %rbp
	ret
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $8, %rsp
	movq %rbp, %rbx
	subq $4, %rbx
	movl $1, %ecx
	movl %ecx, (%rbx)
	movq %rbp, %rbx
	subq $8, %rbx
	push %rbx
	call t
	pop %rbx
	movl %eax, %ecx
	movl %ecx, (%rbx)
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %ecx
	movq %rbp, %rbx
	subq $8, %rbx
	movl (%rbx), %r8d
	addl %r8d, %ecx
	leaq .string_const0(%rip), %rdi
	movl %ecx, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret
