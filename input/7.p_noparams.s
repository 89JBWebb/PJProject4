	.section	.rodata
	.comm _gp, 16, 4
	.string_const0: .string "%d\n"
	.text
	.globl a1
	.type a1,@function
a1:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $0, %rsp
	movl $1, %ebx
	leaq .string_const0(%rip), %rdi
	movl %ebx, %esi
	movl $0, %eax
	call printf@PLT
	movl $0, %ebx
	movl %ebx, %eax
	movq %rbp, %rsp
	popq %rbp
	ret
	.globl a2
	.type a2,@function
a2:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $0, %rsp
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	push %rbx
	call a1
	pop %rbx
	movl %eax, %ecx
	movl %ecx, (%rbx)
	movl $2, %ebx
	leaq .string_const0(%rip), %rdi
	movl %ebx, %esi
	movl $0, %eax
	call printf@PLT
	movl $0, %ebx
	movl %ebx, %eax
	movq %rbp, %rsp
	popq %rbp
	ret
	.globl a3
	.type a3,@function
a3:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $0, %rsp
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	push %rbx
	call a1
	pop %rbx
	movl %eax, %ecx
	movl %ecx, (%rbx)
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	push %rbx
	call a2
	pop %rbx
	movl %eax, %ecx
	movl %ecx, (%rbx)
	movl $3, %ebx
	leaq .string_const0(%rip), %rdi
	movl %ebx, %esi
	movl $0, %eax
	call printf@PLT
	movl $0, %ebx
	movl %ebx, %eax
	movq %rbp, %rsp
	popq %rbp
	ret
	.globl a4
	.type a4,@function
a4:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $0, %rsp
	leaq _gp(%rip), %rbx
	addq $4, %rbx
	push %rbx
	call a1
	pop %rbx
	movl %eax, %ecx
	movl %ecx, (%rbx)
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	push %rbx
	call a2
	pop %rbx
	movl %eax, %ecx
	movl %ecx, (%rbx)
	leaq _gp(%rip), %rbx
	addq $12, %rbx
	push %rbx
	call a3
	pop %rbx
	movl %eax, %ecx
	movl %ecx, (%rbx)
	movl $4, %ebx
	leaq .string_const0(%rip), %rdi
	movl %ebx, %esi
	movl $0, %eax
	call printf@PLT
	movl $0, %ebx
	movl %ebx, %eax
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
	push %rbx
	call a1
	pop %rbx
	movl %eax, %ecx
	movl %ecx, (%rbx)
	leaq _gp(%rip), %rbx
	addq $8, %rbx
	push %rbx
	call a2
	pop %rbx
	movl %eax, %ecx
	movl %ecx, (%rbx)
	leaq _gp(%rip), %rbx
	addq $12, %rbx
	push %rbx
	call a3
	pop %rbx
	movl %eax, %ecx
	movl %ecx, (%rbx)
	leaq _gp(%rip), %rbx
	addq $16, %rbx
	push %rbx
	call a4
	pop %rbx
	movl %eax, %ecx
	movl %ecx, (%rbx)
	leave
	ret
