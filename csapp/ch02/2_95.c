#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>


typedef unsigned float_bits;
int dbg = 0;
float_bits float_i2f(int i)
{
    unsigned sign = i<0?1:0;
    unsigned absi = i<0?-i:i;
    unsigned maxb;
    int j;
    unsigned M; 
    unsigned exp; 
    unsigned frac = absi;
    unsigned off = 0;
    if (i == 0)
        return 0;
    for (j = 0; j < 32; j++)
        if ( (1<<j) & absi )
            maxb  = j;
    if (maxb > 23)
    {
        off = maxb - 23;
        if (frac&(1<<off))
            frac += (1<<(off-1));
        else
            frac += (1<<(off-1)) - 1;
    } 
    for (j = 0; j < 32; j++)
        if( (1<<j) & frac)
            M = j;
    exp = 0x7F + M;
    //if(dbg)printf("%08x %08x %08x\r\n", sign, exp, frac);
    //if(dbg)printf("M = %08x\r\n", M);
    if (M > 23)
    {
        frac >>= M - 23;
    }
    else
    {
        frac <<= 23 - M;
    }

    frac &= (1<<23)-1;
    //if(dbg)printf("%08x %08x %08x\r\n", sign, exp, frac);
    return (sign << 31) | (exp << 23) | frac;
}

float float_i2f_real(int i)
{
	return i;
}


void check_float_i2f(int i)
{
    float_bits fb = float_i2f(i);
    float      f  = float_i2f_real(i);
    if (memcmp(&fb, &f, sizeof(unsigned)))
    {
        printf("i = %d 0x%08x %08x\r\n", i, i, -i);
        printf("fb = %d 0x%08x %f\r\n", fb, fb, *(float*)&fb);
        printf("f = %d 0x%08x %f\r\n", *(int*)&f, *(int*)&f, f);
        dbg = 1, float_i2f(i);
        assert(0);
    }

}

int main()
{
    int i;
    for (i = INT_MIN; i <= INT_MAX; i++)
    {
        check_float_i2f(i);
        if ((i & 0xFFFFFF) == 0)
            printf("===========0x%08x===\r\n", i);
        if (i == INT_MAX)
            break;
    }
    return 0;
}
