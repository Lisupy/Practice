#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <assert.h>

typedef unsigned float_bits;
int dbg = 0;
int float_f2i(float_bits f)
{
    unsigned sign = f >> 31;
    unsigned exp  = f >> 23 & 0xFF;
    unsigned frac = (f       & 0x7FFFFF)|0x800000;

    if (exp == 0xFF)
    {
        return 0x80000000;
    }
    if (exp < 0x7F)
        return 0x0;
    exp -= 0x7F;
    if (exp >= 31)
        return 0x80000000;
    
    if (dbg)printf("0x%08x 0x%08x\r\n", frac, exp);
    if (exp > 22)
        frac <<= exp - 23;
    else
        frac >>= 23 - exp;
    if (sign)
        frac = -frac;
    return frac;
}

int float_f2i_real(float f)
{
    if (isnan(f) || isinf(f))
        return 0x80000000;
    if (f > INT_MAX)
        return 0x80000000;
    if (f < INT_MIN)
        return 0x80000000;
    return (int)f;
}


void check_float_f2i(unsigned i)
{
    float_bits  fb  = *(unsigned*)&i;
    float       f   = *(float*)&i;
    
    int         fbi = float_f2i(fb);
    int         fi  = float_f2i_real(f);
    
    //printf("fb = 0x%08x %lf\r\n", *(int*)&fb, *(float*)&fb);
    //printf("f = 0x%08x %lf\r\n", *(int*)&f, *(float*)&f);

    assert(!memcmp(&fb, &f, sizeof(unsigned)));
    if (memcmp(&fbi, &fi, sizeof(unsigned)))
    {
        printf("fb = 0x%08x %lf\r\n", *(int*)&fb, *(float*)&fb);
        printf("f = 0x%08x %lf\r\n", *(int*)&f, *(float*)&f);
        printf("fbi = 0x%08x %lf\r\n", *(int*)&fbi, *(float*)&fbi);
        printf("fi = 0x%08x %lf\r\n", *(int*)&fi, *(float*)&fi);
        dbg = 1;
        float_f2i(fb);
        assert(0);
        
    }
}

int main()
{
    unsigned i = 0;
    for (i = 0; i <= UINT_MAX; i++)
    {
        check_float_f2i(i);
        if ((i & 0xFFFFFF) == 0)
            printf("=============0x%08x=======\r\n", i);
        if (i == UINT_MAX)
            break;
    }
    return 0;
}
