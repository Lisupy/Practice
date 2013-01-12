#include<stdio.h>
#include<assert.h>

int fits_bits(unsigned x, int n)
{
	assert(n!=0);
	int count = 8*sizeof(int) - n;
	return ((x<<count)>>count) == x;
}
void show_fits_bits(unsigned x, int n)
{
	printf("fits_bits(0x%08X,%d) = %d\n", x, n, fits_bits(x,n));
}

int main()
{
	show_fits_bits(0x00000000, 1);
	show_fits_bits(0xFFFFFFFF, 32);
	show_fits_bits(0xFFFFFFFF, 1);
	show_fits_bits(0x0FFFFFFF, 23);
	show_fits_bits(0x0FFFFFFF, 24);
	show_fits_bits(0x0FFFFFFF, 25);
	show_fits_bits(0x0FFFFFFF, 26);
	show_fits_bits(0x0FFFFFFF, 27);
	show_fits_bits(0x0FFFFFFF, 28);
	show_fits_bits(0x0FFFFFFF, 29);
	show_fits_bits(0x10101010, 1);
	show_fits_bits(0x10000000, 32);
	show_fits_bits(0x78ABCDEF, 4);
	show_fits_bits(0x78ABCDEF, 8);
	show_fits_bits(0x78ABCDEF, 32);
}
