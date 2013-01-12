#include <stdio.h>
float u2f(unsigned x)
{
	return *(float*)(&x);
}
unsigned f2u(float x)
{
	return *(unsigned*)(&x);
}


void show_bits(unsigned x)
{
	int i = 0;
	for (i = 0; i < 32; i++) {
		if (1 & (x >> (31 - i)))
			printf("1");
		else
			printf("0");
	}
}



int main()
{
	show_bits(f2u(22.f/3));
	return 0;
}


