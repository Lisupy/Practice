#include<stdio.h>
#include<assert.h>
#include<limits.h>
const int w = sizeof(int) << 3;
const int off = (sizeof(int)<<3) - 1;
int fiveeighths(int x)
{
	//return (((x) >> 1) + ((x+((x&1)<<2))>>3));
	int pos = ((INT_MIN&~x)>>off)&((x>>1) + (x>>3)+(((x&7)+((x&1)<<2))>>3));
	int neg = ((INT_MIN&x)>>off)&((x>>1) + (x>>3) - ((-(x&7)) + (-(x&1)<<2)>>3));
	return pos|neg;
}

void show_fiveeigths(int x)
{
	printf("fiveeigths(%d) = %d %lld\n", x, fiveeigths(x), (5*(long long int)x)/8);
	assert(fiveeigths(x) == 5*(long long int)x/8);
}

int main()
{
	int i;
	for (i = 32; i >=-32; i--)
		show_fiveeigths(i);
	show_fiveeigths(0x80000000);
}
