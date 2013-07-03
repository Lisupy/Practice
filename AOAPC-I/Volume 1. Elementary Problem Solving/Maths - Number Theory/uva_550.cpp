#include<iostream>
#include<cmath>
#include<cassert>
using namespace std;


int solve(int base, int a, int b){
  int k = 0;
  int p = 1;
  int s = a * p - a * b;
  int t = base * b - 1;
  while (s){
 //   int s = a * p - a * b;
    s = s * base + (base  - 1) * a * b;
    s %= t;
    k++;
    p *= base;
  }
  return k + 1;
}

int main(){
  int base, a, b;
  while (cin >> base >> a >> b){
    int ans = solve(base, a, b);
    cout << ans << endl;
  }

}
