	.section	.rodata
	.comm _gp, 8, 4
	.string_const0: .string "%d\n"
	.text
	.globl t
	.type t,@function
t:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $48, %rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
subq $8, %rsp
	movl $3, %ebx
	movq %rbp, %r8
	subq $44, %r8
	subq $0, %rbx
	imulq $4, %rbx
	addq %rbx, %r8
	movl $5, %ebx
	movl %ebx, (%r8)
	movq %rbp, %rbx
	subq $4, %rbx
	movl $2, %r8d
	movl %r8d, (%rbx)
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %r8d
	leaq .string_const0(%rip), %rdi
	movl %r8d, %esi
	movl $0, %eax
	call printf@PLT
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %r8d
	movl $3, %ebx
	movq %rbp, %r10
	subq $44, %r10
	subq $0, %rbx
	imulq $4, %rbx
	addq %rbx, %r10
	movl (%r10), %ebx
	addl %ebx, %r8d
	movl %r8d, %eax
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
	addq $4, %rbx
	movl $1, %ecx
	movl %ecx, (%rbx)
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	push %rbx
	subq $8, %rsp
	call t
	addq $8, %rsp
	pop %rbx
	movl %eax, %ecx
	movl %ecx, (%rbx)
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	movl (%rbx), %r8d
	addl %r8d, %ecx
	leaq .string_const0(%rip), %rdi
	movl %ecx, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret
