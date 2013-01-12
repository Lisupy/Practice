#include <iostream>

using namespace std;
void show_bytes(void* start, int len) {
    int i;
    unsigned char* ff = (unsigned char*) start;
    for (i = 0; i < len; i++)
        printf("%.2X", ff[i]);
    printf("\n");
}
typedef struct
{
    int a;
    int b;
}AAA;

int main()
{
    int x = -5;
    int m = 8;
    cout << x % m << endl;
    cout << (x-((x >> 3)<<3)) << endl;
    
    while(1);
}
