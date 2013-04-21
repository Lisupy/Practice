#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

char octal[128];
char decimal[128];


int main(){
  while(cin>>octal){
    printf("%s [8] = ", octal);

    char* floatp = octal + 2;
    int float_len = strlen(floatp);
    unsigned long long ull = 0;
    unsigned long long base = 1;
    for (int i = 0; i < 15; i++){
      base *= 8;
      ull *= 8;
      if (i < float_len){
        ull += floatp[i] - '0';
      }
    }
    if (ull == 0){
      printf("0");
    }
    bool dot_used = false;
    while(ull){
      int d = ull/base;
      printf("%d", d);
      ull %= base;
      ull *= 10;

      if (!dot_used && ull != 0){
        printf(".");
        dot_used = true;
      }
    }
    printf(" [10]\n");
  }
}

    
