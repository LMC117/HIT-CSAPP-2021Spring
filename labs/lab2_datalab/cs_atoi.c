#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cs_atoi(const char *str)
{
    int n = 0;
    int neg = 0; // 标志其是否是负数
    if (*str == '-')
    {
        neg = 1;
        str++;
    }
    for (; *str != '\0'; str++)
    {
        if (*str == '0')
            n *= 10;
        else if (*str == '1')
            n += 1, n *= 10;
        else if (*str == '2')
            n += 2, n *= 10;
        else if (*str == '3')
            n += 3, n *= 10;
        else if (*str == '4')
            n += 4, n *= 10;
        else if (*str == '5')
            n += 5, n *= 10;
        else if (*str == '6')
            n += 6, n *= 10;
        else if (*str == '7')
            n += 7, n *= 10;
        else if (*str == '8')
            n += 8, n *= 10;
        else if (*str == '9')
            n += 9, n *= 10;
        else
            break;
    }
    if (neg == 0)
        return n / 10;
    else
        return -(n / 10);
}

int main()
{
    int val;
    char str[20];
    // 测试atoi()
    strcpy(str, "-00001044000ss455");
    val = cs_atoi(str);
    printf("字符串值 = %s, 整型值 = %d\n", str, val);
    return 0;
}