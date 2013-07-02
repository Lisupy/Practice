#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;


long long sum1toN(long long n){
  return n * (n + 1) / 2;
}

long long solve(long long k){
  long long n = 1;
  while (sum1toN(n) < k ||  (sum1toN(n) - k) % 2 != 0){
    n++;
  }
  return n;
}

int main(){
  long long TestNum = 0;
  cin >> TestNum;
  while (TestNum--){
    long long k;
    cin >> k;
    cout << solve(abs(k)) << endl;
    if (TestNum){
      cout << endl;
    }
  }
}

