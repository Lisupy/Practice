#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;


void solve(int n){
  int t = sqrt(n);
  if (t * t == n){
    if (t % 2 == 0){
      cout << t << " " << 1 << endl;
    }else{
      cout << 1 << " " << t << endl;
    }
  }else{
    n -= t * t;
    if (t >= n){
      if (t % 2 == 0){
        cout << t + 1 << " " << n << endl;
      }else{
        cout << n << " " << t + 1 << endl;
      }
    }else{
      n = 2 * t + 1 - n;
      if (t % 2 == 0){
        cout << n + 1 << " " << t + 1 << endl;
      }else{
        cout << t + 1 << " " << n + 1 << endl;
      }
    }
  }
}

int main(){
  int N;
  while (cin >> N && N){
    solve(N);
  }
}
