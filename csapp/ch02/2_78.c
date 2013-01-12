#include<stdio.h>
#include<assert.h>
#include<limits.h>
const int w = sizeof(int) << 3;
const int off = (sizeof(int)<<3) - 1;
int div_pwr2k(int x, int k)
{
	int neg = (((x&INT_MIN)>>off)&(x+(1<<k)-1))>>k;
	int pos = (((~x&INT_MIN)>>off)&x)>>k;
	return neg|pos;
}
int mul5div8(int x)
{
	//return (((x) >> 1) + ((x+((x&1)<<2))>>3));
	//int pos = ((~x&INT_MIN)>>off)&((x>>1) + (x>>3)+(((x&7)+((x&1)<<2))>>3));
	//int min = ((x==INT_MIN)<<off>>off)&
	int xxxxx= (x<<2) + x;
	return div_pwr2k(xxxxx, 3);
}

void show_mul5div8(int x)
{
	printf("mul5div8(%d) = %d %d\n", x, mul5div8(x), (5*x)/8);
	assert(mul5div8(x) == 5*x/8);
}

int main()
{
	int i;
	for (i = 32; i >=-32; i--)
		show_mul5div8(i);
}
