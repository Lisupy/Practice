#include<stdio.h>

unsigned rotate_right(unsigned x, int n)
{
	unsigned mask = (1<<(n-1)<<1)-1;
	return (x>>n)|(x&mask)<<(32-n);
}
void show_rotate_right(unsigned x, int n)
{
	printf("rotate_right(0x%08X,%d) = 0x%08X\n", x, n, rotate_right(x,n));
}

int main()
{
	show_rotate_right(0x00000000, 1);
	show_rotate_right(0xFFFFFFFF, 32);
	show_rotate_right(0x10101010, 1);
	show_rotate_right(0x10000000, 32);
	show_rotate_right(0x78ABCDEF, 0);
	show_rotate_right(0x78ABCDEF, 4);
	show_rotate_right(0x78ABCDEF, 8);
	show_rotate_right(0x78ABCDEF, 32);

}
