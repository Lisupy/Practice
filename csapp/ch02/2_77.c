#include <stdio.h>
#include <limits.h>
int divide_power2(int x, int k)
{
	int w = sizeof(int)<<3;
	int off = w - 1;
	return ((((x&INT_MIN)>>off)&(x+(1<<k)-1))|(((~x&INT_MIN)>>off)&x))>>k;
}

int show_divide_power2(int x, int k)
{
	printf("divide_power2(%d, %d) = %d\n", x, k, divide_power2(x, k));
}

int main()
{
	show_divide_power2(15, 1);
	show_divide_power2(-15, 1);
	show_divide_power2(-16, 1);
	show_divide_power2(-17, 1);
	show_divide_power2(0x80000000, 31);
}
