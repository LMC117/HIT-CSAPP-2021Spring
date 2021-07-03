#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double cs_atof(const char *str)
{
    double n = 0;
    int neg = 0;  // 标志其是否是负数
    int flag = 0; // flag = 1，表示有小数点出现，开始小数位的计算
    int w = 1;    // 表示小数点后的位数
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
            n += 1;
        else if (*str == '2')
            n += 2;
        else if (*str == '3')
            n += 3;
        else if (*str == '4')
            n += 4;
        else if (*str == '5')
            n += 5;
        else if (*str == '6')
            n += 6;
        else if (*str == '7')
            n += 7;
        else if (*str == '8')
            n += 8;
        else if (*str == '9')
            n += 9;
        else if (*str == '.')
        {
            flag = 1;
            n *= 10;
            break;
        }
        else
            break;
    }
    n /= 10;       // 固定整数部分
    if (flag == 1) //进入小数部分的处理
    {
        str++;
        for (; *str != '\0'; str++, w++)
        {
            if (*str == '0')
                ;
            else if (*str == '1')
                n += 1 / pow(10, w);
            else if (*str == '2')
                n += 2 / pow(10, w);
            else if (*str == '3')
                n += 3 / pow(10, w);
            else if (*str == '4')
                n += 4 / pow(10, w);
            else if (*str == '5')
                n += 5 / pow(10, w);
            else if (*str == '6')
                n += 6 / pow(10, w);
            else if (*str == '7')
                n += 7 / pow(10, w);
            else if (*str == '8')
                n += 8 / pow(10, w);
            else if (*str == '9')
                n += 9 / pow(10, w);
            else
                break;
        }
    }
    if (neg == 0)
        return n;
    else
        return -n;
}

int main()
{
    double d, e, f;
    char str[20];
    strcpy(str, "01.13sad489");
    d = cs_atof(str);
    printf("字符串值 = %s, 双精度浮点值 = %f\n", str, d);
    strcpy(str, "-.13sa44");
    e = cs_atof(str);
    printf("字符串值 = %s, 双精度浮点值 = %f\n", str, e);
    strcpy(str, "-1.10300sad489");
    f = cs_atof(str);
    printf("字符串值 = %s, 双精度浮点值 = %f\n", str, f);
    return 0;
}