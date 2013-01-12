#include<stdio.h>
#include<limits.h>
#include<assert.h>
#include<math.h>

typedef unsigned float_bits;

float_bits float_negate(float_bits f)
{
	unsigned sign = f>>31;
	unsigned exp = f>>23 & 0xFF;
	unsigned frac = f	 & 0x7FFFFF;
	if (exp != 0xFF || frac == 0) {
		sign = 1-sign;
	}
	return (sign << 31) | (exp << 23)|frac;
}

float float_negate_real(float f)
{
//	return f;
	return isnan(f)?f:-f;
//	return -f;
}


void check_float_negate_val(unsigned i)
{
	float f = *(float*)(&i);
	float negatef = float_negate_real(f);
	unsigned negatei = float_negate(i);
  	float _f = (f!=f)?f:-f;
  	float f1 = f;
	if (memcmp(&negatei, &_f, sizeof(unsigned))) {
		if (isnan(f))
		{
			assert(i == negatei);
			return ;
		}
		printf("i = %d\r\n", i);
		printf("i = 0x%08x\r\n", i);
		printf("negatei = 0x%08x\r\n", negatei);
		printf("negatef = %f\r\n", negatef);

		printf("f1 = 0x%08x\r\n", *(int*)&f1);
		printf("f = %f\r\n", f);
		printf("f = 0x%08x\r\n", *(int*)&f);
		printf("_f = 0x%08x\r\n", *(int*)&_f);
		printf("negatef = 0x%08x\r\n", *(int*)&negatef);
		printf("nan = %f\r\n", NAN);
		printf("infinity = %f\r\n", INFINITY);
		float nan_f = NAN;
		printf("nan = 0x%08x\r\n", *(int*)&nan_f);
		float inf_f = INFINITY;
		printf("inf = 0x%08x\r\n", *(int*)&inf_f);
		assert(0);
		
	}
}

int main()
{
	unsigned i;
//	check_float_negate_val(INT_MIN);
	for (i = 0x0; i <= UINT_MAX; i++){
		check_float_negate_val(i);
		if  ( (i & 0xFFFFFF) == 0)
			printf("==========0x%08x=======\r\n", i);
		if (i == UINT_MAX)
			break;
	}
	return 0;
}
