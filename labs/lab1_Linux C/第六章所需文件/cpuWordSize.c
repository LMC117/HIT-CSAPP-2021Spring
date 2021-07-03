#include <stdio.h>

int main()
{
    int a = sizeof(char *);
    if (a == 4)
        printf("CPU为32位");
    else if (a == 8)
        printf("CPU为64位");
    return 0;
}
