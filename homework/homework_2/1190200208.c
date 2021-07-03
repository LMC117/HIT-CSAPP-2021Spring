#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2.59
void Q_2_59()
{
    int x = 0x89ABCDEF;
    int y = 0x76543210;
    int a = x & 0xFF; // 按位操作，只保留a的后两位
    int b = y & 0xFFFFFF00;
    printf("2.59：%#x\n", a + b);
}

// 2.63
unsigned srl(unsigned x, int k) // 用算术右移完成逻辑右移
{
    unsigned xsra = (int)x >> k; // x算数右移k位(补k个最高位)
    int len = 8 * sizeof(int);
    // 将高k位变成0
    xsra &= ~(0xFFFFFFFF << (len - k));
    return xsra;
}

int sra(int x, int k) // 用逻辑右移完成算数右移
{
    int xsrl = (unsigned)x >> k; // x逻辑右移k位(补k个0)
    int len = 8 * sizeof(int);
    //高位补了k个0，现验证高→低第k+1位，若其为1，则高k位变1
    int t = xsrl & (0x1 << (len - 1 - k));
    t = -t;                            // 若原数最高位为1,变换后t就为0xFFFFFFFF；若原数最高位为0,变换后t仍为0x00000000；
    xsrl |= (t << (len - k)); // 将高k位变成1
    return xsrl;
}

// 2.67
/*
2.67 A : 移位次数大于了机器的位数
*/
int int_size_is_32()
{
    int set_msb = 1 << 31;    // 32位机上set_msb >= 0
    int beyond_msb = 2 << 31; // 32位机上beyond_msb <= 0
    return set_msb && !beyond_msb;
}

int int_size_is_32_16()
{
    int t = 0x8000 << 15;
    int set_msb = t << 1;    // 32位机上set_msb >= 0
    int beyond_msb = t << 2; // 32位机上beyond_msb <= 0
    return set_msb && !beyond_msb;
}

// 2.71
/*
2.71 A : 最终得到的结果并非int型，应该先将取出的字符移到最高位，再进行算术右移操作
*/
typedef unsigned packed_t;
int xbyte(packed_t word, int bytenum)
{
    return (word << ((3 - bytenum) << 3)) >> 24;
}

// 2.83
/*
A.  Y是k位二进制序列y的无符号十进制值，x是无穷串的值，则有：
    Y + x = x * (2^k)
B.
    (a) 5 / 7
    (b) 2 / 5
    (c) 19 / 63
*/

// 2.87
/*
描述                   Hex           M           E             V         D
--------------------------------------------------------------------------------
-0                    8000           0           0             \         \
最小的>2的值           4001    (2^10+1)/2^10      1            1*2       2.0
512                   5C00           1           9             \         \     
最大的非规格化数       03FF     (2^9-1)/2^9      -14        511*2^(-24)  0.0
-∞                    FC00           \           \             \         \
0x3BB0                 \          123/2^6       -1          123/128     1.0
*/

int main()
{
    Q_2_59();
    /* // 2.63 测试
    int x = 0x80000000, y;
    unsigned a = 0xFFFFFFFF, b;
    y = sra(x, 4); // 验证算术右移（补最高位）
    b = srl(a, 4); // 验证逻辑右移（补0）
    printf("%#x\n", y);
    printf("%#x\n", b);
    */
    return 0;
}