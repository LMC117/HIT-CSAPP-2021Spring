#include <math.h>
#include <stdio.h>

// CSAPP - 第六章作业

// 6.27

/*
A.   01000101或 00111000(标记) + 001(组索引) + 00~11(块偏移)
0x0704  0x0705  0x0706  0x0707
0x08A4  0x08A5  0x08A6  0x08A7
B.   10010001(标记，因为另一组有效位为0) + 110(组索引) + 00~11(块偏移) 
0x1238  0x1239  0x123a  0x123b
*/

// 6.31

/*
A.
0011100011010
B.
块偏移CO: 0x2
组索引CI: 0x6
标记CT:   0x38
命中与否: 否
返回的高速缓存字节: 无
*/

// 6.35

/*
cache: 8组，每组1行，每行4个int
dst：
    0   1   2   3
0   m   h   h   h
1   m   h   h   h
2   m   h   h   h
3   m   h   h   h

src：
    0   1   2   3
0   m   h   h   h
1   m   h   h   h
2   m   h   h   h
3   m   h   h   h

*/

// 6.39

/*
A.
16 * 16 * 4 = 1024
B.
读取方式造成了每个元素（如 square[0][0] 在写c,m,y,k时miss一次，hit三次，故不命中写总数为：256
C.
不命中率：25%
*/

// 6.43

/*
cache有16K组，每组可放1个结构体；
在程序中，相当于按行遍历buffer，buffer中共300K个结构体；
但因为是按行遍历，所以在为一个pixel赋值时，miss一次，hit三次
最终的不命中率为25%
*/

// 6.45 (四星题)

/*
dst按列读入，但每一次读入的cache line只利用了一次便被替换，造成大量的miss
考虑用分块的方法来进行优化：在读入cache line后，对其中的数据充分利用，然后再读下一块
*/

// 设单个cache line数据块容量是B
int B;
void transpose(int *dst, int *src, int dim)
{
    int i, j, x, y, d, s;
    long max = pow(dim, 2);
    for (i = 0; i < dim; i += B)
        for (j = 0; j < dim; j += B)
            for (x = i; x < (i + B); x++)
                for (y = j; y < (j + B); y++)
                {
                    // 使用变量保存cache line中的值，替换后也不再使用，降低miss数
                    d = y * dim + x;
                    s = x * dim + y;
                    if (s < max && d < max)
                        dst[d] = src[s];
                }
}

// 6.46 (四星题)

/*
在上一题的基础上稍加改进即可
*/

void col_convert(int *G, int dim)
{
    int i, j, x, y, d, s;
    long max = pow(dim, 2);
    for (i = 0; i < dim; i += B)
        for (j = i; j < dim; j += B)
            for (x = i; x < i + B; x++)
                for (y = j; y < j + B; y++)
                {
                    // 使用变量保存cache line中的值，替换后也不再使用，降低miss数
                    d = y * dim + x;
                    s = x * dim + y;
                    if (s < max && d < max)
                    {
                        _Bool temp = G[d] || G[s];
                        G[d] = temp;
                        G[s] = temp;
                    }
                }
}