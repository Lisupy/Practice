
ex3.10.o:     file format pe-i386


Disassembly of section .text:

00000000 <_set_int_zero1>:
   0:	55                   	push   %ebp
   1:	89 e5                	mov    %esp,%ebp
   3:	8b 45 08             	mov    0x8(%ebp),%eax
   6:	b8 00 00 00 00       	mov    $0x0,%eax
   b:	5d                   	pop    %ebp
   c:	c3                   	ret    

0000000d <_set_int_zero2>:
   d:	55                   	push   %ebp
   e:	89 e5                	mov    %esp,%ebp
  10:	8b 45 08             	mov    0x8(%ebp),%eax
  13:	31 c0                	xor    %eax,%eax
  15:	5d                   	pop    %ebp
  16:	c3                   	ret    
  17:	90                   	nop
