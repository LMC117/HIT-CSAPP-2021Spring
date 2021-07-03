#include <math.h>
#include <stdio.h>

// CSAPP - 第四章作业

// 4.45

/*
A.
这段代码没有正确描述 pushq %rsp 的行为。
因为对栈寄存器进行压栈操作时，压入的应是%rsp的原始值，而非减去8以后的%rsp值。
B.
movq REG,-0x8(%rsp)
subq $8,%rsp
*/

// 4.46

/*
A.
这段代码没有正确描述 popq %rsp 的行为。
因为对栈寄存器进行弹栈操作时，应是将%rsp置为内存中读出的值，而非增加增量后的栈指针。
B.
addq $8,%rsp
movq -0x8(%rsp),REG
*/

// 4.51

/*
iaddq V,rB
取指：
icode: ifun <- M1[PC]
rA:rB <- M1[PC+1]
valC <- M8[Pc+2]
valP <- PC+10
译码：
valB <- R[rB]
执行：
valE <- valB + valC
访存：
no action.
写回：
R[rB] <- valE
更新PC：
PC <- valP
*/