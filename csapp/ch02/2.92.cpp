/*
 * =====================================================================================
 *
 *       Filename:  2.92.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2011/10/15 17:26:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>

typedef unsigned float_bits;

float_bits float_negate(float_bits f)
{
	unsigned sign = f >> 31;
	unsigned exp = f >> 23 	& 0xFF;
	unsigned frac = f 		& 0x7FFFFF;

	if (exp == 0xFF && frac != 0)
	{
		return -f;
	}
	return f;
}

float float_negate(float f)
{
	if (f != NaN)
		return -f;
	return f;
}

void check_float_negateval(unsigned i)
{
	float f = *(float*)(&i);
	float negatef = float_negate(f);
	unsigned negatei = float_negateval(i);
	if (memcmp(&negatei, &negatef, sizeof(unsigned))) {
		printf("%d\r\n", i);
		printf("i = 0x%08x\r\n", i);
		printf("negatei = 0x%08x\r\n", negatei);
		printf("f = %f\r\n", f);
		printf("negatef = %f\r\n", negatef);

		printf("f = 0x%08x\r\n", *(int*)&f);
		printf("negatef = 0x%08x\r\n", (int*)&negatef);
		assert(0);
	}
}

int main()
{
	unsigned i;
//	check_float_negateval(INT_MIN);
	for (i = 0x7F<<24; i <= UINT_MAX; i++){
		check_float_negateval(i);
		if ((i & ((1<<24) - 1)) == 0)
			printf("0x%08x\r\n", i++);
	}
	return 0;
}
