#include <stdio.h>
#include <assert.h>
void show_bytes(void* start1, int len) {
    int i;
	unsigned char* start = (char*) start1;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

int w = 32;
int w2 = 64;
unsigned unsigned_high_prod(unsigned ux, unsigned uy)
{
	unsigned long long ullx = (unsigned long long)(unsigned)ux;
	unsigned long long ully = (unsigned long long)(unsigned)uy;
	unsigned long long ullxy = ullx*ully;
	unsigned ullxy1 = ullxy>>32;
	return ullxy1;
//	return (((unsigned long long)ux) * ((unsigned long long)uy)>>32;
}
int signed_high_prod(int x, int y)
{
	unsigned ux = (unsigned) x;
	unsigned uy = (unsigned) y;
	// x = ux - SS(x); 
	// y = uy - SS(y);
	// x * y = ux * uy + SS(x)SS(y) - SS(x)uy - SS(y)ux
	// (x*y)>>32 = ...
	unsigned t = (unsigned_high_prod(ux, uy) - (x<0)*uy - (y<0)*ux); 
//	return (x*y<0)?-t:t;
	return t;
}
int check_signed_high_prod(int x, int y)
{
	return (((signed long long)x) * (signed long long)y) >> 32;
}
void show_signed_high_prod(int x, int y)
{
	printf("%d %d\n\n", x, y);
	
	unsigned long long ullx = (unsigned long long)(unsigned)x;
	unsigned long long ully = (unsigned long long)(unsigned)y;
	unsigned long long ullxy = ullx*ully;
	unsigned ullxy1 = ullxy>>32;
	show_bytes(&ullx, 8);
	show_bytes(&ully, 8);
	show_bytes(&ullxy, 8);
	show_bytes(&ullxy1, 4);
	assert(ullxy1 == unsigned_high_prod(x, y));
	printf("\n\n");
	unsigned ullxy2 = unsigned_high_prod(x, y);
	show_bytes(&ullxy2, 4);
	signed long long sllx = (signed long long)x;
	signed long long slly = (signed long long)y;
	signed long long sllxy = sllx*slly;
	signed long sllxy1 = sllxy >>32;
	show_bytes(&sllx, 8);
	show_bytes(&slly, 8);
	show_bytes(&sllxy, 8);
	show_bytes(&sllxy1, 4);			
	assert(sllxy1 == check_signed_high_prod(x, y));

	printf("check_signed_high_prod = 0x%08X\n", check_signed_high_prod(x, y));
	printf("\n");
	assert(signed_high_prod(x,y) == check_signed_high_prod(x, y));
}
int main()
{
	show_signed_high_prod(1, 2);
	show_signed_high_prod(-1, -2);
	show_signed_high_prod(-100, 100);
	show_signed_high_prod(0xFFFFFFFF, 0xFFFFFFFF);
	show_signed_high_prod(0x80000000, 0x80000000);
}
