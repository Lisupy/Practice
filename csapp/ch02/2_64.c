#include<stdio.h>
int any_even_one(unsigned x)
{
	return (x & 0x55555555) != 0;
}
void show_any_even_one(unsigned x)
{   
	printf("any_even_one(0x%08x) = 0x%08x\n", x, any_even_one(x));
}
int main()
{
	show_any_even_one(0);
	show_any_even_one(1);
	show_any_even_one(2);
	return 0;
}
