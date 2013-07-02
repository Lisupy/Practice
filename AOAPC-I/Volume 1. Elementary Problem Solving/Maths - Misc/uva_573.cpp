#include<iostream>
#include<cmath>
using namespace std;


float H, U, D, F;


int solve(){
  int cnt = 0;
  float s = 0;

  while (s >= 0){
    s += U;
    cnt++;
    if (s > H){
      return cnt;
    }
    s -= D;
    U = U - F; 
    if (U < 0){
      U = 0;
    }
  }
  return -cnt;
}


int main(){
  while (cin >> H >> U >> D >> F && H){
    F = U * F / 100;
    int res = solve();
    if (res >= 0){
      cout << "success on day " << res << endl;
    }else{
      cout << "failure on day " << -res << endl;
    }
  }
}

