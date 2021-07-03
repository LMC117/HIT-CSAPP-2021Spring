
hello：     文件格式 elf64-x86-64


Disassembly of section .init:

0000000000400488 <_init>:
  400488:	48 83 ec 08          	sub    $0x8,%rsp
  40048c:	48 8b 05 65 0b 20 00 	mov    0x200b65(%rip),%rax        # 600ff8 <__gmon_start__>
  400493:	48 85 c0             	test   %rax,%rax
  400496:	74 02                	je     40049a <_init+0x12>
  400498:	ff d0                	callq  *%rax
  40049a:	48 83 c4 08          	add    $0x8,%rsp
  40049e:	c3                   	retq   

Disassembly of section .plt:

00000000004004a0 <.plt>:
  4004a0:	ff 35 62 0b 20 00    	pushq  0x200b62(%rip)        # 601008 <_GLOBAL_OFFSET_TABLE_+0x8>
  4004a6:	ff 25 64 0b 20 00    	jmpq   *0x200b64(%rip)        # 601010 <_GLOBAL_OFFSET_TABLE_+0x10>
  4004ac:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004004b0 <puts@plt>:
  4004b0:	ff 25 62 0b 20 00    	jmpq   *0x200b62(%rip)        # 601018 <puts@GLIBC_2.2.5>
  4004b6:	68 00 00 00 00       	pushq  $0x0
  4004bb:	e9 e0 ff ff ff       	jmpq   4004a0 <.plt>

00000000004004c0 <printf@plt>:
  4004c0:	ff 25 5a 0b 20 00    	jmpq   *0x200b5a(%rip)        # 601020 <printf@GLIBC_2.2.5>
  4004c6:	68 01 00 00 00       	pushq  $0x1
  4004cb:	e9 d0 ff ff ff       	jmpq   4004a0 <.plt>

00000000004004d0 <getchar@plt>:
  4004d0:	ff 25 52 0b 20 00    	jmpq   *0x200b52(%rip)        # 601028 <getchar@GLIBC_2.2.5>
  4004d6:	68 02 00 00 00       	pushq  $0x2
  4004db:	e9 c0 ff ff ff       	jmpq   4004a0 <.plt>

00000000004004e0 <exit@plt>:
  4004e0:	ff 25 4a 0b 20 00    	jmpq   *0x200b4a(%rip)        # 601030 <exit@GLIBC_2.2.5>
  4004e6:	68 03 00 00 00       	pushq  $0x3
  4004eb:	e9 b0 ff ff ff       	jmpq   4004a0 <.plt>

00000000004004f0 <sleep@plt>:
  4004f0:	ff 25 42 0b 20 00    	jmpq   *0x200b42(%rip)        # 601038 <sleep@GLIBC_2.2.5>
  4004f6:	68 04 00 00 00       	pushq  $0x4
  4004fb:	e9 a0 ff ff ff       	jmpq   4004a0 <.plt>

Disassembly of section .text:

0000000000400500 <_start>:
  400500:	31 ed                	xor    %ebp,%ebp
  400502:	49 89 d1             	mov    %rdx,%r9
  400505:	5e                   	pop    %rsi
  400506:	48 89 e2             	mov    %rsp,%rdx
  400509:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  40050d:	50                   	push   %rax
  40050e:	54                   	push   %rsp
  40050f:	49 c7 c0 e0 06 40 00 	mov    $0x4006e0,%r8
  400516:	48 c7 c1 70 06 40 00 	mov    $0x400670,%rcx
  40051d:	48 c7 c7 e7 05 40 00 	mov    $0x4005e7,%rdi
  400524:	ff 15 c6 0a 20 00    	callq  *0x200ac6(%rip)        # 600ff0 <__libc_start_main@GLIBC_2.2.5>
  40052a:	f4                   	hlt    
  40052b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000400530 <_dl_relocate_static_pie>:
  400530:	f3 c3                	repz retq 
  400532:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  400539:	00 00 00 
  40053c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000400540 <deregister_tm_clones>:
  400540:	55                   	push   %rbp
  400541:	b8 58 10 60 00       	mov    $0x601058,%eax
  400546:	48 3d 58 10 60 00    	cmp    $0x601058,%rax
  40054c:	48 89 e5             	mov    %rsp,%rbp
  40054f:	74 17                	je     400568 <deregister_tm_clones+0x28>
  400551:	b8 00 00 00 00       	mov    $0x0,%eax
  400556:	48 85 c0             	test   %rax,%rax
  400559:	74 0d                	je     400568 <deregister_tm_clones+0x28>
  40055b:	5d                   	pop    %rbp
  40055c:	bf 58 10 60 00       	mov    $0x601058,%edi
  400561:	ff e0                	jmpq   *%rax
  400563:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  400568:	5d                   	pop    %rbp
  400569:	c3                   	retq   
  40056a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000400570 <register_tm_clones>:
  400570:	be 58 10 60 00       	mov    $0x601058,%esi
  400575:	55                   	push   %rbp
  400576:	48 81 ee 58 10 60 00 	sub    $0x601058,%rsi
  40057d:	48 89 e5             	mov    %rsp,%rbp
  400580:	48 c1 fe 03          	sar    $0x3,%rsi
  400584:	48 89 f0             	mov    %rsi,%rax
  400587:	48 c1 e8 3f          	shr    $0x3f,%rax
  40058b:	48 01 c6             	add    %rax,%rsi
  40058e:	48 d1 fe             	sar    %rsi
  400591:	74 15                	je     4005a8 <register_tm_clones+0x38>
  400593:	b8 00 00 00 00       	mov    $0x0,%eax
  400598:	48 85 c0             	test   %rax,%rax
  40059b:	74 0b                	je     4005a8 <register_tm_clones+0x38>
  40059d:	5d                   	pop    %rbp
  40059e:	bf 58 10 60 00       	mov    $0x601058,%edi
  4005a3:	ff e0                	jmpq   *%rax
  4005a5:	0f 1f 00             	nopl   (%rax)
  4005a8:	5d                   	pop    %rbp
  4005a9:	c3                   	retq   
  4005aa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000004005b0 <__do_global_dtors_aux>:
  4005b0:	80 3d 9d 0a 20 00 00 	cmpb   $0x0,0x200a9d(%rip)        # 601054 <_edata>
  4005b7:	75 17                	jne    4005d0 <__do_global_dtors_aux+0x20>
  4005b9:	55                   	push   %rbp
  4005ba:	48 89 e5             	mov    %rsp,%rbp
  4005bd:	e8 7e ff ff ff       	callq  400540 <deregister_tm_clones>
  4005c2:	c6 05 8b 0a 20 00 01 	movb   $0x1,0x200a8b(%rip)        # 601054 <_edata>
  4005c9:	5d                   	pop    %rbp
  4005ca:	c3                   	retq   
  4005cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  4005d0:	f3 c3                	repz retq 
  4005d2:	0f 1f 40 00          	nopl   0x0(%rax)
  4005d6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4005dd:	00 00 00 

00000000004005e0 <frame_dummy>:
  4005e0:	55                   	push   %rbp
  4005e1:	48 89 e5             	mov    %rsp,%rbp
  4005e4:	5d                   	pop    %rbp
  4005e5:	eb 89                	jmp    400570 <register_tm_clones>

00000000004005e7 <main>:
  4005e7:	55                   	push   %rbp
  4005e8:	48 89 e5             	mov    %rsp,%rbp
  4005eb:	48 83 ec 20          	sub    $0x20,%rsp
  4005ef:	89 7d ec             	mov    %edi,-0x14(%rbp)
  4005f2:	48 89 75 e0          	mov    %rsi,-0x20(%rbp)
  4005f6:	83 7d ec 03          	cmpl   $0x3,-0x14(%rbp)
  4005fa:	74 14                	je     400610 <main+0x29>
  4005fc:	bf f4 06 40 00       	mov    $0x4006f4,%edi
  400601:	e8 aa fe ff ff       	callq  4004b0 <puts@plt>
  400606:	bf 01 00 00 00       	mov    $0x1,%edi
  40060b:	e8 d0 fe ff ff       	callq  4004e0 <exit@plt>
  400610:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
  400617:	eb 39                	jmp    400652 <main+0x6b>
  400619:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  40061d:	48 83 c0 10          	add    $0x10,%rax
  400621:	48 8b 10             	mov    (%rax),%rdx
  400624:	48 8b 45 e0          	mov    -0x20(%rbp),%rax
  400628:	48 83 c0 08          	add    $0x8,%rax
  40062c:	48 8b 00             	mov    (%rax),%rax
  40062f:	48 89 c6             	mov    %rax,%rsi
  400632:	bf 12 07 40 00       	mov    $0x400712,%edi
  400637:	b8 00 00 00 00       	mov    $0x0,%eax
  40063c:	e8 7f fe ff ff       	callq  4004c0 <printf@plt>
  400641:	8b 05 09 0a 20 00    	mov    0x200a09(%rip),%eax        # 601050 <sleepsecs>
  400647:	89 c7                	mov    %eax,%edi
  400649:	e8 a2 fe ff ff       	callq  4004f0 <sleep@plt>
  40064e:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
  400652:	83 7d fc 09          	cmpl   $0x9,-0x4(%rbp)
  400656:	7e c1                	jle    400619 <main+0x32>
  400658:	e8 73 fe ff ff       	callq  4004d0 <getchar@plt>
  40065d:	b8 00 00 00 00       	mov    $0x0,%eax
  400662:	c9                   	leaveq 
  400663:	c3                   	retq   
  400664:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40066b:	00 00 00 
  40066e:	66 90                	xchg   %ax,%ax

0000000000400670 <__libc_csu_init>:
  400670:	41 57                	push   %r15
  400672:	41 56                	push   %r14
  400674:	49 89 d7             	mov    %rdx,%r15
  400677:	41 55                	push   %r13
  400679:	41 54                	push   %r12
  40067b:	4c 8d 25 7e 07 20 00 	lea    0x20077e(%rip),%r12        # 600e00 <__frame_dummy_init_array_entry>
  400682:	55                   	push   %rbp
  400683:	48 8d 2d 7e 07 20 00 	lea    0x20077e(%rip),%rbp        # 600e08 <__init_array_end>
  40068a:	53                   	push   %rbx
  40068b:	41 89 fd             	mov    %edi,%r13d
  40068e:	49 89 f6             	mov    %rsi,%r14
  400691:	4c 29 e5             	sub    %r12,%rbp
  400694:	48 83 ec 08          	sub    $0x8,%rsp
  400698:	48 c1 fd 03          	sar    $0x3,%rbp
  40069c:	e8 e7 fd ff ff       	callq  400488 <_init>
  4006a1:	48 85 ed             	test   %rbp,%rbp
  4006a4:	74 20                	je     4006c6 <__libc_csu_init+0x56>
  4006a6:	31 db                	xor    %ebx,%ebx
  4006a8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  4006af:	00 
  4006b0:	4c 89 fa             	mov    %r15,%rdx
  4006b3:	4c 89 f6             	mov    %r14,%rsi
  4006b6:	44 89 ef             	mov    %r13d,%edi
  4006b9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
  4006bd:	48 83 c3 01          	add    $0x1,%rbx
  4006c1:	48 39 dd             	cmp    %rbx,%rbp
  4006c4:	75 ea                	jne    4006b0 <__libc_csu_init+0x40>
  4006c6:	48 83 c4 08          	add    $0x8,%rsp
  4006ca:	5b                   	pop    %rbx
  4006cb:	5d                   	pop    %rbp
  4006cc:	41 5c                	pop    %r12
  4006ce:	41 5d                	pop    %r13
  4006d0:	41 5e                	pop    %r14
  4006d2:	41 5f                	pop    %r15
  4006d4:	c3                   	retq   
  4006d5:	90                   	nop
  4006d6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4006dd:	00 00 00 

00000000004006e0 <__libc_csu_fini>:
  4006e0:	f3 c3                	repz retq 

Disassembly of section .fini:

00000000004006e4 <_fini>:
  4006e4:	48 83 ec 08          	sub    $0x8,%rsp
  4006e8:	48 83 c4 08          	add    $0x8,%rsp
  4006ec:	c3                   	retq   
