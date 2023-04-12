	.section	.rodata
	.comm _gp, 52, 4
	.string_const0: .string "%d\n"
	.string_const1: .string "%s\n"
	.string_const2: .string "Enter a[1:10]:"
	.string_const3: .string "%d"
	.text
	.globl sort
	.type sort,@function
sort:	nop
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
	addq $44, %rbx
	movl (%rbx), %ecx
	leaq _gp(%rip), %rbx
	addq $48, %rbx
	movl (%rbx), %r8d
	cmpl %r8d, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmove %ebx, %ecx
	cmpl $1, %ecx
	jne j0
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
	jmp j1
j0: nop
	movq %rbp, %rbx
	subq $4, %rbx
	leaq _gp(%rip), %rcx
	addq $44, %rcx
	movl (%rcx), %r8d
	movl %r8d, (%rbx)
	movq %rbp, %rbx
	subq $16, %rbx
	movq %rbp, %rcx
	subq $4, %rcx
	movl (%rcx), %r8d
	movl %r8d, (%rbx)
	movq %rbp, %rbx
	subq $8, %rbx
	leaq _gp(%rip), %rcx
	addq $44, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
j2: nop
	movq %rbp, %rbx
	subq $8, %rbx
	movl (%rbx), %ecx
	leaq _gp(%rip), %rbx
	addq $48, %rbx
	movl (%rbx), %r8d
	cmpl %r8d, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovle %ebx, %ecx
	cmpl $1, %ecx
	jne j3
	movq %rbp, %rbx
	subq $8, %rbx
	movl (%rbx), %ecx
	leaq _gp(%rip), %r8
	addq $0, %r8
	subq $1, %rcx
	imulq $4, %rcx
	addq %rcx, %r8
	movl (%r8), %ecx
	movq %rbp, %r8
	subq $16, %r8
	movl (%r8), %r9d
	leaq _gp(%rip), %r10
	addq $0, %r10
	subq $1, %r9
	imulq $4, %r9
	addq %r9, %r10
	movl (%r10), %r9d
	cmpl %r9d, %ecx
	movl $0, %ecx
	movl $1, %r9d
	cmovl %r9d, %ecx
	cmpl $1, %ecx
	jne j4
	movq %rbp, %rcx
	subq $16, %rcx
	movq %rbp, %r9
	subq $8, %r9
	movl (%r9), %r10d
	movl %r10d, (%rcx)
	jmp j5
j4: nop
j5: nop
	movq %rbp, %rcx
	subq $8, %rcx
	movq %rbp, %r9
	subq $8, %r9
	movl (%r9), %r10d
	movl $1, %r9d
	addl %r9d, %r10d
	movl %r10d, (%rcx)
	jmp j2
j3: nop
	movq %rbp, %rcx
	subq $12, %rcx
	movq %rbp, %r9
	subq $4, %r9
	movl (%r9), %r10d
	leaq _gp(%rip), %r11
	addq $0, %r11
	subq $1, %r10
	imulq $4, %r10
	addq %r10, %r11
	movl (%r11), %r10d
	movl %r10d, (%rcx)
	movq %rbp, %rcx
	subq $4, %rcx
	movl (%rcx), %r10d
	leaq _gp(%rip), %r11
	addq $0, %r11
	subq $1, %r10
	imulq $4, %r10
	addq %r10, %r11
	movq %rbp, %r10
	subq $16, %r10
	movl (%r10), %r12d
	leaq _gp(%rip), %r13
	addq $0, %r13
	subq $1, %r12
	imulq $4, %r12
	addq %r12, %r13
	movl (%r13), %r12d
	movl %r12d, (%r11)
	movq %rbp, %r11
	subq $16, %r11
	movl (%r11), %r12d
	leaq _gp(%rip), %r13
	addq $0, %r13
	subq $1, %r12
	imulq $4, %r12
	addq %r12, %r13
	movq %rbp, %r12
	subq $12, %r12
	movl (%r12), %r14d
	movl %r14d, (%r13)
	leaq _gp(%rip), %r12
	addq $44, %r12
	leaq _gp(%rip), %r13
	addq $44, %r13
	movl (%r13), %r14d
	movl $1, %r13d
	addl %r13d, %r14d
	movl %r14d, (%r12)
	push %rcx
	push %r8
	push %r9
	push %r10
	push %r11
	subq $8, %rsp
	call sort
	addq $8, %rsp
	pop %r11
	pop %r10
	pop %r9
	pop %r8
	pop %rcx
	movl %eax, %r12d
	movl %r12d, %eax
	addq $8, %rsp
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	popq %rbx
	movq %rbp, %rsp
	popq %rbp
	ret
j1: nop
	.globl output
	.type output,@function
output:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	subq $8, %rsp
	movq %rbp, %rbx
	subq $4, %rbx
	movl $1, %ecx
	movl %ecx, (%rbx)
j6: nop
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %ecx
	movl $10, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovle %ebx, %ecx
	cmpl $1, %ecx
	jne j7
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %ecx
	leaq _gp(%rip), %r8
	addq $0, %r8
	subq $1, %rcx
	imulq $4, %rcx
	addq %rcx, %r8
	movl (%r8), %ecx
	leaq .string_const0(%rip), %rdi
	movl %ecx, %esi
	movl $0, %eax
	push %rbx
	subq $8, %rsp
	call printf@PLT
	addq $8, %rsp
	pop %rbx
	movq %rbp, %rcx
	subq $4, %rcx
	movq %rbp, %r8
	subq $4, %r8
	movl (%r8), %r9d
	movl $1, %r8d
	addl %r8d, %r9d
	movl %r9d, (%rcx)
	jmp j6
j7: nop
	movl $1, %ecx
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
	.globl input
	.type input,@function
input:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $16, %rsp
	pushq %rbx
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	subq $8, %rsp
	movl $0, %eax
	leaq .string_const1(%rip), %rdi
	leaq .string_const2(%rip), %rsi
	call printf@PLT
	movq %rbp, %rbx
	subq $4, %rbx
	movl $1, %ecx
	movl %ecx, (%rbx)
j8: nop
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %ecx
	movl $10, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovle %ebx, %ecx
	cmpl $1, %ecx
	jne j9
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %ecx
	leaq _gp(%rip), %r8
	addq $0, %r8
	subq $1, %rcx
	imulq $4, %rcx
	addq %rcx, %r8
	leaq .string_const3(%rip), %rdi
	movq %r8, %rsi
	movl $0, %eax
	push %rbx
	subq $8, %rsp
	call scanf@PLT
	addq $8, %rsp
	pop %rbx
	movq %rbp, %rcx
	subq $4, %rcx
	movq %rbp, %r8
	subq $4, %r8
	movl (%r8), %r9d
	movl $1, %r8d
	addl %r8d, %r9d
	movl %r9d, (%rcx)
	jmp j8
j9: nop
	movl $1, %ecx
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
	leaq _gp(%rip), %rbx
	addq $40, %rbx
	call input
	movl %eax, %ecx
	movl %ecx, (%rbx)
	leaq _gp(%rip), %rbx
	addq $40, %rbx
	call output
	movl %eax, %ecx
	movl %ecx, (%rbx)
	leaq _gp(%rip), %rbx
	addq $44, %rbx
	movl $1, %ecx
	movl %ecx, (%rbx)
	leaq _gp(%rip), %rbx
	addq $48, %rbx
	movl $10, %ecx
	movl %ecx, (%rbx)
	leaq _gp(%rip), %rbx
	addq $40, %rbx
	call sort
	movl %eax, %ecx
	movl %ecx, (%rbx)
	leaq _gp(%rip), %rbx
	addq $40, %rbx
	call output
	movl %eax, %ecx
	movl %ecx, (%rbx)
	leave
	ret
