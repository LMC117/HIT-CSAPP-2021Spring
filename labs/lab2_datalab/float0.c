#include <stdio.h>

int main()
{
    float x = 3.1415926;
    float m = 0.000000000000000000000000000000000000001;
    printf("float / 0:%f\n", x / 0);
    printf("float / min_float:%f\n", x / m);
    return 0;
}