
./a.exe:     file format pei-i386


Disassembly of section .text:

00401000 <_WinMainCRTStartup>:
  401000:	55                   	push   %ebp
  401001:	89 e5                	mov    %esp,%ebp
  401003:	83 ec 18             	sub    $0x18,%esp
  401006:	83 e4 f0             	and    $0xfffffff0,%esp
  401009:	c7 04 24 e9 11 40 00 	movl   $0x4011e9,(%esp)
  401010:	e8 2b 02 00 00       	call   401240 <_cygwin_crt0>
  401015:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
  40101c:	00 
  40101d:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
  401024:	00 
  401025:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
  40102c:	e8 3f 02 00 00       	call   401270 <_cygwin_premain0>
  401031:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
  401038:	00 
  401039:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
  401040:	00 
  401041:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
  401048:	e8 33 02 00 00       	call   401280 <_cygwin_premain1>
  40104d:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
  401054:	00 
  401055:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
  40105c:	00 
  40105d:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
  401064:	e8 27 02 00 00       	call   401290 <_cygwin_premain2>
  401069:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
  401070:	00 
  401071:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
  401078:	00 
  401079:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
  401080:	e8 1b 02 00 00       	call   4012a0 <_cygwin_premain3>
  401085:	c9                   	leave  
  401086:	c3                   	ret    
  401087:	90                   	nop
  401088:	90                   	nop
  401089:	90                   	nop
  40108a:	90                   	nop
  40108b:	90                   	nop
  40108c:	90                   	nop
  40108d:	90                   	nop
  40108e:	90                   	nop
  40108f:	90                   	nop

00401090 <___gcc_register_frame>:
  401090:	55                   	push   %ebp
  401091:	89 e5                	mov    %esp,%ebp
  401093:	83 ec 18             	sub    $0x18,%esp
  401096:	c7 04 24 20 20 40 00 	movl   $0x402020,(%esp)
  40109d:	e8 f6 06 00 00       	call   401798 <_GetModuleHandleA@4>
  4010a2:	89 c2                	mov    %eax,%edx
  4010a4:	83 ec 04             	sub    $0x4,%esp
  4010a7:	85 d2                	test   %edx,%edx
  4010a9:	b8 00 00 00 00       	mov    $0x0,%eax
  4010ae:	74 13                	je     4010c3 <___gcc_register_frame+0x33>
  4010b0:	c7 44 24 04 2f 20 40 	movl   $0x40202f,0x4(%esp)
  4010b7:	00 
  4010b8:	89 14 24             	mov    %edx,(%esp)
  4010bb:	e8 e0 06 00 00       	call   4017a0 <_GetProcAddress@8>
  4010c0:	83 ec 08             	sub    $0x8,%esp
  4010c3:	85 c0                	test   %eax,%eax
  4010c5:	74 11                	je     4010d8 <___gcc_register_frame+0x48>
  4010c7:	c7 44 24 04 00 40 40 	movl   $0x404000,0x4(%esp)
  4010ce:	00 
  4010cf:	c7 04 24 00 30 40 00 	movl   $0x403000,(%esp)
  4010d6:	ff d0                	call   *%eax
  4010d8:	a1 a0 20 40 00       	mov    0x4020a0,%eax
  4010dd:	85 c0                	test   %eax,%eax
  4010df:	74 3a                	je     40111b <___gcc_register_frame+0x8b>
  4010e1:	c7 04 24 45 20 40 00 	movl   $0x402045,(%esp)
  4010e8:	e8 ab 06 00 00       	call   401798 <_GetModuleHandleA@4>
  4010ed:	89 c2                	mov    %eax,%edx
  4010ef:	83 ec 04             	sub    $0x4,%esp
  4010f2:	85 d2                	test   %edx,%edx
  4010f4:	b8 00 00 00 00       	mov    $0x0,%eax
  4010f9:	74 13                	je     40110e <___gcc_register_frame+0x7e>
  4010fb:	c7 44 24 04 53 20 40 	movl   $0x402053,0x4(%esp)
  401102:	00 
  401103:	89 14 24             	mov    %edx,(%esp)
  401106:	e8 95 06 00 00       	call   4017a0 <_GetProcAddress@8>
  40110b:	83 ec 08             	sub    $0x8,%esp
  40110e:	85 c0                	test   %eax,%eax
  401110:	74 09                	je     40111b <___gcc_register_frame+0x8b>
  401112:	c7 04 24 a0 20 40 00 	movl   $0x4020a0,(%esp)
  401119:	ff d0                	call   *%eax
  40111b:	c9                   	leave  
  40111c:	c3                   	ret    
  40111d:	8d 76 00             	lea    0x0(%esi),%esi

00401120 <___gcc_deregister_frame>:
  401120:	55                   	push   %ebp
  401121:	89 e5                	mov    %esp,%ebp
  401123:	83 ec 18             	sub    $0x18,%esp
  401126:	c7 04 24 20 20 40 00 	movl   $0x402020,(%esp)
  40112d:	e8 66 06 00 00       	call   401798 <_GetModuleHandleA@4>
  401132:	89 c2                	mov    %eax,%edx
  401134:	83 ec 04             	sub    $0x4,%esp
  401137:	85 d2                	test   %edx,%edx
  401139:	b8 00 00 00 00       	mov    $0x0,%eax
  40113e:	74 13                	je     401153 <___gcc_deregister_frame+0x33>
  401140:	c7 44 24 04 67 20 40 	movl   $0x402067,0x4(%esp)
  401147:	00 
  401148:	89 14 24             	mov    %edx,(%esp)
  40114b:	e8 50 06 00 00       	call   4017a0 <_GetProcAddress@8>
  401150:	83 ec 08             	sub    $0x8,%esp
  401153:	85 c0                	test   %eax,%eax
  401155:	74 09                	je     401160 <___gcc_deregister_frame+0x40>
  401157:	c7 04 24 00 30 40 00 	movl   $0x403000,(%esp)
  40115e:	ff d0                	call   *%eax
  401160:	c9                   	leave  
  401161:	c3                   	ret    
  401162:	90                   	nop
  401163:	90                   	nop
  401164:	90                   	nop
  401165:	90                   	nop
  401166:	90                   	nop
  401167:	90                   	nop
  401168:	90                   	nop
  401169:	90                   	nop
  40116a:	90                   	nop
  40116b:	90                   	nop
  40116c:	90                   	nop
  40116d:	90                   	nop
  40116e:	90                   	nop
  40116f:	90                   	nop

00401170 <_float_negate>:
  401170:	55                   	push   %ebp
  401171:	89 e5                	mov    %esp,%ebp
  401173:	83 ec 10             	sub    $0x10,%esp
  401176:	8b 45 08             	mov    0x8(%ebp),%eax
  401179:	c1 e8 1f             	shr    $0x1f,%eax
  40117c:	89 45 fc             	mov    %eax,-0x4(%ebp)
  40117f:	8b 45 08             	mov    0x8(%ebp),%eax
  401182:	c1 e8 17             	shr    $0x17,%eax
  401185:	25 ff 00 00 00       	and    $0xff,%eax
  40118a:	89 45 f8             	mov    %eax,-0x8(%ebp)
  40118d:	8b 45 08             	mov    0x8(%ebp),%eax
  401190:	25 ff ff 7f 00       	and    $0x7fffff,%eax
  401195:	89 45 f4             	mov    %eax,-0xc(%ebp)
  401198:	81 7d f8 ff 00 00 00 	cmpl   $0xff,-0x8(%ebp)
  40119f:	75 11                	jne    4011b2 <_float_negate+0x42>
  4011a1:	83 7d 08 00          	cmpl   $0x0,0x8(%ebp)
  4011a5:	74 0b                	je     4011b2 <_float_negate+0x42>
  4011a7:	b8 01 00 00 00       	mov    $0x1,%eax
  4011ac:	2b 45 fc             	sub    -0x4(%ebp),%eax
  4011af:	89 45 fc             	mov    %eax,-0x4(%ebp)
  4011b2:	8b 45 fc             	mov    -0x4(%ebp),%eax
  4011b5:	89 c2                	mov    %eax,%edx
  4011b7:	c1 e2 1f             	shl    $0x1f,%edx
  4011ba:	8b 45 f8             	mov    -0x8(%ebp),%eax
  4011bd:	c1 e0 17             	shl    $0x17,%eax
  4011c0:	09 d0                	or     %edx,%eax
  4011c2:	0b 45 f4             	or     -0xc(%ebp),%eax
  4011c5:	c9                   	leave  
  4011c6:	c3                   	ret    

004011c7 <_float_negate_real>:
  4011c7:	55                   	push   %ebp
  4011c8:	89 e5                	mov    %esp,%ebp
  4011ca:	d9 45 08             	flds   0x8(%ebp)
  4011cd:	d9 e0                	fchs   
  4011cf:	5d                   	pop    %ebp
  4011d0:	c3                   	ret    

004011d1 <_check_float_negate_val>:
  4011d1:	55                   	push   %ebp
  4011d2:	89 e5                	mov    %esp,%ebp
  4011d4:	83 ec 10             	sub    $0x10,%esp
  4011d7:	8d 45 08             	lea    0x8(%ebp),%eax
  4011da:	8b 00                	mov    (%eax),%eax
  4011dc:	89 45 fc             	mov    %eax,-0x4(%ebp)
  4011df:	d9 45 fc             	flds   -0x4(%ebp)
  4011e2:	d9 e0                	fchs   
  4011e4:	d9 5d f8             	fstps  -0x8(%ebp)
  4011e7:	c9                   	leave  
  4011e8:	c3                   	ret    

004011e9 <_main>:
  4011e9:	55                   	push   %ebp
  4011ea:	89 e5                	mov    %esp,%ebp
  4011ec:	83 e4 f0             	and    $0xfffffff0,%esp
  4011ef:	83 ec 20             	sub    $0x20,%esp
  4011f2:	e8 b9 00 00 00       	call   4012b0 <___main>
  4011f7:	c7 44 24 1c ff ff ff 	movl   $0xffffffff,0x1c(%esp)
  4011fe:	ff 
  4011ff:	8b 44 24 1c          	mov    0x1c(%esp),%eax
  401203:	89 04 24             	mov    %eax,(%esp)
  401206:	e8 c6 ff ff ff       	call   4011d1 <_check_float_negate_val>
  40120b:	8b 44 24 1c          	mov    0x1c(%esp),%eax
  40120f:	25 ff ff ff 00       	and    $0xffffff,%eax
  401214:	85 c0                	test   %eax,%eax
  401216:	75 19                	jne    401231 <_main+0x48>
  401218:	8b 44 24 1c          	mov    0x1c(%esp),%eax
  40121c:	83 44 24 1c 01       	addl   $0x1,0x1c(%esp)
  401221:	89 44 24 04          	mov    %eax,0x4(%esp)
  401225:	c7 04 24 80 20 40 00 	movl   $0x402080,(%esp)
  40122c:	e8 87 00 00 00       	call   4012b8 <_printf>
  401231:	83 6c 24 1c 01       	subl   $0x1,0x1c(%esp)
  401236:	eb c7                	jmp    4011ff <_main+0x16>
	...

00401240 <_cygwin_crt0>:
  401240:	55                   	push   %ebp
  401241:	89 e5                	mov    %esp,%ebp
  401243:	83 ec 08             	sub    $0x8,%esp
  401246:	8b 45 08             	mov    0x8(%ebp),%eax
  401249:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
  401250:	00 
  401251:	89 04 24             	mov    %eax,(%esp)
  401254:	e8 67 00 00 00       	call   4012c0 <__cygwin_crt0_common@8>
  401259:	83 ec 08             	sub    $0x8,%esp
  40125c:	ff 15 7c 50 40 00    	call   *0x40507c
  401262:	90                   	nop
  401263:	90                   	nop
  401264:	90                   	nop
  401265:	90                   	nop
  401266:	90                   	nop
  401267:	90                   	nop
  401268:	90                   	nop
  401269:	90                   	nop
  40126a:	90                   	nop
  40126b:	90                   	nop
  40126c:	90                   	nop
  40126d:	90                   	nop
  40126e:	90                   	nop
  40126f:	90                   	nop

00401270 <_cygwin_premain0>:
  401270:	55                   	push   %ebp
  401271:	89 e5                	mov    %esp,%ebp
  401273:	5d                   	pop    %ebp
  401274:	c3                   	ret    
  401275:	90                   	nop
  401276:	90                   	nop
  401277:	90                   	nop
  401278:	90                   	nop
  401279:	90                   	nop
  40127a:	90                   	nop
  40127b:	90                   	nop
  40127c:	90                   	nop
  40127d:	90                   	nop
  40127e:	90                   	nop
  40127f:	90                   	nop

00401280 <_cygwin_premain1>:
  401280:	55                   	push   %ebp
  401281:	89 e5                	mov    %esp,%ebp
  401283:	5d                   	pop    %ebp
  401284:	c3                   	ret    
  401285:	90                   	nop
  401286:	90                   	nop
  401287:	90                   	nop
  401288:	90                   	nop
  401289:	90                   	nop
  40128a:	90                   	nop
  40128b:	90                   	nop
  40128c:	90                   	nop
  40128d:	90                   	nop
  40128e:	90                   	nop
  40128f:	90                   	nop

00401290 <_cygwin_premain2>:
  401290:	55                   	push   %ebp
  401291:	89 e5                	mov    %esp,%ebp
  401293:	5d                   	pop    %ebp
  401294:	c3                   	ret    
  401295:	90                   	nop
  401296:	90                   	nop
  401297:	90                   	nop
  401298:	90                   	nop
  401299:	90                   	nop
  40129a:	90                   	nop
  40129b:	90                   	nop
  40129c:	90                   	nop
  40129d:	90                   	nop
  40129e:	90                   	nop
  40129f:	90                   	nop

004012a0 <_cygwin_premain3>:
  4012a0:	55                   	push   %ebp
  4012a1:	89 e5                	mov    %esp,%ebp
  4012a3:	5d                   	pop    %ebp
  4012a4:	c3                   	ret    
  4012a5:	90                   	nop
  4012a6:	90                   	nop
  4012a7:	90                   	nop
  4012a8:	90                   	nop
  4012a9:	90                   	nop
  4012aa:	90                   	nop
  4012ab:	90                   	nop
  4012ac:	90                   	nop
  4012ad:	90                   	nop
  4012ae:	90                   	nop
  4012af:	90                   	nop

004012b0 <___main>:
  4012b0:	ff 25 78 50 40 00    	jmp    *0x405078
  4012b6:	90                   	nop
  4012b7:	90                   	nop

004012b8 <_printf>:
  4012b8:	ff 25 9c 50 40 00    	jmp    *0x40509c
  4012be:	90                   	nop
  4012bf:	90                   	nop

004012c0 <__cygwin_crt0_common@8>:
  4012c0:	55                   	push   %ebp
  4012c1:	89 e5                	mov    %esp,%ebp
  4012c3:	56                   	push   %esi
  4012c4:	53                   	push   %ebx
  4012c5:	83 ec 10             	sub    $0x10,%esp
  4012c8:	8b 5d 0c             	mov    0xc(%ebp),%ebx
  4012cb:	8b 75 08             	mov    0x8(%ebp),%esi
  4012ce:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
  4012d5:	e8 16 04 00 00       	call   4016f0 <_cygwin_internal>
  4012da:	85 db                	test   %ebx,%ebx
  4012dc:	89 c1                	mov    %eax,%ecx
  4012de:	0f 84 bc 01 00 00    	je     4014a0 <__cygwin_crt0_common@8+0x1e0>
  4012e4:	a1 80 50 40 00       	mov    0x405080,%eax
  4012e9:	85 c9                	test   %ecx,%ecx
  4012eb:	c7 43 04 a8 00 00 00 	movl   $0xa8,0x4(%ebx)
  4012f2:	c7 43 08 ef 03 00 00 	movl   $0x3ef,0x8(%ebx)
  4012f9:	c7 43 0c 09 00 00 00 	movl   $0x9,0xc(%ebx)
  401300:	89 43 10             	mov    %eax,0x10(%ebx)
  401303:	8b 45 00             	mov    0x0(%ebp),%eax
  401306:	c7 83 80 00 00 00 00 	movl   $0x0,0x80(%ebx)
  40130d:	00 00 00 
  401310:	c7 83 84 00 00 00 ed 	movl   $0xed,0x84(%ebx)
  401317:	00 00 00 
  40131a:	c7 43 2c d0 17 40 00 	movl   $0x4017d0,0x2c(%ebx)
  401321:	c7 43 30 dc 17 40 00 	movl   $0x4017dc,0x30(%ebx)
  401328:	c7 43 14 18 40 40 00 	movl   $0x404018,0x14(%ebx)
  40132f:	89 73 28             	mov    %esi,0x28(%ebx)
  401332:	c7 43 48 70 12 40 00 	movl   $0x401270,0x48(%ebx)
  401339:	c7 43 4c 80 12 40 00 	movl   $0x401280,0x4c(%ebx)
  401340:	c7 43 50 90 12 40 00 	movl   $0x401290,0x50(%ebx)
  401347:	c7 43 54 a0 12 40 00 	movl   $0x4012a0,0x54(%ebx)
  40134e:	c7 43 24 1c 40 40 00 	movl   $0x40401c,0x24(%ebx)
  401355:	89 03                	mov    %eax,(%ebx)
  401357:	c7 43 18 10 17 40 00 	movl   $0x401710,0x18(%ebx)
  40135e:	c7 43 1c 18 17 40 00 	movl   $0x401718,0x1c(%ebx)
  401365:	c7 43 20 20 17 40 00 	movl   $0x401720,0x20(%ebx)
  40136c:	c7 43 44 28 17 40 00 	movl   $0x401728,0x44(%ebx)
  401373:	0f 84 c1 00 00 00    	je     40143a <__cygwin_crt0_common@8+0x17a>
  401379:	8b 51 78             	mov    0x78(%ecx),%edx
  40137c:	85 d2                	test   %edx,%edx
  40137e:	0f 84 b6 00 00 00    	je     40143a <__cygwin_crt0_common@8+0x17a>
  401384:	a1 20 40 40 00       	mov    0x404020,%eax
  401389:	85 c0                	test   %eax,%eax
  40138b:	0f 85 a9 00 00 00    	jne    40143a <__cygwin_crt0_common@8+0x17a>
  401391:	a1 00 20 40 00       	mov    0x402000,%eax
  401396:	85 c0                	test   %eax,%eax
  401398:	0f 84 12 02 00 00    	je     4015b0 <__cygwin_crt0_common@8+0x2f0>
  40139e:	a1 04 20 40 00       	mov    0x402004,%eax
  4013a3:	85 c0                	test   %eax,%eax
  4013a5:	0f 84 f5 01 00 00    	je     4015a0 <__cygwin_crt0_common@8+0x2e0>
  4013ab:	a1 08 20 40 00       	mov    0x402008,%eax
  4013b0:	85 c0                	test   %eax,%eax
  4013b2:	0f 84 d8 01 00 00    	je     401590 <__cygwin_crt0_common@8+0x2d0>
  4013b8:	a1 0c 20 40 00       	mov    0x40200c,%eax
  4013bd:	85 c0                	test   %eax,%eax
  4013bf:	0f 84 bb 01 00 00    	je     401580 <__cygwin_crt0_common@8+0x2c0>
  4013c5:	a1 10 20 40 00       	mov    0x402010,%eax
  4013ca:	85 c0                	test   %eax,%eax
  4013cc:	0f 84 9e 01 00 00    	je     401570 <__cygwin_crt0_common@8+0x2b0>
  4013d2:	8b 35 14 20 40 00    	mov    0x402014,%esi
  4013d8:	85 f6                	test   %esi,%esi
  4013da:	0f 84 80 01 00 00    	je     401560 <__cygwin_crt0_common@8+0x2a0>
  4013e0:	8b 0d 18 20 40 00    	mov    0x402018,%ecx
  4013e6:	85 c9                	test   %ecx,%ecx
  4013e8:	0f 84 62 01 00 00    	je     401550 <__cygwin_crt0_common@8+0x290>
  4013ee:	a1 1c 20 40 00       	mov    0x40201c,%eax
  4013f3:	85 c0                	test   %eax,%eax
  4013f5:	0f 84 47 01 00 00    	je     401542 <__cygwin_crt0_common@8+0x282>
  4013fb:	a1 00 20 40 00       	mov    0x402000,%eax
  401400:	89 02                	mov    %eax,(%edx)
  401402:	a1 04 20 40 00       	mov    0x402004,%eax
  401407:	89 42 04             	mov    %eax,0x4(%edx)
  40140a:	a1 08 20 40 00       	mov    0x402008,%eax
  40140f:	89 42 08             	mov    %eax,0x8(%edx)
  401412:	a1 0c 20 40 00       	mov    0x40200c,%eax
  401417:	89 42 0c             	mov    %eax,0xc(%edx)
  40141a:	a1 10 20 40 00       	mov    0x402010,%eax
  40141f:	89 42 10             	mov    %eax,0x10(%edx)
  401422:	a1 14 20 40 00       	mov    0x402014,%eax
  401427:	89 42 14             	mov    %eax,0x14(%edx)
  40142a:	a1 18 20 40 00       	mov    0x402018,%eax
  40142f:	89 42 18             	mov    %eax,0x18(%edx)
  401432:	a1 1c 20 40 00       	mov    0x40201c,%eax
  401437:	89 42 1c             	mov    %eax,0x1c(%edx)
  40143a:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
  401441:	e8 52 03 00 00       	call   401798 <_GetModuleHandleA@4>
  401446:	c7 43 34 00 20 40 00 	movl   $0x402000,0x34(%ebx)
  40144d:	c7 43 38 a4 20 40 00 	movl   $0x4020a4,0x38(%ebx)
  401454:	c7 43 3c 00 40 40 00 	movl   $0x404000,0x3c(%ebx)
  40145b:	c7 43 40 28 41 40 00 	movl   $0x404128,0x40(%ebx)
  401462:	c7 83 94 00 00 00 00 	movl   $0x403000,0x94(%ebx)
  401469:	30 40 00 
  40146c:	89 43 7c             	mov    %eax,0x7c(%ebx)
  40146f:	83 ec 04             	sub    $0x4,%esp
  401472:	c7 83 98 00 00 00 00 	movl   $0x403000,0x98(%ebx)
  401479:	30 40 00 
  40147c:	c7 83 9c 00 00 00 00 	movl   $0x400000,0x9c(%ebx)
  401483:	00 40 00 
  401486:	e8 75 02 00 00       	call   401700 <__pei386_runtime_relocator>
  40148b:	8d 65 f8             	lea    -0x8(%ebp),%esp
  40148e:	b8 01 00 00 00       	mov    $0x1,%eax
  401493:	5b                   	pop    %ebx
  401494:	5e                   	pop    %esi
  401495:	5d                   	pop    %ebp
  401496:	c2 08 00             	ret    $0x8
  401499:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  4014a0:	c7 40 04 a8 00 00 00 	movl   $0xa8,0x4(%eax)
  4014a7:	8b 15 80 50 40 00    	mov    0x405080,%edx
  4014ad:	85 c9                	test   %ecx,%ecx
  4014af:	c7 40 08 ef 03 00 00 	movl   $0x3ef,0x8(%eax)
  4014b6:	89 cb                	mov    %ecx,%ebx
  4014b8:	c7 40 0c 09 00 00 00 	movl   $0x9,0xc(%eax)
  4014bf:	c7 80 80 00 00 00 00 	movl   $0x0,0x80(%eax)
  4014c6:	00 00 00 
  4014c9:	c7 80 84 00 00 00 ed 	movl   $0xed,0x84(%eax)
  4014d0:	00 00 00 
  4014d3:	c7 40 2c d0 17 40 00 	movl   $0x4017d0,0x2c(%eax)
  4014da:	c7 40 30 dc 17 40 00 	movl   $0x4017dc,0x30(%eax)
  4014e1:	c7 40 14 18 40 40 00 	movl   $0x404018,0x14(%eax)
  4014e8:	8b 80 a4 00 00 00    	mov    0xa4(%eax),%eax
  4014ee:	89 71 28             	mov    %esi,0x28(%ecx)
  4014f1:	c7 41 48 70 12 40 00 	movl   $0x401270,0x48(%ecx)
  4014f8:	c7 41 4c 80 12 40 00 	movl   $0x401280,0x4c(%ecx)
  4014ff:	89 02                	mov    %eax,(%edx)
  401501:	8b 45 00             	mov    0x0(%ebp),%eax
  401504:	c7 41 50 90 12 40 00 	movl   $0x401290,0x50(%ecx)
  40150b:	c7 41 54 a0 12 40 00 	movl   $0x4012a0,0x54(%ecx)
  401512:	c7 41 24 1c 40 40 00 	movl   $0x40401c,0x24(%ecx)
  401519:	89 01                	mov    %eax,(%ecx)
  40151b:	c7 41 18 10 17 40 00 	movl   $0x401710,0x18(%ecx)
  401522:	c7 41 1c 18 17 40 00 	movl   $0x401718,0x1c(%ecx)
  401529:	c7 41 20 20 17 40 00 	movl   $0x401720,0x20(%ecx)
  401530:	c7 41 44 28 17 40 00 	movl   $0x401728,0x44(%ecx)
  401537:	0f 85 3c fe ff ff    	jne    401379 <__cygwin_crt0_common@8+0xb9>
  40153d:	e9 f8 fe ff ff       	jmp    40143a <__cygwin_crt0_common@8+0x17a>
  401542:	8b 42 1c             	mov    0x1c(%edx),%eax
  401545:	a3 1c 20 40 00       	mov    %eax,0x40201c
  40154a:	e9 ac fe ff ff       	jmp    4013fb <__cygwin_crt0_common@8+0x13b>
  40154f:	90                   	nop
  401550:	8b 42 18             	mov    0x18(%edx),%eax
  401553:	a3 18 20 40 00       	mov    %eax,0x402018
  401558:	e9 91 fe ff ff       	jmp    4013ee <__cygwin_crt0_common@8+0x12e>
  40155d:	8d 76 00             	lea    0x0(%esi),%esi
  401560:	8b 42 14             	mov    0x14(%edx),%eax
  401563:	a3 14 20 40 00       	mov    %eax,0x402014
  401568:	e9 73 fe ff ff       	jmp    4013e0 <__cygwin_crt0_common@8+0x120>
  40156d:	8d 76 00             	lea    0x0(%esi),%esi
  401570:	8b 42 10             	mov    0x10(%edx),%eax
  401573:	a3 10 20 40 00       	mov    %eax,0x402010
  401578:	e9 55 fe ff ff       	jmp    4013d2 <__cygwin_crt0_common@8+0x112>
  40157d:	8d 76 00             	lea    0x0(%esi),%esi
  401580:	8b 42 0c             	mov    0xc(%edx),%eax
  401583:	a3 0c 20 40 00       	mov    %eax,0x40200c
  401588:	e9 38 fe ff ff       	jmp    4013c5 <__cygwin_crt0_common@8+0x105>
  40158d:	8d 76 00             	lea    0x0(%esi),%esi
  401590:	8b 42 08             	mov    0x8(%edx),%eax
  401593:	a3 08 20 40 00       	mov    %eax,0x402008
  401598:	e9 1b fe ff ff       	jmp    4013b8 <__cygwin_crt0_common@8+0xf8>
  40159d:	8d 76 00             	lea    0x0(%esi),%esi
  4015a0:	8b 42 04             	mov    0x4(%edx),%eax
  4015a3:	a3 04 20 40 00       	mov    %eax,0x402004
  4015a8:	e9 fe fd ff ff       	jmp    4013ab <__cygwin_crt0_common@8+0xeb>
  4015ad:	8d 76 00             	lea    0x0(%esi),%esi
  4015b0:	8b 02                	mov    (%edx),%eax
  4015b2:	a3 00 20 40 00       	mov    %eax,0x402000
  4015b7:	e9 e2 fd ff ff       	jmp    40139e <__cygwin_crt0_common@8+0xde>
  4015bc:	90                   	nop
  4015bd:	90                   	nop
  4015be:	90                   	nop
  4015bf:	90                   	nop

004015c0 <___dllMain>:
  4015c0:	55                   	push   %ebp
  4015c1:	89 e5                	mov    %esp,%ebp
  4015c3:	83 ec 18             	sub    $0x18,%esp
  4015c6:	a1 48 40 40 00       	mov    0x404048,%eax
  4015cb:	89 44 24 08          	mov    %eax,0x8(%esp)
  4015cf:	a1 38 40 40 00       	mov    0x404038,%eax
  4015d4:	89 44 24 04          	mov    %eax,0x4(%esp)
  4015d8:	a1 28 40 40 00       	mov    0x404028,%eax
  4015dd:	89 04 24             	mov    %eax,(%esp)
  4015e0:	e8 9b 01 00 00       	call   401780 <_DllMain@12>
  4015e5:	83 ec 0c             	sub    $0xc,%esp
  4015e8:	c9                   	leave  
  4015e9:	c3                   	ret    
  4015ea:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi

004015f0 <__cygwin_dll_entry@12>:
  4015f0:	55                   	push   %ebp
  4015f1:	89 e5                	mov    %esp,%ebp
  4015f3:	53                   	push   %ebx
  4015f4:	83 ec 14             	sub    $0x14,%esp
  4015f7:	8b 45 0c             	mov    0xc(%ebp),%eax
  4015fa:	8b 4d 08             	mov    0x8(%ebp),%ecx
  4015fd:	8b 55 10             	mov    0x10(%ebp),%edx
  401600:	83 f8 01             	cmp    $0x1,%eax
  401603:	0f 84 87 00 00 00    	je     401690 <__cygwin_dll_entry@12+0xa0>
  401609:	72 18                	jb     401623 <__cygwin_dll_entry@12+0x33>
  40160b:	83 f8 02             	cmp    $0x2,%eax
  40160e:	74 66                	je     401676 <__cygwin_dll_entry@12+0x86>
  401610:	83 f8 03             	cmp    $0x3,%eax
  401613:	bb 01 00 00 00       	mov    $0x1,%ebx
  401618:	74 46                	je     401660 <__cygwin_dll_entry@12+0x70>
  40161a:	89 d8                	mov    %ebx,%eax
  40161c:	8b 5d fc             	mov    -0x4(%ebp),%ebx
  40161f:	c9                   	leave  
  401620:	c2 0c 00             	ret    $0xc
  401623:	89 54 24 08          	mov    %edx,0x8(%esp)
  401627:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
  40162e:	00 
  40162f:	89 0c 24             	mov    %ecx,(%esp)
  401632:	e8 49 01 00 00       	call   401780 <_DllMain@12>
  401637:	83 ec 0c             	sub    $0xc,%esp
  40163a:	85 c0                	test   %eax,%eax
  40163c:	89 c3                	mov    %eax,%ebx
  40163e:	74 da                	je     40161a <__cygwin_dll_entry@12+0x2a>
  401640:	a1 58 40 40 00       	mov    0x404058,%eax
  401645:	89 04 24             	mov    %eax,(%esp)
  401648:	e8 23 01 00 00       	call   401770 <_cygwin_detach_dll>
  40164d:	c7 05 58 40 40 00 ff 	movl   $0xffffffff,0x404058
  401654:	ff ff ff 
  401657:	eb c1                	jmp    40161a <__cygwin_dll_entry@12+0x2a>
  401659:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  401660:	89 55 10             	mov    %edx,0x10(%ebp)
  401663:	8b 5d fc             	mov    -0x4(%ebp),%ebx
  401666:	c7 45 0c 03 00 00 00 	movl   $0x3,0xc(%ebp)
  40166d:	89 4d 08             	mov    %ecx,0x8(%ebp)
  401670:	c9                   	leave  
  401671:	e9 0a 01 00 00       	jmp    401780 <_DllMain@12>
  401676:	89 55 10             	mov    %edx,0x10(%ebp)
  401679:	8b 5d fc             	mov    -0x4(%ebp),%ebx
  40167c:	c7 45 0c 02 00 00 00 	movl   $0x2,0xc(%ebp)
  401683:	89 4d 08             	mov    %ecx,0x8(%ebp)
  401686:	c9                   	leave  
  401687:	e9 f4 00 00 00       	jmp    401780 <_DllMain@12>
  40168c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  401690:	31 c0                	xor    %eax,%eax
  401692:	85 d2                	test   %edx,%edx
  401694:	0f 94 c0             	sete   %al
  401697:	31 db                	xor    %ebx,%ebx
  401699:	89 0d 28 40 40 00    	mov    %ecx,0x404028
  40169f:	c7 05 38 40 40 00 01 	movl   $0x1,0x404038
  4016a6:	00 00 00 
  4016a9:	89 15 48 40 40 00    	mov    %edx,0x404048
  4016af:	a3 20 40 40 00       	mov    %eax,0x404020
  4016b4:	c7 44 24 04 c0 15 40 	movl   $0x4015c0,0x4(%esp)
  4016bb:	00 
  4016bc:	89 0c 24             	mov    %ecx,(%esp)
  4016bf:	e8 6c 00 00 00       	call   401730 <_cygwin_attach_dll>
  4016c4:	83 f8 ff             	cmp    $0xffffffff,%eax
  4016c7:	0f 95 c3             	setne  %bl
  4016ca:	a3 58 40 40 00       	mov    %eax,0x404058
  4016cf:	89 d8                	mov    %ebx,%eax
  4016d1:	8b 5d fc             	mov    -0x4(%ebp),%ebx
  4016d4:	c9                   	leave  
  4016d5:	c2 0c 00             	ret    $0xc
  4016d8:	90                   	nop
  4016d9:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi

004016e0 <__cygwin_noncygwin_dll_entry@12>:
  4016e0:	55                   	push   %ebp
  4016e1:	89 e5                	mov    %esp,%ebp
  4016e3:	c9                   	leave  
  4016e4:	e9 07 ff ff ff       	jmp    4015f0 <__cygwin_dll_entry@12>
  4016e9:	90                   	nop
  4016ea:	90                   	nop
  4016eb:	90                   	nop
  4016ec:	90                   	nop
  4016ed:	90                   	nop
  4016ee:	90                   	nop
  4016ef:	90                   	nop

004016f0 <_cygwin_internal>:
  4016f0:	ff 25 8c 50 40 00    	jmp    *0x40508c
  4016f6:	90                   	nop
  4016f7:	90                   	nop
	...

00401700 <__pei386_runtime_relocator>:
  401700:	55                   	push   %ebp
  401701:	89 e5                	mov    %esp,%ebp
  401703:	5d                   	pop    %ebp
  401704:	c3                   	ret    
  401705:	90                   	nop
  401706:	90                   	nop
  401707:	90                   	nop
  401708:	90                   	nop
  401709:	90                   	nop
  40170a:	90                   	nop
  40170b:	90                   	nop
  40170c:	90                   	nop
  40170d:	90                   	nop
  40170e:	90                   	nop
  40170f:	90                   	nop

00401710 <_malloc>:
  401710:	ff 25 98 50 40 00    	jmp    *0x405098
  401716:	90                   	nop
  401717:	90                   	nop

00401718 <_free>:
  401718:	ff 25 94 50 40 00    	jmp    *0x405094
  40171e:	90                   	nop
  40171f:	90                   	nop

00401720 <_realloc>:
  401720:	ff 25 a0 50 40 00    	jmp    *0x4050a0
  401726:	90                   	nop
  401727:	90                   	nop

00401728 <_calloc>:
  401728:	ff 25 84 50 40 00    	jmp    *0x405084
  40172e:	90                   	nop
  40172f:	90                   	nop

00401730 <_cygwin_attach_dll>:
  401730:	55                   	push   %ebp
  401731:	89 e5                	mov    %esp,%ebp
  401733:	53                   	push   %ebx
  401734:	83 ec 14             	sub    $0x14,%esp
  401737:	8b 5d 08             	mov    0x8(%ebp),%ebx
  40173a:	c7 44 24 04 68 40 40 	movl   $0x404068,0x4(%esp)
  401741:	00 
  401742:	8b 45 0c             	mov    0xc(%ebp),%eax
  401745:	89 04 24             	mov    %eax,(%esp)
  401748:	e8 73 fb ff ff       	call   4012c0 <__cygwin_crt0_common@8>
  40174d:	89 5d 08             	mov    %ebx,0x8(%ebp)
  401750:	8b 5d fc             	mov    -0x4(%ebp),%ebx
  401753:	c7 45 0c 68 40 40 00 	movl   $0x404068,0xc(%ebp)
  40175a:	83 ec 08             	sub    $0x8,%esp
  40175d:	c9                   	leave  
  40175e:	e9 2d 00 00 00       	jmp    401790 <_dll_dllcrt0>
  401763:	90                   	nop
  401764:	90                   	nop
  401765:	90                   	nop
  401766:	90                   	nop
  401767:	90                   	nop
  401768:	90                   	nop
  401769:	90                   	nop
  40176a:	90                   	nop
  40176b:	90                   	nop
  40176c:	90                   	nop
  40176d:	90                   	nop
  40176e:	90                   	nop
  40176f:	90                   	nop

00401770 <_cygwin_detach_dll>:
  401770:	ff 25 88 50 40 00    	jmp    *0x405088
  401776:	90                   	nop
  401777:	90                   	nop
	...

00401780 <_DllMain@12>:
  401780:	55                   	push   %ebp
  401781:	b8 01 00 00 00       	mov    $0x1,%eax
  401786:	89 e5                	mov    %esp,%ebp
  401788:	5d                   	pop    %ebp
  401789:	c2 0c 00             	ret    $0xc
  40178c:	90                   	nop
  40178d:	90                   	nop
  40178e:	90                   	nop
  40178f:	90                   	nop

00401790 <_dll_dllcrt0>:
  401790:	ff 25 90 50 40 00    	jmp    *0x405090
  401796:	90                   	nop
  401797:	90                   	nop

00401798 <_GetModuleHandleA@4>:
  401798:	ff 25 a8 50 40 00    	jmp    *0x4050a8
  40179e:	90                   	nop
  40179f:	90                   	nop

004017a0 <_GetProcAddress@8>:
  4017a0:	ff 25 ac 50 40 00    	jmp    *0x4050ac
  4017a6:	90                   	nop
  4017a7:	90                   	nop

004017a8 <.text>:
	...

004017b0 <_register_frame_ctor>:
  4017b0:	55                   	push   %ebp
  4017b1:	89 e5                	mov    %esp,%ebp
  4017b3:	83 ec 08             	sub    $0x8,%esp
  4017b6:	c9                   	leave  
  4017b7:	e9 d4 f8 ff ff       	jmp    401090 <___gcc_register_frame>
  4017bc:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi

004017c0 <_deregister_frame_dtor>:
  4017c0:	55                   	push   %ebp
  4017c1:	89 e5                	mov    %esp,%ebp
  4017c3:	83 ec 08             	sub    $0x8,%esp
  4017c6:	c9                   	leave  
  4017c7:	e9 54 f9 ff ff       	jmp    401120 <___gcc_deregister_frame>
  4017cc:	90                   	nop
  4017cd:	90                   	nop
  4017ce:	90                   	nop
  4017cf:	90                   	nop

004017d0 <__CTOR_LIST__>:
  4017d0:	ff                   	(bad)  
  4017d1:	ff                   	(bad)  
  4017d2:	ff                   	(bad)  
  4017d3:	ff b0 17 40 00 00    	pushl  0x4017(%eax)

004017d4 <.ctors.65535>:
  4017d4:	b0 17                	mov    $0x17,%al
  4017d6:	40                   	inc    %eax
  4017d7:	00 00                	add    %al,(%eax)
  4017d9:	00 00                	add    %al,(%eax)
	...

004017dc <__DTOR_LIST__>:
  4017dc:	ff                   	(bad)  
  4017dd:	ff                   	(bad)  
  4017de:	ff                   	(bad)  
  4017df:	ff c0                	inc    %eax

004017e0 <.dtors.65535>:
  4017e0:	c0 17 40             	rclb   $0x40,(%edi)
  4017e3:	00 00                	add    %al,(%eax)
  4017e5:	00 00                	add    %al,(%eax)
	...
