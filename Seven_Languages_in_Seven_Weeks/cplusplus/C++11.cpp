

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int foo(int x)
{
	return x;
}
int main()
{
	[] { cout << "Hello, World" << endl; } ();
	
	
	int i = 1024;
    auto func = [=] { printf("%d\n", i); };
    func();
    
    int&& s = 0;
    int arr[4];
	for (const int& x : {0,1,2})
    	s=max(s,foo(x));
	printf("%d", s);
	for (const int& x : arr)
    	s=max(s,foo(x));
    //generate_n (myarray, 9, UniqueNumber);
	system("Pause");
}
