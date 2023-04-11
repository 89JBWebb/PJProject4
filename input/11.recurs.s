	.section	.rodata
	.comm _gp, 4, 4
	.string_const0: .string "%d\n"
	.string_const1: .string "%s"
	.string_const2: .string "Enter a:"
	.string_const3: .string "%d"
	.text
	.globl decls
	.type decls,@function
decls:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $0, %rsp
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	leaq .string_const0(%rip), %rdi
	movl %ecx, %esi
	movl $0, %eax
	call printf@PLT
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	movl $0, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovg %ebx, %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L0
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	leaq _gp(%rip), %rcx
	addq $4, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	subl %ecx, %r8d
	movl %r8d, (%rbx)
	call decls
	movl %eax, %ebx
	movl %ebx, %eax
	movq %rbp, %rsp
	popq %rbp
	ret
	jmp .L1
.L0:	 nop
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl $0, %ecx
	movl %ecx, (%rbx)
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	movl %ecx, %eax
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
	leaq .string_const1(%rip), %rdi
	leaq .string_const2(%rip), %rsi
	call printf@PLT
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	leaq .string_const3(%rip), %rdi
	movq %rbx, %rsi
	movl $0, %eax
	call scanf@PLT
	call decls
	movl %eax, %ebx
	leaq .string_const0(%rip), %rdi
	movl %ebx, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret
