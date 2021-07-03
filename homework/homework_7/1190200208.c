#include <math.h>
#include <stdio.h>

// CSAPP - 第七章作业

// 7.7
/* bar5.c */
/*
void f()
{
    double x;
    x=-0.0;
}
*/

// 7.9
/*
在p2中，main是弱符号，而foo6.c中的main函数是强符号，故在链接后， 引用的是foo6.c中的main函数。故在打印时，实际打印main函数汇编代码的第一个字节。
查看main函数汇编代码，可知其打印push %rbp对应的字节。在我的电脑上，其显示为0x55
*/


// 7.11
/* 
剩下的8个字节是为了对.bss data作出响应，在程序运行时，其被初始化为0
*/

// 7.13 好像不用做？
/*
A.libc.a包含1690个文件，libm.a包含471个文件
B.经linux环境下检验，gcc-Og与gcc-Og-g产生代码不一样
C.linux-vdso.so.1 (0x00007ffecebfc000)
  libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f659bb3a000)
  /lib64/ld-linux-x86-64.so.2 (0x00007f659bf2b000)
*/

