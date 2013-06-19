/*
 * Algorithm:  inverse
 */


#include<iostream>
#include<algorithm>
using namespace std;


struct Range{
  long long l, r;
  Range(){}
  Range(long long _l, long long _r) : l(_l), r(_r) {}
};


Range inverse_f[1024 * 1024];

bool operator<(const Range &a, const Range &b){
  return a.r < b.r;
}

void init(){
  inverse_f[1] = Range(1, 1);
  inverse_f[2] = Range(2, 3);
  for (int i = 3; i < 1024 * 1024; i++){
    long long l = inverse_f[i - 1].r + 1;
    long long len = lower_bound(inverse_f, inverse_f + i, Range(i, i)) - inverse_f;
    long long r = l + len - 1;
    inverse_f[i] = Range(l, r);
  }
}


int main(){
  init();
  long long n;
  while (cin >> n && n){
    long long pos = lower_bound(inverse_f, inverse_f + 1024 * 1024, Range(n, n)) - inverse_f;
    cout << pos << endl;
  }
}
