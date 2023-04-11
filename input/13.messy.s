	.section	.rodata
	.comm _gp, 44, 4
	.string_const0: .string "%d\n"
	.text
	.globl f1
	.type f1,@function
f1:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $4, %rsp
	movq %rbp, %rbx
	subq $4, %rbx
	movl $10, %ecx
	movl %ecx, (%rbx)
.L0:	nop
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %ecx
	movl $0, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovg %ebx, %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L1
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %ecx
	leaq _gp(%rip), %r8
	addq $44, %r8
	subq $1, %rcx
	imulq $4, %rcx
	addq %rcx, %r8
	movq %rbp, %rcx
	subq $4, %rcx
	movl (%rcx), %r9d
	leaq _gp(%rip), %r10
	addq $44, %r10
	subq $1, %r9
	imulq $4, %r9
	addq %r9, %r10
	movl (%r10), %r9d
	movl $1, %r10d
	subl %r10d, %r9d
	movl %r9d, (%r8)
	movq %rbp, %r8
	subq $4, %r8
	movq %rbp, %r9
	subq $4, %r9
	movl (%r9), %r10d
	movl $1, %r9d
	subl %r9d, %r10d
	movl %r10d, (%r8)
	jmp .L0
.L1:	 nop
	movl $5, %r8d
	leaq _gp(%rip), %r10
	addq $44, %r10
	subq $1, %r8
	imulq $4, %r8
	addq %r8, %r10
	movl (%r10), %r8d
	movl %r8d, %eax
	movq %rbp, %rsp
	popq %rbp
	ret
	.globl f2
	.type f2,@function
f2:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $44, %rsp
	movq %rbp, %rbx
	subq $4, %rbx
	movl $2, %ecx
	movl %ecx, (%rbx)
.L2:	nop
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %ecx
	movl $11, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovle %ebx, %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L3
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %ecx
	movl $5, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovl %ebx, %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L4
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %ecx
	movq %rbp, %r8
	subq $44, %r8
	subq $0, %rcx
	imulq $4, %rcx
	addq %rcx, %r8
	movl $0, %ecx
	movl %ecx, (%r8)
	jmp .L5
.L4:	 nop
	movq %rbp, %rcx
	subq $4, %rcx
	movl (%rcx), %r8d
	movq %rbp, %r9
	subq $44, %r9
	subq $0, %r8
	imulq $4, %r8
	addq %r8, %r9
	movl $1, %r8d
	movl %r8d, (%r9)
.L5:	 nop
	movq %rbp, %r8
	subq $4, %r8
	movq %rbp, %r9
	subq $4, %r9
	movl (%r9), %r10d
	movl $1, %r9d
	addl %r9d, %r10d
	movl %r10d, (%r8)
	jmp .L2
.L3:	 nop
	movl $10, %r8d
	movq %rbp, %r10
	subq $44, %r10
	subq $0, %r8
	imulq $4, %r8
	addq %r8, %r10
	movl (%r10), %r8d
	movl %r8d, %eax
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
.L6:	nop
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	movl $10, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovle %ebx, %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L7
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
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl (%rcx), %r10d
	imull %r10d, %r9d
	movl %r9d, (%r8)
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	leaq _gp(%rip), %r8
	addq $4, %r8
	movl (%r8), %r9d
	movl $1, %r8d
	addl %r8d, %r9d
	movl %r9d, (%rcx)
	jmp .L6
.L7:	 nop
	push %rbx
	call f1
	pop %rbx
	movl %eax, %ecx
	leaq .string_const0(%rip), %rdi
	movl %ecx, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl (%rcx), %r8d
	leaq .string_const0(%rip), %rdi
	movl %r8d, %esi
	movl $0, %eax
	call printf@PLT
	push %rbx
	call f2
	pop %rbx
	movl %eax, %ecx
	leaq .string_const0(%rip), %rdi
	movl %ecx, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl (%rcx), %r8d
	leaq .string_const0(%rip), %rdi
	movl %r8d, %esi
	movl $0, %eax
	call printf@PLT
	movl $10, %ecx
	leaq _gp(%rip), %r9
	addq $44, %r9
	subq $1, %rcx
	imulq $4, %rcx
	addq %rcx, %r9
	movl (%r9), %ecx
	leaq .string_const0(%rip), %rdi
	movl %ecx, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret
