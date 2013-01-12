	.file	"ex3.10.c"
	.text
.globl _set_int_zero1
	.def	_set_int_zero1;	.scl	2;	.type	32;	.endef
_set_int_zero1:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	$0, %eax
	popl	%ebp
	ret
.globl _set_int_zero2
	.def	_set_int_zero2;	.scl	2;	.type	32;	.endef
_set_int_zero2:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	xor     %eax, %eax
	popl	%ebp
	ret
