#include <stdio.h>
#include <string.h>

int main()
{
    char *p;
    float pos_zero, neg_zero, min_pos, max_pos, min_g, pos_inf, nan;
    // 注意p+1代表向高地址移动，而x86机器中以小端法保存，所以高地址保存着后面的位  高地址 78 56 34 12 低地址
    // +0
    p = (char *)&pos_zero;
    *p = 0b00000000;
	*(p + 1) = 0b00000000;
	*(p + 2) = 0b00000000;
	*(p + 3) = 0b00000000;
    printf("+0:%f\n",pos_zero);
    // -0
    p = (char *)&neg_zero;
    *p = 0b00000000;
	*(p + 1) = 0b00000000;
	*(p + 2) = 0b00000000;
	*(p + 3) = 0b10000000;
    printf("-0:%f\n",neg_zero);
    // 最小浮点正数  1 8 23
    p = (char*)& min_pos;
	*p = 0b00000001;
	*(p + 1) = 0b00000000;
	*(p + 2) = 0b00000000;
	*(p + 3) = 0b00000000;
	printf("最小浮点正数:%.46f\n",min_pos);
    // 最大浮点正数
    p = (char*)& max_pos;
	*p = 0b11111111;
	*(p + 1) = 0b11111111;
	*(p + 2) = 0b01111111;
	*(p + 3) = 0b01111111;
	printf("最大浮点正数:%.46f\n",max_pos);
    // 最小规格化数
    p = (char*)& min_g;
	*p = 0b00000001;
	*(p + 1) = 0b00000000;
	*(p + 2) = 0b10000000;
	*(p + 3) = 0b00000000;
	printf("最小正规格化数:%.46f\n",min_g);
    // 正无穷
    p = (char*)& pos_inf;
	*p = 0b00000000;
	*(p + 1) = 0b00000000;
	*(p + 2) = 0b10000000;
	*(p + 3) = 0b01111111;
	printf("正无穷:%f\n",pos_inf);
    // NaN
    p = (char*)& nan;
	*p = 0b00000001;
	*(p + 1) = 0b00000000;
	*(p + 2) = 0b10000000;
	*(p + 3) = 0b01111111;
	printf("NaN:%f\n",nan);
    return 0;
}