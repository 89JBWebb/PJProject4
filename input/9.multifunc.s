	.section	.rodata
	.string_const0: .string "%d\n"
	.text
	.globl b1
	.type b1,@function
b1:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $0, %rsp
	movl $1, %ebx
	leaq .string_const0(%rip), %rdi
	movl %ebx, %esi
	movl $0, %eax
	call printf@PLT
	movl $1, %ebx
	movl %ebx, %eax
	movq %rbp, %rsp
	popq %rbp
	ret
	.globl b2
	.type b2,@function
b2:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $0, %rsp
	movl $2, %ebx
	leaq .string_const0(%rip), %rdi
	movl %ebx, %esi
	movl $0, %eax
	call printf@PLT
	call b1
	movl %eax, %ebx
	movl %ebx, %eax
	movq %rbp, %rsp
	popq %rbp
	ret
	.globl b3
	.type b3,@function
b3:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $0, %rsp
	movl $3, %ebx
	leaq .string_const0(%rip), %rdi
	movl %ebx, %esi
	movl $0, %eax
	call printf@PLT
	call b1
	movl %eax, %ebx
	push %rbx
	call b2
	pop %rbx
	movl %eax, %ecx
	addl %ecx, %ebx
	movl %ebx, %eax
	movq %rbp, %rsp
	popq %rbp
	ret
	.globl b4
	.type b4,@function
b4:	nop
	pushq %rbp
	movq %rsp, %rbp
	subq $0, %rsp
	movl $4, %ebx
	leaq .string_const0(%rip), %rdi
	movl %ebx, %esi
	movl $0, %eax
	call printf@PLT
	call b1
	movl %eax, %ebx
	push %rbx
	call b2
	pop %rbx
	movl %eax, %ecx
	addl %ecx, %ebx
	push %rbx
	call b3
	pop %rbx
	movl %eax, %ecx
	addl %ecx, %ebx
	movl %ebx, %eax
	movq %rbp, %rsp
	popq %rbp
	ret
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	call b1
	movl %eax, %ebx
	push %rbx
	call b2
	pop %rbx
	movl %eax, %ecx
	addl %ecx, %ebx
	push %rbx
	call b3
	pop %rbx
	movl %eax, %ecx
	addl %ecx, %ebx
	push %rbx
	call b4
	pop %rbx
	movl %eax, %ecx
	addl %ecx, %ebx
	leaq .string_const0(%rip), %rdi
	movl %ebx, %esi
	movl $0, %eax
	call printf@PLT
	leave
	ret
