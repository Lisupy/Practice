#include<stdio.h>

unsigned put_byte(unsigned x, unsigned char b, int i)
{
	int lshift = (sizeof(int) - 1 - i) << 3;
	int rshift = i << 3;
	
	return (x & ~(0xFF << rshift)) | (b << rshift);
}

void show_put_byte(unsigned x, unsigned char b, int i)
{
	printf("put_byte(0x%08X, 0x%02X, %d) = 0x%08X\r\n",
			x, b, i, put_byte(x, b, i));
}
int main()
{
	show_put_byte(0x12345678, 0xAB, 2);
	show_put_byte(0x12345678, 0xAB, 0);
	return 0;
}
