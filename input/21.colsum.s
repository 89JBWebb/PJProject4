	.section	.rodata
	.comm _gp, 800, 4
	.string_const0: .string "%d"
	.string_const1: .string "%s"
	.string_const2: .string "  "
	.string_const3: .string "%s\n"
	.string_const4: .string "*"
	.string_const5: .string "column sum:"
	.string_const6: .string "%d\n"
	.text
	.globl initialize
	.type initialize,@function
initialize:	nop
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
j0: nop
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %ecx
	movl $10, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovle %ebx, %ecx
	cmpl $1, %ecx
	jne j1
	movq %rbp, %rbx
	subq $8, %rbx
	movl $1, %ecx
	movl %ecx, (%rbx)
j2: nop
	movq %rbp, %rbx
	subq $8, %rbx
	movl (%rbx), %ecx
	movl $20, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovle %ebx, %ecx
	cmpl $1, %ecx
	jne j3
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %ecx
	movq %rbp, %rbx
	subq $8, %rbx
	movl (%rbx), %r8d
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movslq %ecx, %rcx
	subq $1, %rcx
	movq $20, %r9
	imulq %r9, %rcx
	movslq %r8d, %r8
	addq %r8, %rcx
	subq $1, %rcx
	imulq $4, %rcx
	addq %rcx, %rbx
	movq %rbp, %rcx
	subq $4, %rcx
	movl (%rcx), %r8d
	movl $20, %ecx
	imull %ecx, %r8d
	movq %rbp, %rcx
	subq $8, %rcx
	movl (%rcx), %r9d
	addl %r9d, %r8d
	movl %r8d, (%rbx)
	movq %rbp, %rbx
	subq $4, %rbx
	movl (%rbx), %ecx
	movq %rbp, %rbx
	subq $8, %rbx
	movl (%rbx), %r8d
	leaq _gp(%rip), %rbx
	addq $0, %rbx
	movslq %ecx, %rcx
	subq $1, %rcx
	movq $20, %r9
	imulq %r9, %rcx
	movslq %r8d, %r8
	addq %r8, %rcx
	subq $1, %rcx
	imulq $4, %rcx
	addq %rcx, %rbx
	movl (%rbx), %ecx
	leaq .string_const0(%rip), %rdi
	movl %ecx, %esi
	movl $0, %eax
	call printf@PLT
	movl $0, %eax
	leaq .string_const1(%rip), %rdi
	leaq .string_const2(%rip), %rsi
	call printf@PLT
	movq %rbp, %rbx
	subq $8, %rbx
	movq %rbp, %rcx
	subq $8, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
	jmp j2
j3: nop
	movl $0, %eax
	leaq .string_const3(%rip), %rdi
	leaq .string_const4(%rip), %rsi
	call printf@PLT
	movq %rbp, %rbx
	subq $4, %rbx
	movq %rbp, %rcx
	subq $4, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
	jmp j0
j1: nop
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
	.globl colsum
	.type colsum,@function
colsum:	nop
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
	leaq .string_const3(%rip), %rdi
	leaq .string_const5(%rip), %rsi
	call printf@PLT
	movq %rbp, %rbx
	subq $8, %rbx
	movl $1, %ecx
	movl %ecx, (%rbx)
j4: nop
	movq %rbp, %rbx
	subq $8, %rbx
	movl (%rbx), %ecx
	movl $20, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovle %ebx, %ecx
	cmpl $1, %ecx
	jne j5
	movq %rbp, %rbx
	subq $4, %rbx
	movl $1, %ecx
	movl %ecx, (%rbx)
	movq %rbp, %rbx
	subq $12, %rbx
	movl $0, %ecx
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
	subq $12, %rbx
	movq %rbp, %rcx
	subq $12, %rcx
	movl (%rcx), %r8d
	movq %rbp, %rcx
	subq $4, %rcx
	movl (%rcx), %r9d
	movq %rbp, %rcx
	subq $8, %rcx
	movl (%rcx), %r10d
	leaq _gp(%rip), %rcx
	addq $0, %rcx
	movslq %r9d, %r9
	subq $1, %r9
	movq $20, %r11
	imulq %r11, %r9
	movslq %r10d, %r10
	addq %r10, %r9
	subq $1, %r9
	imulq $4, %r9
	addq %r9, %rcx
	movl (%rcx), %r9d
	addl %r9d, %r8d
	movl %r8d, (%rbx)
	movq %rbp, %rbx
	subq $4, %rbx
	movq %rbp, %rcx
	subq $4, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
	jmp j6
j7: nop
	movq %rbp, %rbx
	subq $12, %rbx
	movl (%rbx), %ecx
	leaq .string_const0(%rip), %rdi
	movl %ecx, %esi
	movl $0, %eax
	call printf@PLT
	movl $0, %eax
	leaq .string_const1(%rip), %rdi
	leaq .string_const2(%rip), %rsi
	call printf@PLT
	movq %rbp, %rbx
	subq $8, %rbx
	movq %rbp, %rcx
	subq $8, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
	jmp j4
j5: nop
	movl $0, %eax
	leaq .string_const3(%rip), %rdi
	leaq .string_const4(%rip), %rsi
	call printf@PLT
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
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	call initialize
	movl %eax, %ebx
	movl $1, %ecx
	cmpl %ecx, %ebx
	movl $0, %ebx
	movl $1, %ecx
	cmove %ecx, %ebx
	cmpl $1, %ebx
	jne j8
	call colsum
	movl %eax, %ebx
	leaq .string_const6(%rip), %rdi
	movl %ebx, %esi
	movl $0, %eax
	call printf@PLT
	jmp j9
j8: nop
j9: nop
	leave
	ret
