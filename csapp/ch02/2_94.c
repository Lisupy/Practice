#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#include <string.h>


typedef unsigned float_bits;

float_bits float_twice(float_bits f)
{
	unsigned sign = f >> 31;
	unsigned exp  = f >> 23 & 0xFF;
	unsigned frac = f		& 0x7FFFFF;
	
//	printf("sign = %x\r\n", sign);
//	printf("exp = %x\r\n", exp);
//	printf("frac = %x\r\n", frac);
	if (exp == 0xFF)
		;
	else if (exp != 0)
	{
		exp++;
		if (exp == 0xFF)
			frac = 0;
	}
	else
	{
		frac <<= 1;
	}

	return (sign << 31) | (exp << 23) | frac;
}

float float_twice_real(float f)
{
	return 2 * f;
}

void check_float_twice(unsigned u)
{
	unsigned u2 = float_twice(u);
	float f = *(float*)&u;
	float f2 = float_twice_real(f);

	if (memcmp(&u2, &f2, sizeof(unsigned)))
	{
		if (isnan(*(float*)&u))
		{
			assert(u2 == u);
			return;
		}
		printf("u  = 0x%08x, %f\r\n", u,  *(float*)&u);
		printf("u2 = 0x%08x, %f\r\n", u2, *(float*)&u2);
		printf("f  = 0x%08x, %f\r\n", *(unsigned*)&f, f);
		printf("f2 = 0x%08x, %f\r\n", *(unsigned*)&f2, f2);
		assert(0);
	}
}

int main()
{
	unsigned u;
	for (u = 0x0; u <= UINT_MAX; u++)
	{
		check_float_twice(u);
		if ( (u & 0xFFFFFF) == 0)
		{
			printf("=================%08x==\r\n", u);
		}
		if (u == UINT_MAX)
			break;
	}
}
