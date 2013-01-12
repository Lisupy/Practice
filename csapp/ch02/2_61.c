#include<stdio.h>
#include<assert.h>

int test_all_bits_one(int x)
{
	return !~x;
}

int test_all_bits_zero(int x)
{
	return !x;
}

int test_msB_all_bits_one(int x)
{
	return test_all_bits_one(x>>((sizeof(int) -1) << 3));
}

int test_lsB_all_bits_zero(int x)
{
	return test_all_bits_zero(x<<((sizeof(int) -1) << 3));
}

int main()
{
	assert(test_all_bits_one(-1) == 1);
	assert(test_all_bits_one(0) == 0);
	assert(test_all_bits_one(1) == 0);

	assert(test_all_bits_zero(0) == 1);
	assert(test_all_bits_zero(1) == 0);

	assert(test_msB_all_bits_one((int)0xFF000000) == 1);
	assert(test_msB_all_bits_one((int)0x00FFFFFF) == 0);

	assert(test_lsB_all_bits_zero((int)0xFFFFFF00) == 1);
	assert(test_lsB_all_bits_zero((int)0x000000FF) == 0);

	puts("OK!");
	return 0;
}
