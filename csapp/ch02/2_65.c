#include<stdio.h>
int even_ones(unsigned x)
{
	x ^= x >> 16;
	x ^= x >> 8;
	x ^= x >> 4;
	x ^= x >> 2;
	x ^= x >> 1;
	return !(x & 1) ;
}
void show_even_ones(unsigned x)
{
	printf("even_ones(0x%08X) = %d\n", x, even_ones(x));
}

int main()
{
	show_even_ones(0x00000000);
	show_even_ones(0xFFFFFFFF);
	show_even_ones(0x10101010);
	show_even_ones(0x10000000);
}
