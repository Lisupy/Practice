/*
 * Algorithm: 
 */

#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;


long long f(long long m){
 // cout << m << endl;
  long long result = m;
  for (long long n = 0; n < sqrt(m); n++){
    long long sn = n * (1 + n);
    long long tk = m - sn;
    long long t = (tk + n) / (n + 1);
    result = min(result, t + 2 * n);
  }
  return result;
}


int main(){
  long long x, y;
  int n;
  cin >> n;
  while (n--){
    cin >> x >> y;
    cout << f(y - x) << endl;
  }
}


