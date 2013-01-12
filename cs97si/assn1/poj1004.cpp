#include<iostream>
#include<numeric>
#include<cstdio>
using namespace std;
int main()
{
  double accounts[12];
  for (int i = 0; i < 12; i++)
    scanf("%lf", &accounts[i]);
  double balance = accumulate(accounts, accounts+12, 0.0)/12;
  printf("$%.02f\n", balance);
}

