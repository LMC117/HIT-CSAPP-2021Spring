#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cs_ftoa(double value, char *s)
{
    char *p = s;
    if (value < 0)
    {
        *s = '-';
        s++;
    }
    value = fabs(value);
    int int_value = floor(value); // 取整数部分
    // 整数部分操作
    for (; int_value != 0; s++)
    {
        int t = 0; // 迭代的次数
        int temp = int_value;
        // 获取最高位
        while (temp > 10)
        {
            temp /= 10;
            t++;
        }
        // 向字符数组写入该位
        if (temp == 0)
            *s = '0';
        else if (temp == 1)
            *s = '1';
        else if (temp == 2)
            *s = '2';
        else if (temp == 3)
            *s = '3';
        else if (temp == 4)
            *s = '4';
        else if (temp == 5)
            *s = '5';
        else if (temp == 6)
            *s = '6';
        else if (temp == 7)
            *s = '7';
        else if (temp == 8)
            *s = '8';
        else if (temp == 9)
            *s = '9';
        // 更新int_value的值
        int_value -= temp * pow(10, t);
    }
    *s = '.';
    s++;
    double u;
    double fract = modf(value, &u); // fract保留着value的小数部分,u保留着value的整数部分
    double error_ftoa = fract;      // 记录误差，用于与精度比较终止循环
    int n = 1;                      // 记录小数点后的位数
    // 小数部分操作: 每次乘10取整数部分，直到剩余0为止
    for (; error_ftoa >= 1e-6; s++, n++)
    {
        fract *= 10;
        fract = modf(fract, &u);
        int int_u = (int)u;
        error_ftoa -= (u * pow(10, -n));
        if (int_u == 0)
            *s = '0';
        else if (int_u == 1)
            *s = '1';
        else if (int_u == 2)
            *s = '2';
        else if (int_u == 3)
            *s = '3';
        else if (int_u == 4)
            *s = '4';
        else if (int_u == 5)
            *s = '5';
        else if (int_u == 6)
            *s = '6';
        else if (int_u == 7)
            *s = '7';
        else if (int_u == 8)
            *s = '8';
        else if (int_u == 9)
            *s = '9';
    }
    *s = '\0';
    for (; *p != '\0'; p++) // 遍历字符数组
        printf("%c", *p);
    printf("\n");
}

int main()
{
    double n;
    char s[10000];
    n = 1233.11;
    cs_ftoa(n, s);
    n = 1.23344;
    cs_ftoa(n, s);
    n = -123.5500;
    cs_ftoa(n, s);
    return 0;
}