#include <stdio.h>

int leftmost_one(unsigned d)
{
	d|=d>>1;
	d|=d>>2;
	d|=d>>4;
	d|=d>>8;
	d|=d>>16;
	return (((d>>1) + 1)&d );
}
void show_leftmost_one(unsigned d)
{
	printf("show_leftmost_one(0x%08X) = 0x%08X\n", d, leftmost_one(d));
}

int main()
{
	show_leftmost_one(0xFF00);
	show_leftmost_one(0xFFFFFFFF);
	show_leftmost_one(0x000000);
	show_leftmost_one(0xF0F00000);
	show_leftmost_one(0x1);
	return 0;
}
