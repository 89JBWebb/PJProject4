	.section	.rodata
	.comm _gp, 8, 4
	.string_const0: .string "%d\n"
	.text
	.globl t
	.type t,@function
t:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $44, %rsp
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
	movq %rbp, %rsp
	popq %rbp
	ret
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl $1, %r8d
	movl %r8d, (%rcx)
	leaq _gp(%rip), %r8
	addq $8, %r8
	push %rbx
	push %rcx
	push %r8
	call t
	pop %r8
	pop %rcx
	pop %rbx
	movl %eax, %r9d
	movl %r9d, (%r8)
	leaq _gp(%rip), %r9
	addq $4, %r9
	movl (%r9), %r10d
	leaq _gp(%rip), %r11
	addq $8, %r11
	movl (%r11), %r12d
	addl %r12d, %r10d
	leaq .string_const0(%rip), %rdi
	movl %r10d, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret
