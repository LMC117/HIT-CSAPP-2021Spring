#include <math.h>
#include <stdio.h>

// CSAPP - 第九章作业


// 9.11

/*
A.
0 0 0 0 1 0 0 1 1 1 1 1 0 0
B.
VPN:        0x9
TLBI:       0x1
TLBT:       0x2
TLB命中:    否
缺页:       否
PPN:        0x17
C.
0 1 0 1 1 1 1 1 1 1 0 0
D.
字节偏移：      0x0
缓存索引:       0xf
缓存标记:       0x17
缓存命中:       否
返回缓存字节:   无
*/


// 9.13

/*
A.
0 0 0 0 0 0 0 1 0 0 0 0 0 0
B.
VPN:        0x1
TLBI:       0x1
TLBT:       0x0
TLB命中:    否
缺页:       是
PPN:        无
C.D.均无意义
*/


// 9.15

/*
请求            块大小          块头部
malloc(3)       8               0x9                    
malloc(11)      16              0x10
malloc(20)      24              0x19
malloc(21)      24              0x19
*/


// 9.19

/*
1)
    a
2)
    d
3)
    b
*/