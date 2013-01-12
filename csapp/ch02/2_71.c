#include<stdio.h>
#include<assert.h>

typedef unsigned packed_t;
int xbyte(packed_t word, int bytenum)
{
	int n = word;
	int off = (3-bytenum)<< 3;
	return n << off >> 24;
}
void show_xbyte(packed_t x, int bytenum)
{
	printf("xbyte(0x%08X,%d) = 0x%08X\n", x, bytenum, xbyte(x,bytenum));
}

int main()
{
	show_xbyte(0x00000000, 1);
	show_xbyte(0xFEDCBA21, 0);
	show_xbyte(0xFFEDCBA2, 1);
	show_xbyte(0x0FFFFFFF, 2);
	show_xbyte(0x0FFFFFFF, 3);
	show_xbyte(0x0FFFFFFF, 0);
}
