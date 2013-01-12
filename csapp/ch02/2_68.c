#include<stdio.h>
int lower_bits(int x, int n)
{
	int mask = (1<<(n-1)<<1)-1;
	return x&mask;
}

void show_lower_bits(int x, int n)
{
	printf("lower_bits(0x%08X,%d) = 0x%08X\n", x, n, lower_bits(x,n));
}

int main()
{
	show_lower_bits(0x00000000, 1);
	show_lower_bits(0xFFFFFFFF, 32);
	show_lower_bits(0x10101010, 1);
	show_lower_bits(0x10000000, 32);
	show_lower_bits(0x78ABCDEF, 1);
	show_lower_bits(0x78ABCDEF, 2);
	show_lower_bits(0x78ABCDEF, 8);
	show_lower_bits(0x78ABCDEF, 32);

}
