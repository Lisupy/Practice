#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;


char image[32][32];
int N;

int a[32];


int main(){
  while (scanf("%d\n", &N) && N){
    for (int i = 0; i < N; i++){
      fgets(image[i], 32, stdin);
    }

    for (int i = 0; i < N; i++){
      a[i] = 0;
      for (int j = 0; j < 25; j++){
        if (image[i][j] == 'X'){
          a[i]++;
        }
      }
    }

    int max_a = *max_element(a, a + N);

    int cnt = 0;
    for (int i = 0; i < N; i++){
      cnt += max_a - a[i];
    }

    printf("%d\n", cnt);
  }
}
