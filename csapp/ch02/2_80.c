#include<stdio.h>
int A(int n)
{
	return ~((1<<n)-1);
}
int B(int n, int m)
{
	return ((1<<n+m)-1)-((1<<m)-1);
}
int main()
{

}
