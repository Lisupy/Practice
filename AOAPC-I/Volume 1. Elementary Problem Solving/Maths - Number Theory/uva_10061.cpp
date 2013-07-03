#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
using namespace std;


int N, B;

map<int, int> factors(int n){
  map<int, int> a;
  int len = sqrt(n);
  for (int i = 2; i <= len; i++){
    while (n % i == 0){
      a[i]++;
      n /= i;
    }
  }
  if (n != 1){
    a[n]++;
  }
  return a;
}
int factorsCnt(int n, int m){
  int s = 0;
  while (n){
    s += n / m;
    n /= m;
  }
  return s;
}

int trailingZero(){
  map<int, int> m = factors(B);
  int ans = 0xffffff;
  for (map<int, int>::iterator it = m.begin(); it != m.end(); it++){
    int f = it->first;
    int n = it->second;
    int s = factorsCnt(N, f);
    ans = min(ans, s / n);
  }
  return ans;
}

int digitsNum(){
  double s = 0;
  for (int i = 1; i <= N; i++){
    s += log(i);
  }
  return s / log(B) + 1;
}



int main(){
  while (cin >> N >> B){
    cout << trailingZero() << " " << digitsNum() << endl;
  }
}
