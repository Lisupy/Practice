#include<stdio.h>
#include<limits.h>

int saturating_add(int x, int y)
{
	int mask = INT_MIN;
	int sum = x + y;
	int w = (sizeof(int)<<3)-1;
	int tmin = ( ((x&mask)&&(y&mask)&&!(sum&mask)) << w >> w ) & INT_MIN;
	int tmax = ( ((~x&mask)&&(~y&mask)&&(sum&mask)) << w >> w) & INT_MAX;
	return (sum& ~(!(tmin|tmax))) | tmin | tmax;
}

void show_saturating_add(int x, int y)
{
	printf("saturating_add(0x%08X, 0x%08X) = 0x%08X:%d\n", 
			x, y, saturating_add(x, y), saturating_add(x, y) );
	printf("%d + %d = %d\n", x, y, x+y);
	printf("    \n");
}


int main()
{
	show_saturating_add(0xFFFFFFFF, 0x80000000);
	show_saturating_add(0xFFFFFFFF, 0xFFFFFFFF);
	show_saturating_add(0x7FFFFFF0, 0x0000000F);
	show_saturating_add(0x7FFFFFF5, 0x0000000F);
	show_saturating_add(0x55555555, 0x55555555);
	show_saturating_add(0x55555555, 0x33333333);
	show_saturating_add(0x55555555, 0x23333333);
	show_saturating_add(0x55555555, 0x2FFFFFFF);
}

