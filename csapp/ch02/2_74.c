#include<stdio.h>
int tsub_ovf(int x, int y)
{
	return (y>0&&x-y>x)||(y<0&&x-y<x);
}
void show_tsub_ovf(int x, int y)
{
	printf("%d-%d=%d  %s\n", x, y, x-y, tsub_ovf(x, y)?"overflow":"unoverflow");
}
int main()
{
	show_tsub_ovf(-1, 0);
	show_tsub_ovf(-2, 0);
	show_tsub_ovf(0x80000000, 1);
	show_tsub_ovf(0x80000000, 0x80000000);
	show_tsub_ovf(0x0FFFFFF0, 0x80000000);
}
