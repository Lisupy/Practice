#include <stdio.h>
#include <limits.h>
unsigned f2u(float x)
{
    return *((unsigned*)&x);
}
aaf
float u2f(unsigned x)
{
	return *((float*)&x);
}

int float_ge(float x, float y)
{
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);
    unsigned sx = ux>>31;
    unsigned sy = uy>>31;
    return 	(  sx &&  sy ) && (ux <= uy)	|| //x<=0,y<=0
            (  sx && !sy) && (ux == INT_MIN && uy == 0)	||  //x<=0,y>=0
            ( !sx &&  sy) ||		// x>=0, y<=0
            ( !sx &&  sy) && (ux>=uy); // x>=0, y>=0
}
void show_float_ge(float x, float y)
{
	printf("0x%08X, 0x%08X\n", f2u(x), f2u(y));
	printf("float_ge(%f, %f) = %d\n", x, y, float_ge(x, y));
	printf("\n");
}

int main()
{
	show_float_ge(0, 0);
	show_float_ge(-0, -0);
	show_float_ge(-0.0, 0.0);
	show_float_ge(0.0, -0.0);
	show_float_ge(-1.1, 0);
	show_float_ge(-1.2, -1.3);
	show_float_ge(1.2, 1.3);
	show_float_ge(1.2, -1.3);
	show_float_ge(-1.2, 1.3);
}

