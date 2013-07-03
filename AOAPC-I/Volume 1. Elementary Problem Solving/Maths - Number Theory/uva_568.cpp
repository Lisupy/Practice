#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;


const int MAXN = 10 * 1024;
int ans[MAXN];


void init(){
  ans[0] = 1;
  long long s = 1;
  for (int i = 1; i < MAXN; i++){
    s *= i;
 //   cout << i << ", " << s << endl;
    while (s % 10 == 0){
      s /= 10;
    }
    s %= 1000 * 1000;
    ans[i] = s % 10;
  }
 // cout << "init Done!" << endl;
}

int main(){
  init();
  int n;
  while (scanf("%d", &n) != EOF){
    printf("%5d -> %d\n", n, ans[n]);
  }
}
