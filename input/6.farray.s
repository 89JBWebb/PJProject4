	.section	.rodata
	.comm _gp, 44, 4
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
	movq %rbp, %rbx
	subq $4, %rbx
	movl $2, %ecx
	movl %ecx, (%rbx)
j0: nop
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %ecx
	movl $11, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovle %ebx, %ecx
	cmpl $1, %ecx
	jne j1
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %ecx
	movq %rbp, %r8
	subq $48, %r8
	subq $2, %rcx
	imulq $4, %rcx
	addq %rcx, %r8
	movq %rbp, %rcx
	subq $4, %rcx
	movl (%rcx), %r9d
	movl $1, %ecx
	subl %ecx, %r9d
	leaq _gp(%rip), %r10
	addq $44, %r10
	subq $1, %r9
	imulq $4, %r9
	addq %r9, %r10
	movl (%r10), %r9d
	movl %r9d, (%r8)
	movq %rbp, %r8
	subq $4, %r8
	movq %rbp, %r9
	subq $4, %r9
	movl (%r9), %r10d
	movl $1, %r9d
	addl %r9d, %r10d
	movl %r10d, (%r8)
	jmp j0
j1: nop
	movl $5, %r8d
	movq %rbp, %r10
	subq $48, %r10
	subq $2, %r8
	imulq $4, %r8
	addq %r8, %r10
	movl (%r10), %r8d
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
j2: nop
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	movl $10, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovle %ebx, %ecx
	cmpl $1, %ecx
	jne j3
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	leaq _gp(%rip), %r8
	addq $44, %r8
	subq $1, %rcx
	imulq $4, %rcx
	addq %rcx, %r8
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl (%rcx), %r9d
	movl %r9d, (%r8)
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	leaq _gp(%rip), %r8
	addq $4, %r8
	movl (%r8), %r9d
	movl $1, %r8d
	addl %r8d, %r9d
	movl %r9d, (%rcx)
	jmp j2
j3: nop
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	push %rbx
	subq $8, %rsp
	call t
	addq $8, %rsp
	pop %rbx
	movl %eax, %r8d
	movl %r8d, (%rcx)
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl (%rcx), %r8d
	leaq .string_const0(%rip), %rdi
	movl %r8d, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret
