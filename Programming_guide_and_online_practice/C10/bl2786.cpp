//Algorithm:  for 
//Complexity: O(K)
//Trick:      None;
//FirstPos:   1


#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

const int MAXK = 1024*1024;
const int MOD = 32767;

int a[MAXK];

void init(){
  a[1] = 1;
  a[2] = 2;
  for (int i = 3; i < MAXK; i++){
    a[i] = (2 * a[i-1] + a[i-2]) % MOD;
  }
}

int main(){
  init();

  int n;
  scanf("%d", &n);
  while (n--){
    int k;
    scanf("%d", &k);
    printf("%d\n", a[k]);
  }
}


