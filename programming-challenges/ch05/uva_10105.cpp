/*
 * Algorithm: counting, math
 */

#include<iostream>
using namespace std;

long long factorial[32];


void init(){
  long long s = 1;
  factorial[0] = 1;
  for (int i = 1; i < 32; i++){
    s *= i;
    factorial[i] = s;
  }
}

int a[32];
int main(){
  init();
  int n, k;
  while (cin >> n >> k){
    long long s = factorial[n];
    int cnt_a = 0;
    for (int i = 0; i < k; i++){
      cin >> a[i];
      s /= factorial[a[i]];
      cnt_a += a[i];
    }
    if (cnt_a != n){
      s = 0;
    }
    cout << s << endl;
  }
}

