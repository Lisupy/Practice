#include<stdio.h>


uint32_t mix_x_leb_and_y(uint32_t x, uint32_t y)
{
	return (x&0xFF) | (y&~0xFF);
}

void show_mix(uint32_t x, uint32_t y)
{
	printf("mix 0x%08X and 0x%08X : 0x%08X\r\n", 
			x, y, mix_x_leb_and_y(x, y));
}
int main()
{
	show_mix(0x89ABCDEF, 0x76543210);
	return 0;
}
