#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cs_itoa(int value, char *s)
{
    char *p = s;
    if (value < 0)
    {
        *s = '-';
        s++;
    }
    value = abs(value);
    for (; value != 0; s++)
    {
        int t = 0; // 迭代的次数
        int temp = value;
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
        // 更新value的值
        value -= temp * pow(10, t);
    }
    *s = '\0';
    for (; *p != '\0';p++) // 遍历字符数组
        printf("%c", *p);
    printf("\n");
}

int main()
{
    int n;
    char s[10000];
    n = 1233;
    cs_itoa(n, s);
    n = 123344;
    cs_itoa(n, s);
    n = -123;
    cs_itoa(n, s);
    return 0;
}