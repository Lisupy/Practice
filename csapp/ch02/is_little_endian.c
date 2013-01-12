#include<stdio.h>

int is_little_endian()
{
	int i = 0x12345678;
	return *((char*)(&i) == 0x78;
}

int main()
{
	printf("is_little_endian = %d", is_little_endian());
}
