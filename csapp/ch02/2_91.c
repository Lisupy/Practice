#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <string.h>
#include <math.h>
typedef unsigned float_bits;

float_bits float_absval(float_bits f)
{
	unsigned sign = f>>31;
	unsigned exp  = f>>23 & 0xFF;
	unsigned frac = f 	  & 0x7FFFFF;

	if (exp != 0xFF || frac == 0) {
		sign = 0; 
	}


	return (sign << 31) | (exp << 23) | frac;
}

float float_abs(float f)
{
	if (isnan(f))
		return f;
	if (f == 0)
		return 0;
	if (f < 0.0)
		return -f;
	return f;
}

void check_float_absval(unsigned i)
{
	float f = *(float*)(&i);
	float absf = float_abs(f);
	unsigned absi = float_absval(i);
	if (memcmp(&absi, &absf, sizeof(unsigned))) {
		//printf("isnan = %d ", isnan(f));
		if (isnan(f))
		{
			assert(i == absi);
			return;
		}
		printf("%d\r\n", i);
		printf("i = 0x%08x\r\n", i);
		printf("absi = 0x%08x\r\n", absi);
		printf("f = %f\r\n", f);
		printf("absf = %f\r\n", absf);
		printf("f = 0x%08x\r\n", *(int*)&f);
		printf("absf = 0x%08x\r\n", *(int*)&absf);
		float a = -0.0;
		float b = -a;
		printf("a = 0x%08x\r\n", *(int*)&a);
		printf("b = 0x%08x\r\n", *(int*)&b);
		assert(0);
	}
}

int main()
{
	unsigned i;
//	check_float_absval(INT_MIN);
	for (i = 0x0; i <= UINT_MAX; i++){
		check_float_absval(i);
		if ((i & 0xFFFFFF) == 0)
			printf("======0x%08x\r\n", i);
		if (i == UINT_MAX)
			break;
	}
	return 0;
}
