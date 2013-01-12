#include<stdio.h>
#include<assert.h>
int int_shifts_are_logical()
{
	int x = (int)0x80000000;
	return !~(x>>((sizeof(int)<<3)-1));
}

int main()
{
	assert(int_shifts_are_logical() == 1);
	puts("OK!");
	return 0;
}
