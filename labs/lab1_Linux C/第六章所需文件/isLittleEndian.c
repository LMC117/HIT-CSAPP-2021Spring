#include <stdio.h>

int main(){
    // int类型赋值给char类型会造成数据丢失，故设置一个2字节的int，赋值给1字节的char类型，根据留下的字节来判断是大端存储还是小端存储
    int a = 0x1100;
    char b = a;
    if(b == 00)
        printf("小端存储");
    else
        printf("大端存储");
    return 0;
}