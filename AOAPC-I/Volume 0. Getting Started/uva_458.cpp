#include<iostream>
#include<algorithm>
#include<cctype>
#include<cstdio>
using namespace std;


int main(){
  char ch;
  while (scanf("%c", &ch) != EOF){
    printf("%c", ch != '\n' ? ch - 7 : ch);
  }
}
