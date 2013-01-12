#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;

int N,X;
int lowbit(int X){
  return X&-X;
}
int main()
{
  scanf("%d",&N);
  while(N--){
    scanf("%d", &X);
    printf("%d %d\n", X-lowbit(X)+1, X+lowbit(X)-1);
  }
}
