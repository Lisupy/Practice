/*
 *  0
 * 1 2
 *  3
 * 4 5
 *  6
 */


#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;


int used[10][7] = {
//{0, 1, 2, 3, 4, 5, 6}
  {1, 1, 1, 0, 1, 1, 1}, //0
  {0, 0, 1, 0, 0, 1, 0}, //1
  {1, 0, 1, 1, 1, 0, 1}, //2
  {1, 0, 1, 1, 0, 1, 1}, //3
  {0, 1, 1, 1, 0, 1, 0}, //4
  {1, 1, 0, 1, 0, 1, 1}, //5
  {1, 1, 0, 1, 1, 1, 1}, //6
  {1, 0, 1, 0, 0, 1, 0}, //7
  {1, 1, 1, 1, 1, 1, 1}, //8
  {1, 1, 1, 1, 0, 1, 1}, //9
};

void pr_nc(char c, size_t n){
  while(n--){
    printf("%c", c);
  }
}
void print_line(size_t l, char* str, size_t s){
  for (int i = 0; str[i]; i++){
    char ch = str[i];
    int n = ch - '0';
    if (i != 0)
      printf(" ");
    printf(" ");
    if (used[n][l]){
      pr_nc('-', s);
    }else{
      pr_nc(' ', s);
    }
    printf(" ");
  }
  printf("\n");
}
void print_row(size_t r1, size_t r2, char* str, size_t s){
  for (int i = 0; str[i]; i++){
    char ch = str[i];
    int n = ch - '0';
    if (i != 0)
      printf(" ");
    if (used[n][r1]){
      printf("|");
    }else{
      printf(" ");
    }
    pr_nc(' ', s);
    if (used[n][r2]){
      printf("|");
    }else{
      printf(" ");
    }
  }
  printf("\n");
}
void print(char* str, size_t s){
  print_line(0, str, s);
  for (size_t i = 0; i < s; i++)
    print_row(1, 2, str, s);
  print_line(3, str, s);
  for (size_t i = 0; i < s; i++)
    print_row(4, 5, str, s);
  print_line(6, str, s);
}

int main(){
  int s;
  char n_str[64];
  while(scanf("%d%s", &s, n_str) && s){
    print(n_str, s);
    printf("\n");
  }
}

