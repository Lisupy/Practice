	.file	"store_prod.c"
	.text
	.p2align 4,,15
.globl _store_prod
	.def	_store_prod;	.scl	2;	.type	32;	.endef
_store_prod:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %eax
	movl	20(%ebp), %ecx
	imull	%eax, %ecx
	mull	16(%ebp)
	leal	(%ecx,%edx), %edx
	movl	8(%ebp), %ecx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	popl	%ebp
	ret
