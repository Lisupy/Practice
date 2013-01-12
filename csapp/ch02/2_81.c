#include <stdio.h>
#include <assert.h>
#include <limits.h>
void A()
{
	int x = INT_MIN;
	int y = 0;
	printf("%d %d\n", x > y, -x < -y);
}
void B()
{
	
}
void C()
{
	int x = 1;
	int y = 1;
	printf("%d %d\n", ~x+~y, ~(x+y));
}
void D()
{
}
void E()
{
	int x = 1;
	printf("%d %d\n", (x>>1) <<1, x);
}
int main()
{
	A();
	B();
	C();
	D();
	E();
}
