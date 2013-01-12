
./a.exe:     file format pei-i386


Disassembly of section .text:

00401000 <_WinMainCRTStartup>:
  401000:	55                   	push   %ebp
  401001:	89 e5                	mov    %esp,%ebp
  401003:	83 ec 18             	sub    $0x18,%esp
  401006:	83 e4 f0             	and    $0xfffffff0,%esp
  401009:	c7 04 24 49 13 40 00 	movl   $0x401349,(%esp)
  401010:	e8 8b 03 00 00       	call   4013a0 <_cygwin_crt0>
  401015:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
  40101c:	00 
  40101d:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
  401024:	00 
  401025:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
  40102c:	e8 9f 03 00 00       	call   4013d0 <_cygwin_premain0>
  401031:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
  401038:	00 
  401039:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
  401040:	00 
  401041:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
  401048:	e8 93 03 00 00       	call   4013e0 <_cygwin_premain1>
  40104d:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
  401054:	00 
  401055:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
  40105c:	00 
  40105d:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
  401064:	e8 87 03 00 00       	call   4013f0 <_cygwin_premain2>
  401069:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%esp)
  401070:	00 
  401071:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
  401078:	00 
  401079:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
  401080:	e8 7b 03 00 00       	call   401400 <_cygwin_premain3>
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
  40109d:	e8 66 08 00 00       	call   401908 <_GetModuleHandleA@4>
  4010a2:	89 c2                	mov    %eax,%edx
  4010a4:	83 ec 04             	sub    $0x4,%esp
  4010a7:	85 d2                	test   %edx,%edx
  4010a9:	b8 00 00 00 00       	mov    $0x0,%eax
  4010ae:	74 13                	je     4010c3 <___gcc_register_frame+0x33>
  4010b0:	c7 44 24 04 2f 20 40 	movl   $0x40202f,0x4(%esp)
  4010b7:	00 
  4010b8:	89 14 24             	mov    %edx,(%esp)
  4010bb:	e8 50 08 00 00       	call   401910 <_GetProcAddress@8>
  4010c0:	83 ec 08             	sub    $0x8,%esp
  4010c3:	85 c0                	test   %eax,%eax
  4010c5:	74 11                	je     4010d8 <___gcc_register_frame+0x48>
  4010c7:	c7 44 24 04 00 40 40 	movl   $0x404000,0x4(%esp)
  4010ce:	00 
  4010cf:	c7 04 24 00 30 40 00 	movl   $0x403000,(%esp)
  4010d6:	ff d0                	call   *%eax
  4010d8:	a1 78 21 40 00       	mov    0x402178,%eax
  4010dd:	85 c0                	test   %eax,%eax
  4010df:	74 3a                	je     40111b <___gcc_register_frame+0x8b>
  4010e1:	c7 04 24 45 20 40 00 	movl   $0x402045,(%esp)
  4010e8:	e8 1b 08 00 00       	call   401908 <_GetModuleHandleA@4>
  4010ed:	89 c2                	mov    %eax,%edx
  4010ef:	83 ec 04             	sub    $0x4,%esp
  4010f2:	85 d2                	test   %edx,%edx
  4010f4:	b8 00 00 00 00       	mov    $0x0,%eax
  4010f9:	74 13                	je     40110e <___gcc_register_frame+0x7e>
  4010fb:	c7 44 24 04 53 20 40 	movl   $0x402053,0x4(%esp)
  401102:	00 
  401103:	89 14 24             	mov    %edx,(%esp)
  401106:	e8 05 08 00 00       	call   401910 <_GetProcAddress@8>
  40110b:	83 ec 08             	sub    $0x8,%esp
  40110e:	85 c0                	test   %eax,%eax
  401110:	74 09                	je     40111b <___gcc_register_frame+0x8b>
  401112:	c7 04 24 78 21 40 00 	movl   $0x402178,(%esp)
  401119:	ff d0                	call   *%eax
  40111b:	c9                   	leave  
  40111c:	c3                   	ret    
  40111d:	8d 76 00             	lea    0x0(%esi),%esi

00401120 <___gcc_deregister_frame>:
  401120:	55                   	push   %ebp
  401121:	89 e5                	mov    %esp,%ebp
  401123:	83 ec 18             	sub    $0x18,%esp
  401126:	c7 04 24 20 20 40 00 	movl   $0x402020,(%esp)
  40112d:	e8 d6 07 00 00       	call   401908 <_GetModuleHandleA@4>
  401132:	89 c2                	mov    %eax,%edx
  401134:	83 ec 04             	sub    $0x4,%esp
  401137:	85 d2                	test   %edx,%edx
  401139:	b8 00 00 00 00       	mov    $0x0,%eax
  40113e:	74 13                	je     401153 <___gcc_deregister_frame+0x33>
  401140:	c7 44 24 04 67 20 40 	movl   $0x402067,0x4(%esp)
  401147:	00 
  401148:	89 14 24             	mov    %edx,(%esp)
  40114b:	e8 c0 07 00 00       	call   401910 <_GetProcAddress@8>
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
  4011d4:	83 ec 38             	sub    $0x38,%esp
  4011d7:	8d 45 08             	lea    0x8(%ebp),%eax
  4011da:	8b 00                	mov    (%eax),%eax
  4011dc:	89 45 f4             	mov    %eax,-0xc(%ebp)
  4011df:	8b 45 f4             	mov    -0xc(%ebp),%eax
  4011e2:	89 04 24             	mov    %eax,(%esp)
  4011e5:	e8 dd ff ff ff       	call   4011c7 <_float_negate_real>
  4011ea:	d9 5d f0             	fstps  -0x10(%ebp)
  4011ed:	8b 45 08             	mov    0x8(%ebp),%eax
  4011f0:	89 04 24             	mov    %eax,(%esp)
  4011f3:	e8 78 ff ff ff       	call   401170 <_float_negate>
  4011f8:	89 45 ec             	mov    %eax,-0x14(%ebp)
  4011fb:	c7 44 24 08 04 00 00 	movl   $0x4,0x8(%esp)
  401202:	00 
  401203:	8d 45 f0             	lea    -0x10(%ebp),%eax
  401206:	89 44 24 04          	mov    %eax,0x4(%esp)
  40120a:	8d 45 ec             	lea    -0x14(%ebp),%eax
  40120d:	89 04 24             	mov    %eax,(%esp)
  401210:	e8 03 02 00 00       	call   401418 <_memcmp>
  401215:	85 c0                	test   %eax,%eax
  401217:	0f 84 2a 01 00 00    	je     401347 <_check_float_negate_val+0x176>
  40121d:	8b 45 08             	mov    0x8(%ebp),%eax
  401220:	89 44 24 04          	mov    %eax,0x4(%esp)
  401224:	c7 04 24 80 20 40 00 	movl   $0x402080,(%esp)
  40122b:	e8 f0 01 00 00       	call   401420 <_printf>
  401230:	8b 45 08             	mov    0x8(%ebp),%eax
  401233:	89 44 24 04          	mov    %eax,0x4(%esp)
  401237:	c7 04 24 85 20 40 00 	movl   $0x402085,(%esp)
  40123e:	e8 dd 01 00 00       	call   401420 <_printf>
  401243:	8b 45 ec             	mov    -0x14(%ebp),%eax
  401246:	89 44 24 04          	mov    %eax,0x4(%esp)
  40124a:	c7 04 24 92 20 40 00 	movl   $0x402092,(%esp)
  401251:	e8 ca 01 00 00       	call   401420 <_printf>
  401256:	d9 45 f4             	flds   -0xc(%ebp)
  401259:	dd 5c 24 04          	fstpl  0x4(%esp)
  40125d:	c7 04 24 a5 20 40 00 	movl   $0x4020a5,(%esp)
  401264:	e8 b7 01 00 00       	call   401420 <_printf>
  401269:	d9 45 f0             	flds   -0x10(%ebp)
  40126c:	dd 5c 24 04          	fstpl  0x4(%esp)
  401270:	c7 04 24 ae 20 40 00 	movl   $0x4020ae,(%esp)
  401277:	e8 a4 01 00 00       	call   401420 <_printf>
  40127c:	8d 45 f4             	lea    -0xc(%ebp),%eax
  40127f:	8b 00                	mov    (%eax),%eax
  401281:	89 44 24 04          	mov    %eax,0x4(%esp)
  401285:	c7 04 24 bd 20 40 00 	movl   $0x4020bd,(%esp)
  40128c:	e8 8f 01 00 00       	call   401420 <_printf>
  401291:	d9 45 f4             	flds   -0xc(%ebp)
  401294:	d9 e0                	fchs   
  401296:	d9 5d e8             	fstps  -0x18(%ebp)
  401299:	8d 45 e8             	lea    -0x18(%ebp),%eax
  40129c:	8b 00                	mov    (%eax),%eax
  40129e:	89 44 24 04          	mov    %eax,0x4(%esp)
  4012a2:	c7 04 24 ca 20 40 00 	movl   $0x4020ca,(%esp)
  4012a9:	e8 72 01 00 00       	call   401420 <_printf>
  4012ae:	8d 45 f0             	lea    -0x10(%ebp),%eax
  4012b1:	89 44 24 04          	mov    %eax,0x4(%esp)
  4012b5:	c7 04 24 d8 20 40 00 	movl   $0x4020d8,(%esp)
  4012bc:	e8 5f 01 00 00       	call   401420 <_printf>
  4012c1:	dd 05 68 21 40 00    	fldl   0x402168
  4012c7:	dd 5c 24 04          	fstpl  0x4(%esp)
  4012cb:	c7 04 24 eb 20 40 00 	movl   $0x4020eb,(%esp)
  4012d2:	e8 49 01 00 00       	call   401420 <_printf>
  4012d7:	dd 05 70 21 40 00    	fldl   0x402170
  4012dd:	dd 5c 24 04          	fstpl  0x4(%esp)
  4012e1:	c7 04 24 f6 20 40 00 	movl   $0x4020f6,(%esp)
  4012e8:	e8 33 01 00 00       	call   401420 <_printf>
  4012ed:	b8 00 00 c0 7f       	mov    $0x7fc00000,%eax
  4012f2:	89 45 e4             	mov    %eax,-0x1c(%ebp)
  4012f5:	8d 45 e4             	lea    -0x1c(%ebp),%eax
  4012f8:	89 44 24 04          	mov    %eax,0x4(%esp)
  4012fc:	c7 04 24 06 21 40 00 	movl   $0x402106,(%esp)
  401303:	e8 18 01 00 00       	call   401420 <_printf>
  401308:	b8 00 00 80 7f       	mov    $0x7f800000,%eax
  40130d:	89 45 e0             	mov    %eax,-0x20(%ebp)
  401310:	8d 45 e0             	lea    -0x20(%ebp),%eax
  401313:	89 44 24 04          	mov    %eax,0x4(%esp)
  401317:	c7 04 24 15 21 40 00 	movl   $0x402115,(%esp)
  40131e:	e8 fd 00 00 00       	call   401420 <_printf>
  401323:	c7 44 24 0c 24 21 40 	movl   $0x402124,0xc(%esp)
  40132a:	00 
  40132b:	c7 44 24 08 4b 21 40 	movl   $0x40214b,0x8(%esp)
  401332:	00 
  401333:	c7 44 24 04 2f 00 00 	movl   $0x2f,0x4(%esp)
  40133a:	00 
  40133b:	c7 04 24 26 21 40 00 	movl   $0x402126,(%esp)
  401342:	e8 e1 00 00 00       	call   401428 <___assert_func>
  401347:	c9                   	leave  
  401348:	c3                   	ret    

00401349 <_main>:
  401349:	55                   	push   %ebp
  40134a:	89 e5                	mov    %esp,%ebp
  40134c:	83 e4 f0             	and    $0xfffffff0,%esp
  40134f:	83 ec 20             	sub    $0x20,%esp
  401352:	e8 b9 00 00 00       	call   401410 <___main>
  401357:	c7 44 24 1c ff ff ff 	movl   $0xffffffff,0x1c(%esp)
  40135e:	ff 
  40135f:	8b 44 24 1c          	mov    0x1c(%esp),%eax
  401363:	89 04 24             	mov    %eax,(%esp)
  401366:	e8 66 fe ff ff       	call   4011d1 <_check_float_negate_val>
  40136b:	8b 44 24 1c          	mov    0x1c(%esp),%eax
  40136f:	25 ff ff ff 00       	and    $0xffffff,%eax
  401374:	85 c0                	test   %eax,%eax
  401376:	75 19                	jne    401391 <_main+0x48>
  401378:	8b 44 24 1c          	mov    0x1c(%esp),%eax
  40137c:	83 44 24 1c 01       	addl   $0x1,0x1c(%esp)
  401381:	89 44 24 04          	mov    %eax,0x4(%esp)
  401385:	c7 04 24 2d 21 40 00 	movl   $0x40212d,(%esp)
  40138c:	e8 8f 00 00 00       	call   401420 <_printf>
  401391:	83 6c 24 1c 01       	subl   $0x1,0x1c(%esp)
  401396:	eb c7                	jmp    40135f <_main+0x16>
	...

004013a0 <_cygwin_crt0>:
  4013a0:	55                   	push   %ebp
  4013a1:	89 e5                	mov    %esp,%ebp
  4013a3:	83 ec 08             	sub    $0x8,%esp
  4013a6:	8b 45 08             	mov    0x8(%ebp),%eax
  4013a9:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
  4013b0:	00 
  4013b1:	89 04 24             	mov    %eax,(%esp)
  4013b4:	e8 77 00 00 00       	call   401430 <__cygwin_crt0_common@8>
  4013b9:	83 ec 08             	sub    $0x8,%esp
  4013bc:	ff 15 88 50 40 00    	call   *0x405088
  4013c2:	90                   	nop
  4013c3:	90                   	nop
  4013c4:	90                   	nop
  4013c5:	90                   	nop
  4013c6:	90                   	nop
  4013c7:	90                   	nop
  4013c8:	90                   	nop
  4013c9:	90                   	nop
  4013ca:	90                   	nop
  4013cb:	90                   	nop
  4013cc:	90                   	nop
  4013cd:	90                   	nop
  4013ce:	90                   	nop
  4013cf:	90                   	nop

004013d0 <_cygwin_premain0>:
  4013d0:	55                   	push   %ebp
  4013d1:	89 e5                	mov    %esp,%ebp
  4013d3:	5d                   	pop    %ebp
  4013d4:	c3                   	ret    
  4013d5:	90                   	nop
  4013d6:	90                   	nop
  4013d7:	90                   	nop
  4013d8:	90                   	nop
  4013d9:	90                   	nop
  4013da:	90                   	nop
  4013db:	90                   	nop
  4013dc:	90                   	nop
  4013dd:	90                   	nop
  4013de:	90                   	nop
  4013df:	90                   	nop

004013e0 <_cygwin_premain1>:
  4013e0:	55                   	push   %ebp
  4013e1:	89 e5                	mov    %esp,%ebp
  4013e3:	5d                   	pop    %ebp
  4013e4:	c3                   	ret    
  4013e5:	90                   	nop
  4013e6:	90                   	nop
  4013e7:	90                   	nop
  4013e8:	90                   	nop
  4013e9:	90                   	nop
  4013ea:	90                   	nop
  4013eb:	90                   	nop
  4013ec:	90                   	nop
  4013ed:	90                   	nop
  4013ee:	90                   	nop
  4013ef:	90                   	nop

004013f0 <_cygwin_premain2>:
  4013f0:	55                   	push   %ebp
  4013f1:	89 e5                	mov    %esp,%ebp
  4013f3:	5d                   	pop    %ebp
  4013f4:	c3                   	ret    
  4013f5:	90                   	nop
  4013f6:	90                   	nop
  4013f7:	90                   	nop
  4013f8:	90                   	nop
  4013f9:	90                   	nop
  4013fa:	90                   	nop
  4013fb:	90                   	nop
  4013fc:	90                   	nop
  4013fd:	90                   	nop
  4013fe:	90                   	nop
  4013ff:	90                   	nop

00401400 <_cygwin_premain3>:
  401400:	55                   	push   %ebp
  401401:	89 e5                	mov    %esp,%ebp
  401403:	5d                   	pop    %ebp
  401404:	c3                   	ret    
  401405:	90                   	nop
  401406:	90                   	nop
  401407:	90                   	nop
  401408:	90                   	nop
  401409:	90                   	nop
  40140a:	90                   	nop
  40140b:	90                   	nop
  40140c:	90                   	nop
  40140d:	90                   	nop
  40140e:	90                   	nop
  40140f:	90                   	nop

00401410 <___main>:
  401410:	ff 25 84 50 40 00    	jmp    *0x405084
  401416:	90                   	nop
  401417:	90                   	nop

00401418 <_memcmp>:
  401418:	ff 25 a8 50 40 00    	jmp    *0x4050a8
  40141e:	90                   	nop
  40141f:	90                   	nop

00401420 <_printf>:
  401420:	ff 25 ac 50 40 00    	jmp    *0x4050ac
  401426:	90                   	nop
  401427:	90                   	nop

00401428 <___assert_func>:
  401428:	ff 25 80 50 40 00    	jmp    *0x405080
  40142e:	90                   	nop
  40142f:	90                   	nop

00401430 <__cygwin_crt0_common@8>:
  401430:	55                   	push   %ebp
  401431:	89 e5                	mov    %esp,%ebp
  401433:	56                   	push   %esi
  401434:	53                   	push   %ebx
  401435:	83 ec 10             	sub    $0x10,%esp
  401438:	8b 5d 0c             	mov    0xc(%ebp),%ebx
  40143b:	8b 75 08             	mov    0x8(%ebp),%esi
  40143e:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
  401445:	e8 16 04 00 00       	call   401860 <_cygwin_internal>
  40144a:	85 db                	test   %ebx,%ebx
  40144c:	89 c1                	mov    %eax,%ecx
  40144e:	0f 84 bc 01 00 00    	je     401610 <__cygwin_crt0_common@8+0x1e0>
  401454:	a1 8c 50 40 00       	mov    0x40508c,%eax
  401459:	85 c9                	test   %ecx,%ecx
  40145b:	c7 43 04 a8 00 00 00 	movl   $0xa8,0x4(%ebx)
  401462:	c7 43 08 ef 03 00 00 	movl   $0x3ef,0x8(%ebx)
  401469:	c7 43 0c 09 00 00 00 	movl   $0x9,0xc(%ebx)
  401470:	89 43 10             	mov    %eax,0x10(%ebx)
  401473:	8b 45 00             	mov    0x0(%ebp),%eax
  401476:	c7 83 80 00 00 00 00 	movl   $0x0,0x80(%ebx)
  40147d:	00 00 00 
  401480:	c7 83 84 00 00 00 ed 	movl   $0xed,0x84(%ebx)
  401487:	00 00 00 
  40148a:	c7 43 2c 40 19 40 00 	movl   $0x401940,0x2c(%ebx)
  401491:	c7 43 30 4c 19 40 00 	movl   $0x40194c,0x30(%ebx)
  401498:	c7 43 14 18 40 40 00 	movl   $0x404018,0x14(%ebx)
  40149f:	89 73 28             	mov    %esi,0x28(%ebx)
  4014a2:	c7 43 48 d0 13 40 00 	movl   $0x4013d0,0x48(%ebx)
  4014a9:	c7 43 4c e0 13 40 00 	movl   $0x4013e0,0x4c(%ebx)
  4014b0:	c7 43 50 f0 13 40 00 	movl   $0x4013f0,0x50(%ebx)
  4014b7:	c7 43 54 00 14 40 00 	movl   $0x401400,0x54(%ebx)
  4014be:	c7 43 24 1c 40 40 00 	movl   $0x40401c,0x24(%ebx)
  4014c5:	89 03                	mov    %eax,(%ebx)
  4014c7:	c7 43 18 80 18 40 00 	movl   $0x401880,0x18(%ebx)
  4014ce:	c7 43 1c 88 18 40 00 	movl   $0x401888,0x1c(%ebx)
  4014d5:	c7 43 20 90 18 40 00 	movl   $0x401890,0x20(%ebx)
  4014dc:	c7 43 44 98 18 40 00 	movl   $0x401898,0x44(%ebx)
  4014e3:	0f 84 c1 00 00 00    	je     4015aa <__cygwin_crt0_common@8+0x17a>
  4014e9:	8b 51 78             	mov    0x78(%ecx),%edx
  4014ec:	85 d2                	test   %edx,%edx
  4014ee:	0f 84 b6 00 00 00    	je     4015aa <__cygwin_crt0_common@8+0x17a>
  4014f4:	a1 20 40 40 00       	mov    0x404020,%eax
  4014f9:	85 c0                	test   %eax,%eax
  4014fb:	0f 85 a9 00 00 00    	jne    4015aa <__cygwin_crt0_common@8+0x17a>
  401501:	a1 00 20 40 00       	mov    0x402000,%eax
  401506:	85 c0                	test   %eax,%eax
  401508:	0f 84 12 02 00 00    	je     401720 <__cygwin_crt0_common@8+0x2f0>
  40150e:	a1 04 20 40 00       	mov    0x402004,%eax
  401513:	85 c0                	test   %eax,%eax
  401515:	0f 84 f5 01 00 00    	je     401710 <__cygwin_crt0_common@8+0x2e0>
  40151b:	a1 08 20 40 00       	mov    0x402008,%eax
  401520:	85 c0                	test   %eax,%eax
  401522:	0f 84 d8 01 00 00    	je     401700 <__cygwin_crt0_common@8+0x2d0>
  401528:	a1 0c 20 40 00       	mov    0x40200c,%eax
  40152d:	85 c0                	test   %eax,%eax
  40152f:	0f 84 bb 01 00 00    	je     4016f0 <__cygwin_crt0_common@8+0x2c0>
  401535:	a1 10 20 40 00       	mov    0x402010,%eax
  40153a:	85 c0                	test   %eax,%eax
  40153c:	0f 84 9e 01 00 00    	je     4016e0 <__cygwin_crt0_common@8+0x2b0>
  401542:	8b 35 14 20 40 00    	mov    0x402014,%esi
  401548:	85 f6                	test   %esi,%esi
  40154a:	0f 84 80 01 00 00    	je     4016d0 <__cygwin_crt0_common@8+0x2a0>
  401550:	8b 0d 18 20 40 00    	mov    0x402018,%ecx
  401556:	85 c9                	test   %ecx,%ecx
  401558:	0f 84 62 01 00 00    	je     4016c0 <__cygwin_crt0_common@8+0x290>
  40155e:	a1 1c 20 40 00       	mov    0x40201c,%eax
  401563:	85 c0                	test   %eax,%eax
  401565:	0f 84 47 01 00 00    	je     4016b2 <__cygwin_crt0_common@8+0x282>
  40156b:	a1 00 20 40 00       	mov    0x402000,%eax
  401570:	89 02                	mov    %eax,(%edx)
  401572:	a1 04 20 40 00       	mov    0x402004,%eax
  401577:	89 42 04             	mov    %eax,0x4(%edx)
  40157a:	a1 08 20 40 00       	mov    0x402008,%eax
  40157f:	89 42 08             	mov    %eax,0x8(%edx)
  401582:	a1 0c 20 40 00       	mov    0x40200c,%eax
  401587:	89 42 0c             	mov    %eax,0xc(%edx)
  40158a:	a1 10 20 40 00       	mov    0x402010,%eax
  40158f:	89 42 10             	mov    %eax,0x10(%edx)
  401592:	a1 14 20 40 00       	mov    0x402014,%eax
  401597:	89 42 14             	mov    %eax,0x14(%edx)
  40159a:	a1 18 20 40 00       	mov    0x402018,%eax
  40159f:	89 42 18             	mov    %eax,0x18(%edx)
  4015a2:	a1 1c 20 40 00       	mov    0x40201c,%eax
  4015a7:	89 42 1c             	mov    %eax,0x1c(%edx)
  4015aa:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
  4015b1:	e8 52 03 00 00       	call   401908 <_GetModuleHandleA@4>
  4015b6:	c7 43 34 00 20 40 00 	movl   $0x402000,0x34(%ebx)
  4015bd:	c7 43 38 7c 21 40 00 	movl   $0x40217c,0x38(%ebx)
  4015c4:	c7 43 3c 00 40 40 00 	movl   $0x404000,0x3c(%ebx)
  4015cb:	c7 43 40 28 41 40 00 	movl   $0x404128,0x40(%ebx)
  4015d2:	c7 83 94 00 00 00 00 	movl   $0x403000,0x94(%ebx)
  4015d9:	30 40 00 
  4015dc:	89 43 7c             	mov    %eax,0x7c(%ebx)
  4015df:	83 ec 04             	sub    $0x4,%esp
  4015e2:	c7 83 98 00 00 00 00 	movl   $0x403000,0x98(%ebx)
  4015e9:	30 40 00 
  4015ec:	c7 83 9c 00 00 00 00 	movl   $0x400000,0x9c(%ebx)
  4015f3:	00 40 00 
  4015f6:	e8 75 02 00 00       	call   401870 <__pei386_runtime_relocator>
  4015fb:	8d 65 f8             	lea    -0x8(%ebp),%esp
  4015fe:	b8 01 00 00 00       	mov    $0x1,%eax
  401603:	5b                   	pop    %ebx
  401604:	5e                   	pop    %esi
  401605:	5d                   	pop    %ebp
  401606:	c2 08 00             	ret    $0x8
  401609:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  401610:	c7 40 04 a8 00 00 00 	movl   $0xa8,0x4(%eax)
  401617:	8b 15 8c 50 40 00    	mov    0x40508c,%edx
  40161d:	85 c9                	test   %ecx,%ecx
  40161f:	c7 40 08 ef 03 00 00 	movl   $0x3ef,0x8(%eax)
  401626:	89 cb                	mov    %ecx,%ebx
  401628:	c7 40 0c 09 00 00 00 	movl   $0x9,0xc(%eax)
  40162f:	c7 80 80 00 00 00 00 	movl   $0x0,0x80(%eax)
  401636:	00 00 00 
  401639:	c7 80 84 00 00 00 ed 	movl   $0xed,0x84(%eax)
  401640:	00 00 00 
  401643:	c7 40 2c 40 19 40 00 	movl   $0x401940,0x2c(%eax)
  40164a:	c7 40 30 4c 19 40 00 	movl   $0x40194c,0x30(%eax)
  401651:	c7 40 14 18 40 40 00 	movl   $0x404018,0x14(%eax)
  401658:	8b 80 a4 00 00 00    	mov    0xa4(%eax),%eax
  40165e:	89 71 28             	mov    %esi,0x28(%ecx)
  401661:	c7 41 48 d0 13 40 00 	movl   $0x4013d0,0x48(%ecx)
  401668:	c7 41 4c e0 13 40 00 	movl   $0x4013e0,0x4c(%ecx)
  40166f:	89 02                	mov    %eax,(%edx)
  401671:	8b 45 00             	mov    0x0(%ebp),%eax
  401674:	c7 41 50 f0 13 40 00 	movl   $0x4013f0,0x50(%ecx)
  40167b:	c7 41 54 00 14 40 00 	movl   $0x401400,0x54(%ecx)
  401682:	c7 41 24 1c 40 40 00 	movl   $0x40401c,0x24(%ecx)
  401689:	89 01                	mov    %eax,(%ecx)
  40168b:	c7 41 18 80 18 40 00 	movl   $0x401880,0x18(%ecx)
  401692:	c7 41 1c 88 18 40 00 	movl   $0x401888,0x1c(%ecx)
  401699:	c7 41 20 90 18 40 00 	movl   $0x401890,0x20(%ecx)
  4016a0:	c7 41 44 98 18 40 00 	movl   $0x401898,0x44(%ecx)
  4016a7:	0f 85 3c fe ff ff    	jne    4014e9 <__cygwin_crt0_common@8+0xb9>
  4016ad:	e9 f8 fe ff ff       	jmp    4015aa <__cygwin_crt0_common@8+0x17a>
  4016b2:	8b 42 1c             	mov    0x1c(%edx),%eax
  4016b5:	a3 1c 20 40 00       	mov    %eax,0x40201c
  4016ba:	e9 ac fe ff ff       	jmp    40156b <__cygwin_crt0_common@8+0x13b>
  4016bf:	90                   	nop
  4016c0:	8b 42 18             	mov    0x18(%edx),%eax
  4016c3:	a3 18 20 40 00       	mov    %eax,0x402018
  4016c8:	e9 91 fe ff ff       	jmp    40155e <__cygwin_crt0_common@8+0x12e>
  4016cd:	8d 76 00             	lea    0x0(%esi),%esi
  4016d0:	8b 42 14             	mov    0x14(%edx),%eax
  4016d3:	a3 14 20 40 00       	mov    %eax,0x402014
  4016d8:	e9 73 fe ff ff       	jmp    401550 <__cygwin_crt0_common@8+0x120>
  4016dd:	8d 76 00             	lea    0x0(%esi),%esi
  4016e0:	8b 42 10             	mov    0x10(%edx),%eax
  4016e3:	a3 10 20 40 00       	mov    %eax,0x402010
  4016e8:	e9 55 fe ff ff       	jmp    401542 <__cygwin_crt0_common@8+0x112>
  4016ed:	8d 76 00             	lea    0x0(%esi),%esi
  4016f0:	8b 42 0c             	mov    0xc(%edx),%eax
  4016f3:	a3 0c 20 40 00       	mov    %eax,0x40200c
  4016f8:	e9 38 fe ff ff       	jmp    401535 <__cygwin_crt0_common@8+0x105>
  4016fd:	8d 76 00             	lea    0x0(%esi),%esi
  401700:	8b 42 08             	mov    0x8(%edx),%eax
  401703:	a3 08 20 40 00       	mov    %eax,0x402008
  401708:	e9 1b fe ff ff       	jmp    401528 <__cygwin_crt0_common@8+0xf8>
  40170d:	8d 76 00             	lea    0x0(%esi),%esi
  401710:	8b 42 04             	mov    0x4(%edx),%eax
  401713:	a3 04 20 40 00       	mov    %eax,0x402004
  401718:	e9 fe fd ff ff       	jmp    40151b <__cygwin_crt0_common@8+0xeb>
  40171d:	8d 76 00             	lea    0x0(%esi),%esi
  401720:	8b 02                	mov    (%edx),%eax
  401722:	a3 00 20 40 00       	mov    %eax,0x402000
  401727:	e9 e2 fd ff ff       	jmp    40150e <__cygwin_crt0_common@8+0xde>
  40172c:	90                   	nop
  40172d:	90                   	nop
  40172e:	90                   	nop
  40172f:	90                   	nop

00401730 <___dllMain>:
  401730:	55                   	push   %ebp
  401731:	89 e5                	mov    %esp,%ebp
  401733:	83 ec 18             	sub    $0x18,%esp
  401736:	a1 48 40 40 00       	mov    0x404048,%eax
  40173b:	89 44 24 08          	mov    %eax,0x8(%esp)
  40173f:	a1 38 40 40 00       	mov    0x404038,%eax
  401744:	89 44 24 04          	mov    %eax,0x4(%esp)
  401748:	a1 28 40 40 00       	mov    0x404028,%eax
  40174d:	89 04 24             	mov    %eax,(%esp)
  401750:	e8 9b 01 00 00       	call   4018f0 <_DllMain@12>
  401755:	83 ec 0c             	sub    $0xc,%esp
  401758:	c9                   	leave  
  401759:	c3                   	ret    
  40175a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi

00401760 <__cygwin_dll_entry@12>:
  401760:	55                   	push   %ebp
  401761:	89 e5                	mov    %esp,%ebp
  401763:	53                   	push   %ebx
  401764:	83 ec 14             	sub    $0x14,%esp
  401767:	8b 45 0c             	mov    0xc(%ebp),%eax
  40176a:	8b 4d 08             	mov    0x8(%ebp),%ecx
  40176d:	8b 55 10             	mov    0x10(%ebp),%edx
  401770:	83 f8 01             	cmp    $0x1,%eax
  401773:	0f 84 87 00 00 00    	je     401800 <__cygwin_dll_entry@12+0xa0>
  401779:	72 18                	jb     401793 <__cygwin_dll_entry@12+0x33>
  40177b:	83 f8 02             	cmp    $0x2,%eax
  40177e:	74 66                	je     4017e6 <__cygwin_dll_entry@12+0x86>
  401780:	83 f8 03             	cmp    $0x3,%eax
  401783:	bb 01 00 00 00       	mov    $0x1,%ebx
  401788:	74 46                	je     4017d0 <__cygwin_dll_entry@12+0x70>
  40178a:	89 d8                	mov    %ebx,%eax
  40178c:	8b 5d fc             	mov    -0x4(%ebp),%ebx
  40178f:	c9                   	leave  
  401790:	c2 0c 00             	ret    $0xc
  401793:	89 54 24 08          	mov    %edx,0x8(%esp)
  401797:	c7 44 24 04 00 00 00 	movl   $0x0,0x4(%esp)
  40179e:	00 
  40179f:	89 0c 24             	mov    %ecx,(%esp)
  4017a2:	e8 49 01 00 00       	call   4018f0 <_DllMain@12>
  4017a7:	83 ec 0c             	sub    $0xc,%esp
  4017aa:	85 c0                	test   %eax,%eax
  4017ac:	89 c3                	mov    %eax,%ebx
  4017ae:	74 da                	je     40178a <__cygwin_dll_entry@12+0x2a>
  4017b0:	a1 58 40 40 00       	mov    0x404058,%eax
  4017b5:	89 04 24             	mov    %eax,(%esp)
  4017b8:	e8 23 01 00 00       	call   4018e0 <_cygwin_detach_dll>
  4017bd:	c7 05 58 40 40 00 ff 	movl   $0xffffffff,0x404058
  4017c4:	ff ff ff 
  4017c7:	eb c1                	jmp    40178a <__cygwin_dll_entry@12+0x2a>
  4017c9:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
  4017d0:	89 55 10             	mov    %edx,0x10(%ebp)
  4017d3:	8b 5d fc             	mov    -0x4(%ebp),%ebx
  4017d6:	c7 45 0c 03 00 00 00 	movl   $0x3,0xc(%ebp)
  4017dd:	89 4d 08             	mov    %ecx,0x8(%ebp)
  4017e0:	c9                   	leave  
  4017e1:	e9 0a 01 00 00       	jmp    4018f0 <_DllMain@12>
  4017e6:	89 55 10             	mov    %edx,0x10(%ebp)
  4017e9:	8b 5d fc             	mov    -0x4(%ebp),%ebx
  4017ec:	c7 45 0c 02 00 00 00 	movl   $0x2,0xc(%ebp)
  4017f3:	89 4d 08             	mov    %ecx,0x8(%ebp)
  4017f6:	c9                   	leave  
  4017f7:	e9 f4 00 00 00       	jmp    4018f0 <_DllMain@12>
  4017fc:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
  401800:	31 c0                	xor    %eax,%eax
  401802:	85 d2                	test   %edx,%edx
  401804:	0f 94 c0             	sete   %al
  401807:	31 db                	xor    %ebx,%ebx
  401809:	89 0d 28 40 40 00    	mov    %ecx,0x404028
  40180f:	c7 05 38 40 40 00 01 	movl   $0x1,0x404038
  401816:	00 00 00 
  401819:	89 15 48 40 40 00    	mov    %edx,0x404048
  40181f:	a3 20 40 40 00       	mov    %eax,0x404020
  401824:	c7 44 24 04 30 17 40 	movl   $0x401730,0x4(%esp)
  40182b:	00 
  40182c:	89 0c 24             	mov    %ecx,(%esp)
  40182f:	e8 6c 00 00 00       	call   4018a0 <_cygwin_attach_dll>
  401834:	83 f8 ff             	cmp    $0xffffffff,%eax
  401837:	0f 95 c3             	setne  %bl
  40183a:	a3 58 40 40 00       	mov    %eax,0x404058
  40183f:	89 d8                	mov    %ebx,%eax
  401841:	8b 5d fc             	mov    -0x4(%ebp),%ebx
  401844:	c9                   	leave  
  401845:	c2 0c 00             	ret    $0xc
  401848:	90                   	nop
  401849:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi

00401850 <__cygwin_noncygwin_dll_entry@12>:
  401850:	55                   	push   %ebp
  401851:	89 e5                	mov    %esp,%ebp
  401853:	c9                   	leave  
  401854:	e9 07 ff ff ff       	jmp    401760 <__cygwin_dll_entry@12>
  401859:	90                   	nop
  40185a:	90                   	nop
  40185b:	90                   	nop
  40185c:	90                   	nop
  40185d:	90                   	nop
  40185e:	90                   	nop
  40185f:	90                   	nop

00401860 <_cygwin_internal>:
  401860:	ff 25 98 50 40 00    	jmp    *0x405098
  401866:	90                   	nop
  401867:	90                   	nop
	...

00401870 <__pei386_runtime_relocator>:
  401870:	55                   	push   %ebp
  401871:	89 e5                	mov    %esp,%ebp
  401873:	5d                   	pop    %ebp
  401874:	c3                   	ret    
  401875:	90                   	nop
  401876:	90                   	nop
  401877:	90                   	nop
  401878:	90                   	nop
  401879:	90                   	nop
  40187a:	90                   	nop
  40187b:	90                   	nop
  40187c:	90                   	nop
  40187d:	90                   	nop
  40187e:	90                   	nop
  40187f:	90                   	nop

00401880 <_malloc>:
  401880:	ff 25 a4 50 40 00    	jmp    *0x4050a4
  401886:	90                   	nop
  401887:	90                   	nop

00401888 <_free>:
  401888:	ff 25 a0 50 40 00    	jmp    *0x4050a0
  40188e:	90                   	nop
  40188f:	90                   	nop

00401890 <_realloc>:
  401890:	ff 25 b0 50 40 00    	jmp    *0x4050b0
  401896:	90                   	nop
  401897:	90                   	nop

00401898 <_calloc>:
  401898:	ff 25 90 50 40 00    	jmp    *0x405090
  40189e:	90                   	nop
  40189f:	90                   	nop

004018a0 <_cygwin_attach_dll>:
  4018a0:	55                   	push   %ebp
  4018a1:	89 e5                	mov    %esp,%ebp
  4018a3:	53                   	push   %ebx
  4018a4:	83 ec 14             	sub    $0x14,%esp
  4018a7:	8b 5d 08             	mov    0x8(%ebp),%ebx
  4018aa:	c7 44 24 04 68 40 40 	movl   $0x404068,0x4(%esp)
  4018b1:	00 
  4018b2:	8b 45 0c             	mov    0xc(%ebp),%eax
  4018b5:	89 04 24             	mov    %eax,(%esp)
  4018b8:	e8 73 fb ff ff       	call   401430 <__cygwin_crt0_common@8>
  4018bd:	89 5d 08             	mov    %ebx,0x8(%ebp)
  4018c0:	8b 5d fc             	mov    -0x4(%ebp),%ebx
  4018c3:	c7 45 0c 68 40 40 00 	movl   $0x404068,0xc(%ebp)
  4018ca:	83 ec 08             	sub    $0x8,%esp
  4018cd:	c9                   	leave  
  4018ce:	e9 2d 00 00 00       	jmp    401900 <_dll_dllcrt0>
  4018d3:	90                   	nop
  4018d4:	90                   	nop
  4018d5:	90                   	nop
  4018d6:	90                   	nop
  4018d7:	90                   	nop
  4018d8:	90                   	nop
  4018d9:	90                   	nop
  4018da:	90                   	nop
  4018db:	90                   	nop
  4018dc:	90                   	nop
  4018dd:	90                   	nop
  4018de:	90                   	nop
  4018df:	90                   	nop

004018e0 <_cygwin_detach_dll>:
  4018e0:	ff 25 94 50 40 00    	jmp    *0x405094
  4018e6:	90                   	nop
  4018e7:	90                   	nop
	...

004018f0 <_DllMain@12>:
  4018f0:	55                   	push   %ebp
  4018f1:	b8 01 00 00 00       	mov    $0x1,%eax
  4018f6:	89 e5                	mov    %esp,%ebp
  4018f8:	5d                   	pop    %ebp
  4018f9:	c2 0c 00             	ret    $0xc
  4018fc:	90                   	nop
  4018fd:	90                   	nop
  4018fe:	90                   	nop
  4018ff:	90                   	nop

00401900 <_dll_dllcrt0>:
  401900:	ff 25 9c 50 40 00    	jmp    *0x40509c
  401906:	90                   	nop
  401907:	90                   	nop

00401908 <_GetModuleHandleA@4>:
  401908:	ff 25 b8 50 40 00    	jmp    *0x4050b8
  40190e:	90                   	nop
  40190f:	90                   	nop

00401910 <_GetProcAddress@8>:
  401910:	ff 25 bc 50 40 00    	jmp    *0x4050bc
  401916:	90                   	nop
  401917:	90                   	nop

00401918 <.text>:
	...

00401920 <_register_frame_ctor>:
  401920:	55                   	push   %ebp
  401921:	89 e5                	mov    %esp,%ebp
  401923:	83 ec 08             	sub    $0x8,%esp
  401926:	c9                   	leave  
  401927:	e9 64 f7 ff ff       	jmp    401090 <___gcc_register_frame>
  40192c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi

00401930 <_deregister_frame_dtor>:
  401930:	55                   	push   %ebp
  401931:	89 e5                	mov    %esp,%ebp
  401933:	83 ec 08             	sub    $0x8,%esp
  401936:	c9                   	leave  
  401937:	e9 e4 f7 ff ff       	jmp    401120 <___gcc_deregister_frame>
  40193c:	90                   	nop
  40193d:	90                   	nop
  40193e:	90                   	nop
  40193f:	90                   	nop

00401940 <__CTOR_LIST__>:
  401940:	ff                   	(bad)  
  401941:	ff                   	(bad)  
  401942:	ff                   	(bad)  
  401943:	ff 20                	jmp    *(%eax)

00401944 <.ctors.65535>:
  401944:	20 19                	and    %bl,(%ecx)
  401946:	40                   	inc    %eax
  401947:	00 00                	add    %al,(%eax)
  401949:	00 00                	add    %al,(%eax)
	...

0040194c <__DTOR_LIST__>:
  40194c:	ff                   	(bad)  
  40194d:	ff                   	(bad)  
  40194e:	ff                   	(bad)  
  40194f:	ff 30                	pushl  (%eax)

00401950 <.dtors.65535>:
  401950:	30 19                	xor    %bl,(%ecx)
  401952:	40                   	inc    %eax
  401953:	00 00                	add    %al,(%eax)
  401955:	00 00                	add    %al,(%eax)
	...
