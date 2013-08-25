#include<iostream>
#include<cstdio>
using namespace std;

void solve(int n){
  if (n == 0){
    cout << 0 << " " << 0 << endl;
    return;
  }
  int t = 1;
  while (n > t * 6){
    n -= t * 6;
    t++;
  }

  if (n < t){
    cout << t - n << " " << n << endl;
    return;
  }

  n -= t;
  if (n < t){
    cout << -n << " " << t  << endl;
    return;
  }

  n -= t;
  if (n < t){
    cout << -t << " " << t - n << endl;
    return;
  }

  n -= t;
  if (n < t){
    cout << -(t - n) << " " << -n << endl;
    return;
  }

  n -= t;
  if (n < t){
    cout << n << " " << -t << endl;
    return;
  }
  n -= t;
  cout << t << " " << -(t - n) << endl;
}

int main(){
  int n;
  while (cin >> n){
    solve(n - 1);
  }
}
