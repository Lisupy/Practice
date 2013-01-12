#include <stdio.h>
#include <assert.h>

float u2f(unsigned x)
{
	return *(float*)(&x);
}
unsigned f2u(float x)
{
	return *(unsigned*)(&x);
}

const int s = 1;
const int k = 8;
const int n = 23;

const int Bias = ( 1<<(8-1) ) - 1;

float fpw2(int x)
{
	/*  Result exponent and fraction */
	unsigned exp, frac;
	unsigned u;
	if (x < -149) {
		/* Too small. Return 0.0 */
		exp = 0;
		frac = 0;
	//	printf("1*__  %d\r\n", x);
	} else if (x < -126){
		/* Denormalized result */
		exp = 0;
		frac = 1 << ( 149 + x);
		//printf("2*__  %d\r\n", x);
	} else if ( x < 129) {
		/*  Normalized result */
		exp = x + 127;
		frac = 0;
		///printf("3*__  %d\r\n", x);
	} else {
		/* Too big. Return +oo */
		exp = 255;
		frac = 0;
	}
	
	/* Pack exp and frac into 32 bits */
	u = exp << 23 | frac;
	/* Return as float */
	return u2f(u);
}

float fpwr2_check(int x)
{
	float fx = 1;
	if (x > 0) {
		while (x--)
			fx*=2;
	} else {
		while (x++)
			fx/=2;
	}
	return fx;
}

void print_fpwr2(int x)
{
	float f1 = fpw2(x);
	float f2 = fpwr2_check(x);
	if (f1 != f2) {
		printf("x = %d, f1 = %10.20f, f2 = %10.20f\r\n", x, f1, f2);
		printf("\t\t%u, %u\r\n", f2u(f1), f2u(f2));	
		assert(0);
	}
}

int main()
{
//	printf("Bias = %d\r\n", Bias);
	int i = 0;
	for (i = -1000; i <= 1000; i++) {
		print_fpwr2(i);
	}
	puts("check fpw2 in range(-1000,1000) done!");
	return 0;
}
