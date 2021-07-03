#include <stdio.h>

int utf8len(char *x)
{
    int n = 0;
    for (; *x != '\0'; n++)
    {
        if ((*x >> 7) == 0)
            x++;
        else if ((*x >> 5) == 0xFFFFFFFE)
            x += 2;
        else if ((*x >> 4) == 0xFFFFFFFE)
            x += 3;
        else if ((*x >> 3) == 0xFFFFFFFE)
            x += 4;
        else
            break;
    }
    return n;
}

int main()
{
    char c[] = "A阿萨德";
    int n = utf8len(c);
    printf("%d", n);
    return 0;
}