#include<sstream>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
#include<cassert>
using namespace std;
template<typename OutType, typename InType>
OutType simple_cast(InType in){
  stringstream ss;
  ss<<in;
  OutType out;
  ss>>out;
  return out;
}
int tle_reversed_number(int n){
  string tmp = simple_cast<string>(n);
  reverse(tmp.begin(), tmp.end());
  return simple_cast<int>(tmp);
}
int reversed_number(int n){
  char buf[128];
  int len = snprintf(buf, 128, "%d", n);
  assert(0 < len && len < 128);
  reverse(buf, buf+len);
  sscanf(buf, "%d", &n);
  return n;
}
int N;
int main(){
  scanf("%d", &N);
  for (int i = 0; i < N; i++){
    int A, B;
    cin>>A>>B;
    A = reversed_number(A);
    B = reversed_number(B);
    int C= A+B;
    C = reversed_number(C);
    cout << C << endl;
  }
}

