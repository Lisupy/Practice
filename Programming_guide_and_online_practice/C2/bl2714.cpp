#include<iostream>
#include<cstdio>
using namespace std;

int n;
double sum;
double a;

int main(){
  cin>>n;
  for (int i = 0; i < n; i++){
    cin>>a;
    sum+=a;
  }
  printf("%.2f", sum/n);
}
