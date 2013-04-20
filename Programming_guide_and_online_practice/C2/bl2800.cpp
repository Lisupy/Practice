#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;


int cnt[256];

int main(){
  char c;
  while(scanf("%c", &c)!=EOF){
    cnt[c]++;
  }

  int height = *max_element(cnt+'A', cnt+'Z'+1);

  while(height){
    int end = 'Z';
    while(cnt[end]<height)
      end--;

    for (int i = 'A'; i <= end; i++){
      if (cnt[i]>=height){
        printf("*");
      }
      else{
        printf(" ");
      }
      if (i == end){
        printf("\n");
      }
      else{
        printf(" ");
      }
    }
    height--;
  }
  for (int i = 'A'; i <= 'Z'; i++){
    printf("%c", i);
    if (i == 'z'){
      printf("\n");
    }
    else{
      printf(" ");
    }
  }
}
