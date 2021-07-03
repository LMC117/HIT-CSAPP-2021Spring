#include <stdio.h>

int fib_int(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib_int(n - 2) + fib_int(n - 1);
}

long fib_long(int n)
{
    if (n == 0)
        return (long)0;
    else if (n == 1)
        return (long)1;
    else
        return fib_long(n - 2) + fib_long(n - 1);
}

unsigned int fib_u_int(int n)
{
    if (n == 0)
        return (unsigned int)0;
    else if (n == 1)
        return (unsigned int)1;
    else
        return fib_u_int(n - 2) + fib_u_int(n - 1);
}

unsigned long fib_u_long(int n)
{
    if (n == 0)
        return (unsigned long)0;
    else if (n == 1)
        return (unsigned long)1;
    else
        return fib_u_long(n - 2) + fib_u_long(n - 1);
}

int main()
{
    int i = 0, l = 0, ui = 3, ul = 3;
    for (; fib_int(i) >= 0; i++)
        ;
    printf("对int类型，n为%d时出错\n", i);
    for (; fib_long(l) >= 0; l++)
        ;
    printf("对long类型，n为%d时出错\n", l);
    for (; fib_u_int(ui) > fib_u_int(ui-1); ui++)
        ;
    printf("对unsigned int类型，n为%d时出错\n", ui);
    for (; fib_u_long(ul) > fib_u_long(ul-1); ul++)
        ;
    printf("对unsigned long类型，n为%d时出错\n", ul);
    return 0;
}