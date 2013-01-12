
ex3.67.o:     file format pe-i386


Disassembly of section .text:

00000000 <_proc>:
   0:	55                   	push   %ebp
   1:	89 e5                	mov    %esp,%ebp
   3:	8b 4d 08             	mov    0x8(%ebp),%ecx
   6:	8b 51 04             	mov    0x4(%ecx),%edx
   9:	8b 02                	mov    (%edx),%eax
   b:	8b 00                	mov    (%eax),%eax
   d:	2b 01                	sub    (%ecx),%eax
   f:	89 42 04             	mov    %eax,0x4(%edx)
  12:	5d                   	pop    %ebp
  13:	c3                   	ret    
  14:	90                   	nop
  15:	90                   	nop
  16:	90                   	nop
  17:	90                   	nop
  18:	90                   	nop
  19:	90                   	nop
  1a:	90                   	nop
  1b:	90                   	nop
  1c:	90                   	nop
  1d:	90                   	nop
  1e:	90                   	nop
  1f:	90                   	nop
