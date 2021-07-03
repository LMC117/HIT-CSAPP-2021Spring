#include <math.h>
#include <stdio.h>

// CSAPP - 第三章作业

// 3.59
/*
    dest in %rdi, x in %rsi, y in %rdx

  stroe_prod:
    movq %rdx, %rax    // %rax = y, 此时y_l = %rax
    cqto               // 设置%rdx为y的符号位,此时y_h = %rdx（全0或-1即ffffffff）
    movq %rsi, %rcx    // 将x的值赋给%rcx，为下一行获取x的符号
    sarq $63, %rcx     // %rcx为x的符号位拓展（0或-1）x_h = %rcx
    imulq %rax, %rcx   // 计算y_l * x_h，作为高位的一部分
    imulq %rsi, %rdx   // 计算y_h * x_l，作为高位的一部分
    addq %rdx, %rcx    // 计算x_h * y_l + x_l * y_h
    mulq %rsi          // 该命令是计算x_l * y_l的值，此时%rax中保存着乘积低64位值，而%rdx中保存着高64位值（算作高位的一部分）
    addq %rcx, %rdx    // 得到最终高位的值，其由三部分构成：y_l * x_h，y_h * x_l，以及x_l * y_l的高64位部分
    movq %rax, (%rdi)  // 将低64位保存在dest的地址
    movq %rdx, 8(%rdi) // 将高64位保存在dest+8的地址
    ret
*/

// 3.61
long cread_alt(long *xp)
{
    long v = 0;
    long *p = xp ? xp : &v;
    return p;
}

// 3.63
long switch_prob(long x, long n)
{
    long result = x;
    switch (n)
    {
    case 60:
    case 62:
        result *= 8;
        break;
    case 63:
        result >>= 3;
        break;
    case 64:
        result <<= 4;
        result -= x;
        result *= result;
        result += 0x4b;
        break;
    case 65:
        result = x * x;
    case 61:
    default:
        result += 0x4b;
        break;
    }
    return result;
}

// 3.65
/*
A.rdx
B.rax
C.15
*/

// 3.67
/*
A.
    104	--------------------
		|				   |
		|				   |
		|				   |
		|                  |
		|				   |
    64  --------------------  ----→ %rdi
	    |				   |
		|				   |
		|				   |
		|				   |
	32  --------------------
		|		 z		   |
	24	--------------------
		|	&z   (s.p)     |
	16	--------------------
		|	y   (s.a[1])   |
	 8	--------------------
		|   x   (s.a[0])   |
	 0	--------------------  ----→ %rsp
B.
地址 %rsp + 64
C.
通过%rsp做基地址，加上偏移量的方式访问
D.
将获得的s元素值mov到对应的区域，对应区域通过%rdi做基地址，加上偏移量的方式访问
E.
    104	--------------------
		|				   |
		|				   |
	88	--------------------
		|	z     (r.q)    |
	80	--------------------  
		|   x   (r.u[1])   |
	72	--------------------  
		|	y   (r.u[0])   |
	64  --------------------  
		|				   |
		|				   |
		|				   |
		|				   |
	32  --------------------
		|		 z		   |
	24	--------------------
		|	&z   (s.p)     |
	16	--------------------
		|	y   (s.a[1])   |
	 8	--------------------
		|   x   (s.a[0])   |
	 0	--------------------  
		|	eval的返回地址  |
	-8	--------------------  ----→ %rsp
    从process返回后，eval仍通过%rsp做基地址，加上偏移量的方式访问
F.
结构体作为参数传入函数及返回时，都是以指针形式传递的
*/

// 3.69
/*
A.7
B.
typedef struct
{
    int idx;
    long x[4];
} a_struct;
*/

// 3.71
void good_echo()
{
    const int size = 8;
    char str[8];
    int i;
    while (fgets(str, size, stdin) != NULL)
    {
        for (i = 0; str[i]; i++)
            putchar(str[i]);
        if (i < size - 1)
            break;
    }
    return;
}

int main()
{
    return 0;
}