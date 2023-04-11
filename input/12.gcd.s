	.section	.rodata
	.comm _gp, 8, 4
	.string_const0: .string "%s"
	.string_const1: .string "x="
	.string_const2: .string "%d"
	.string_const3: .string "y="
	.string_const4: .string "gcd="
	.string_const5: .string "%d\n"
	.text
	.globl gcd
	.type gcd,@function
gcd:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $4, %rsp
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	movl (%rbx), %ecx
	movl $0, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmove %ebx, %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L0
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	movl %ecx, %eax
	movq %rbp, %rsp
	popq %rbp
	ret
	jmp .L1
.L0:	 nop
	movq %rbp, %rbx
	subq $4, %rbx
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl (%rcx), %r8d
	movl %r8d, (%rbx)
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	leaq _gp(%rip), %rcx
	addq $8, %rcx
	movl (%rcx), %r8d
	movl %r8d, (%rbx)
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	movq %rbp, %rcx
	subq $4, %rcx
	movl (%rcx), %r8d
	leaq _gp(%rip), %rcx
	addq $8, %rcx
	movl (%rcx), %r9d
	movq %rbp, %rcx
	subq $4, %rcx
	movl (%rcx), %r10d
	leaq _gp(%rip), %rcx
	addq $8, %rcx
	movl (%rcx), %r11d
	movl %r10d, %eax
	cdq
	idivl %r11d
	movl %eax, %r10d
	imull %r10d, %r9d
	subl %r9d, %r8d
	movl %r8d, (%rbx)
	call gcd
	movl %eax, %ebx
	movl %ebx, %eax
	movq %rbp, %rsp
	popq %rbp
	ret
.L1:	 nop
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	movl $0, %eax
	leaq .string_const0(%rip), %rdi
	leaq .string_const1(%rip), %rsi
	call printf@PLT
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	leaq .string_const2(%rip), %rdi
	movq %rbx, %rsi
	movl $0, %eax
	call scanf@PLT
	movl $0, %eax
	leaq .string_const0(%rip), %rdi
	leaq .string_const3(%rip), %rsi
	call printf@PLT
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	leaq .string_const2(%rip), %rdi
	movq %rbx, %rsi
	movl $0, %eax
	call scanf@PLT
.L2:	nop
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	movl $0, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovne %ebx, %ecx
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	movl (%rbx), %r8d
	movl $0, %ebx
	cmpl %ebx, %r8d
	movl $0, %r8d
	movl $1, %ebx
	cmovne %ebx, %r8d
	orl %r8d, %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L3
	movl $0, %eax
	leaq .string_const0(%rip), %rdi
	leaq .string_const4(%rip), %rsi
	call printf@PLT
	call gcd
	movl %eax, %ebx
	leaq .string_const5(%rip), %rdi
	movl %ebx, %esi
	movl $0, %eax
	call printf@PLT
	movl $0, %eax
	leaq .string_const0(%rip), %rdi
	leaq .string_const1(%rip), %rsi
	call printf@PLT
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	leaq .string_const2(%rip), %rdi
	movq %rbx, %rsi
	movl $0, %eax
	call scanf@PLT
	movl $0, %eax
	leaq .string_const0(%rip), %rdi
	leaq .string_const3(%rip), %rsi
	call printf@PLT
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	leaq .string_const2(%rip), %rdi
	movq %rbx, %rsi
	movl $0, %eax
	call scanf@PLT
	jmp .L2
.L3:	 nop
	leave
	ret
