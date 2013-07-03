#include<iostream>
#include<cstdio>
using namespace std;


int gcd(int a, int b){
  return b == 0 ? a : gcd(b, a % b);
}


int main(){
  int STEP, MOD;
  while (cin >> STEP >> MOD){
    const char* s = gcd(STEP, MOD) == 1 ? "Good Choice" : "Bad Choice";
    printf("%10d%10d    %s\n\n", STEP, MOD, s);
  }
}
