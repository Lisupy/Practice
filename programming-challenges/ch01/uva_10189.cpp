//Algorithm:  brute-forces
//Complexity: O(m * n)
//IndexBased: 1
//Trick:      InPlaced



#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;



const int MAXN = 128;


int FIELD_X = 0;

char field[MAXN][MAXN];
int n, m;

void field_output(){
  for (int i = 1; i <= n; i++){
    printf("%s\n", field[i] + 1);
  }
}

void field_input(){
  memset(field, 0, sizeof(field));
  for (int i = 1; i <= n; i++){
    scanf("%s", field[i] + 1);
  }
  //field_output();
}

void field_process(){
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      if (field[i][j] == '.'){
        char &sum = field[i][j];
        sum = '0';
        for (int di = -1; di <= 1; di++){
          for (int dj = -1; dj <= 1; dj++){
            char ch = field[i + di][j + dj];
            if (ch == '*'){
              sum++;
            }
          }
        }
      }
    }
  }
}

int main(){
  while (scanf("%d%d", &n, &m) && n){
    field_input();
    field_process();
    if (FIELD_X > 0){
      printf("\n");
    }
    printf("Field #%d:\n", ++FIELD_X);
    field_output();
  }
}

