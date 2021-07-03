#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

//定义结构体
typedef struct Com
{
    int i;
} com;

//定义联合体
typedef union uni
{
    int i;
    char c;
} uni;

//定义枚举类型
enum week
{
    Mon = 1,
    Tues,
    Wed,
    Thurs,
    Fri,
    Sat,
    Sun
} day;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
    {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void *));
}

void show_short(short x)
{
    show_bytes((byte_pointer)&x, sizeof(short));
}

void show_long(long x)
{
    show_bytes((byte_pointer)&x, sizeof(long));
}

void show_char(char x)
{
    show_bytes((byte_pointer)&x, sizeof(char));
}

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_double(double x)
{
    show_bytes((byte_pointer)&x, sizeof(double));
}

int main()
{
    //数据初始化
    int i = 381;
    int *ip = i;
    short s = 5;
    long l = 179000;
    char c = 'c';
    float f = 3.14;
    double d = 3.14159;
    com com;
    com.i = 50;
    uni uni;
    uni.i = 50;
    uni.c = 'u';
    day = Fri;
    //测试
    printf("变量名                      内容                                地址                         十六进制内存\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("   i                         %d                            %p                      ", i, &i);
    show_int(i);
    printf("  ip                         %p               %p                   ", ip, &ip);
    show_pointer(ip);
    printf("   s                         %d                              %p                   ", s, &s);
    show_short(s);
    printf("   l                         %ld                        %p                   ", l, &l);
    show_long(l);
    printf("   c                         %c                              %p                   ", c, &c);
    show_char(c);
    printf("   f                         %f                      %p                   ", f, &f);
    show_float(f);
    printf("   d                         %lf                      %p                   ", d, &d);
    show_double(d);
    printf("   com.i                     %d                            %p                      ", com.i, &com.i);
    show_int(com.i);
    printf("   uni.i                     %d                           %p                   ", uni.i, &uni.i);
    show_int(uni.i);
    printf("   uni.c                     %c                             %p                   ", uni.c, &uni.c);
    show_char(uni.c);
    printf("   day                       %d                             %p                   ", day, &day);
    show_int(day);
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("main函数的地址: %lx\n", main);
    printf("printf函数的地址: %lx\n", printf);
    return 0;
}