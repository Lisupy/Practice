#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;


const int MAXN = 128;
const int MOD = 100*1000*1000;
vector<int> dp[MAXN][MAXN];

void add(vector<int> &a, const vector<int> &b){
  while (a.size() < b.size())
    a.push_back(0);

  for (int i = 0; i < b.size(); i++){
    a[i] += b[i];
  }

  int carry = 0;
  for (int i = 0; i < a.size(); i++){
    a[i] += carry;
    carry = 0;
    if (a[i] >= MOD){
      a[i] -= MOD;
      carry = 1;
    }
  }
  if (carry > 0){
    a.push_back(carry);
  }
}
void BigNum_pr(const vector<int> &a){
  printf("%d", a[a.size() - 1]);
  for (int i = (int)a.size() - 2; i >=0 ;i--){
    printf("%08d", a[i]);
  }
}



void init(){
  for (int i = 0; i < MAXN; i++)
    for (int j = 0; j < MAXN; j++)
      dp[i][j].reserve(100);

  for (int i = 0; i < MAXN; i++){
    dp[0][i].push_back(1);
  }

  for (int i = 1; i < MAXN; i++){
    dp[i][0].push_back(0);
  }
  for (int i = 1; i < MAXN; i++){
    for (int j = 1; j < MAXN; j++){
      dp[i][j] = dp[i-1][j];
      if (i <j)
        add(dp[i][j], dp[i][j-1]);
    }
  }
}

const vector<int> &CatalanNumber(int n){
  return dp[n][n];
}


int main(){
  init(); 
  int n;
  while(scanf("%d", &n) && n!= -1){
    const vector<int> &ans = CatalanNumber(n);
    BigNum_pr(ans);
    printf("\n");
  }
}

