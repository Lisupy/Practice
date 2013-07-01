#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;



int main(){
  int CaseNum = 0;
  int N, Q;
  while (scanf("%d %d", &N, &Q)){
    if (N == 0 && Q == 0){
      break;
    }
    printf("CASE# %d:\n", ++CaseNum);
    vector<int> marbles(N);
    for (int i = 0; i < N; i++){
      scanf("%d", &marbles[i]);
    }
    sort(marbles.begin(), marbles.end());
    for (int i = 0; i < Q; i++){
      int q;
      scanf("%d", &q);
      vector<int>::iterator it = lower_bound(marbles.begin(), marbles.end(), q);
      if (it == marbles.end() || *it != q){
        printf("%d not found\n", q);
      }else{
        size_t pos = it - marbles.begin();
        printf("%d found at %lu\n", q, pos + 1);
      }
    }
  }
}
