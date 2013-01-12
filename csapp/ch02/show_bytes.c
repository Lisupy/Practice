#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len) {
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

#define show(type, x) \
	void show_#type(#type x){\
		show_bytes((#type) &x, sizeof( #type )); \
	}\

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void show_short(short x){
	show_bytes((byte_pointer) &x, sizeof(short));
}
int main()
{
	show_int(0x12345678);
	show(float, 1.0);
	return 0;
}
