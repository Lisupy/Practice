#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

typedef unsigned float_bits;

float_bits float_half(float_bits f)
{
	unsigned sign = f >> 31;
	unsigned exp  = f >> 23 & 0xFF;
	unsigned frac = f 		& 0x7FFFFF;
	unsigned flag = 0;

	if (exp == 0xFF)
	{
		;	
	}
	else if (exp != 0)
	{
		exp = exp - 1;
		if (exp == 0)
			flag = 1;
	}
	if (exp == 0)
	{
		if ( (frac & 0x3) == 0x3)
		{
			frac = (frac >> 1) + 1;
		}
		else
		{
			frac = frac >> 1;
		}		
		
	}

	if (flag)
		frac = frac + 0x400000; 	
	return (sign << 31) | (exp << 23) | frac;
}

float float_half_real(float f)
{
	if (isnan(f))
		return f;
	return 0.5*f;
}

void check_float_half(unsigned u)
{
	float f = *(float*)&u;
	float f2 = float_half_real(f);
	float_bits u2 = float_half(u);

	if (memcmp(&f2, &u2, sizeof(float)))
	{
		if(isnan(f))
		{
			assert(u == u2);
			return;
		}
		printf("isnan(f) = %d\r\n", isnan(f));
		printf("u  = 0x%08x, %.10f\r\n", u, *(float*)&u);
		printf("u2 = 0x%08x, %.10f\r\n", u2, *(float*)&u2);
		printf("f  = 0x%08x, %.10f\r\n", *(int*)&f, f);
		printf("f2 = 0x%08x, %.10f\r\n", *(int*)&f2, f2);
		assert(0);
	}
}

int main()
{
	unsigned u;
	for (u = 0; u <= UINT_MAX; u++)
	{
		check_float_half(u);
		if ( (u & 0xFFFFFF) == 0)
			printf("=====================0x%08x\r\n", u);
		if (u == UINT_MAX)
			break;
	}
}


