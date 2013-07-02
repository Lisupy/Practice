#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;


long long P(long long a, long long b){
  return a * (a - 1) * b * (b - 1) / 4;
}


int main(){
  long long TestNum = 0;
  long long a, b;
  while (cin >> a >> b && a){
    cout << "Case " << ++TestNum << ": ";
    cout << P(a, b) << endl;
  }
}
