#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;



int N;
int a[64];


int main(){
  

  scanf("%d", &N);
  while (N--){
    int L;
    scanf("%d", &L);
    for (int i = 0; i < L; i++){
      scanf("%d", &a[i]);
    }

    int s = 0;
    for (int i = 0; i < L; i++){
      for (int j = i + 1; j < L; j++){
        if (a[i] > a[j]){
          s++;
        }
      }
    }

    printf("Optimal train swapping takes %d swaps.\n", s);
  }
}
