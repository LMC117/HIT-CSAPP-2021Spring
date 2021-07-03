#include <stdio.h>

int fib_int(int n)
{
    int a, b, c;
    a = 0;
    b = 1;
    c = 1;
    if (n == 0)
        return a;
    else if (n == 1)
        return b;
    else
    {
        for (int i = 2; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}

long fib_long(int n)
{
    long a, b, c;
    a = 0;
    b = 1;
    c = 1;
    if (n == 0)
        return a;
    else if (n == 1)
        return b;
    else
    {
        for (int i = 2; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}

unsigned int fib_u_int(int n)
{
    unsigned int a, b, c;
    a = 0;
    b = 1;
    c = 1;
    if (n == 0)
        return a;
    else if (n == 1)
        return b;
    else
    {
        for (int i = 2; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}

unsigned long fib_u_long(int n)
{
    unsigned long a, b, c;
    a = 0;
    b = 1;
    c = 1;
    if (n == 0)
        return a;
    else if (n == 1)
        return b;
    else
    {
        for (int i = 2; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}

int main()
{
    int i = 46, l = 0, ui = 3, ul = 3;
    for (; fib_int(i) >= 0; i++)
        ;
    printf("对int类型，n为%d时出错\n", i);
    for (; fib_long(l) >= 0; l++)
        ;
    printf("对long类型，n为%d时出错\n", l);
    for (; fib_u_int(ui) > fib_u_int(ui - 1); ui++)
        ;
    printf("对unsigned int类型，n为%d时出错\n", ui);
    for (; fib_u_long(ul) > fib_u_long(ul - 1); ul++)
        ;
    printf("对unsigned long类型，n为%d时出错\n", ul);
    return 0;
}