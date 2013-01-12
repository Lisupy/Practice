#include<stdio.h>
int sra(int x, int k)
{
	int xsrl = (unsigned) x >> k;
	return xsrl | (x << (sizeof(int)*8 - k));	
}
void show_sra(int x, int k)
{
	printf("sra(0x%08X, %d) = 0x%08X\n", x, k, sra(x, k));
}
unsigned srl(unsigned x, int k)
{
	unsigned xsra = (int) x >> k;
	return (xsra) & ((1 << (sizeof(int)*8 - k)) - 1);
}

void show_srl(unsigned x, int k)
{
	printf("srl(0x%08X, %d) = 0x%08X\n", x, k, srl(x, k));
}

int main()
{
	show_sra(0xFFFFFFFF, 4);
	show_sra(0x0FFFFFFF, 4);
	show_srl(0xFFFFFFFF, 4);
	show_srl(0x0FFFFFFF, 4);
	return 0;
}
