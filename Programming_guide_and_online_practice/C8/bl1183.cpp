#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iostream>
using namespace std;

int main(){

  long long a, b, c;

  cin >> a;
  long long m, n;
  for (m = a; m > 0; m--){
    if ((a * a + 1) % m == 0 ){
      break;
    }
  }
  n = (a * a + 1) / m;
  b = a + m;
  c = a + n;
  cout << b + c << endl;
}
