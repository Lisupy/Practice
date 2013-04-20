//dp(n,m)  0<=n<=30, 0<=m<=12
//ans = dp(30,12)
//dp(n,m) = min{dp(k,m-1)+cost(k,n)}  0<=k<=n
//dp(0,0) = 0
//
//cost(b,e) = sum{ (k-(b-1))*w[k]}  b<=k<e
//          = cost(0,e)-cost(0,b) - sum(b,e)*b
//
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<cassert>
#include<numeric>
using namespace std;


int w[31];
int cost0[31];
int sum0[31];

int dp[31][13];
int trace[31][13];
int t;


int get_ord(char ch){
  switch(ch){
  case 'a'...'z':return ch-'a';
  case '+':     return 'z'-'a'+1;
  case '*':     return 'z'-'a'+2;
  case '/':     return 'z'-'a'+3;
  case '?':     return 'z'-'a'+4;
  }
  assert(0);
  return -1;
}

char get_chr(int ord){
  switch(ord){
  case 0 ... 25:return 'a'+ord;
  case 26:   return '+';
  case 27:   return '*';
  case 28:   return '/';
  case 29:   return '?';
  }
  assert(0);
  return -1;
}

int Sum(int begin, int end){
  return sum0[end]-sum0[begin];
}

int cost(int begin, int end){
  return cost0[end] - cost0[begin] - Sum(begin,end)*begin;
}

int main(){
  (void)scanf("%d", &t);
  while(t--){
    
    int M;
    scanf("%d", &M);
    fill_n(w, 30, 0);
    while(M--){
      char buf[32];
      (void)scanf("%s", buf);
      for(int i = 0; buf[i]; i++)
        w[get_ord(buf[i])]++;
    } 

    partial_sum(w, w+31, sum0+1);
    for (int i = 0; i < 31; i++)
      cost0[i+1] = w[i]*(i+1) + cost0[i];

    for (int i = 0; i < 31; i++){
      for (int j = 0; j < 13; j++){
        dp[i][j] = 0xfffffff;
      }
    }
    dp[0][0] = 0;
    

    for (int i = 0; i < 31; i++){
      for (int j = 1; j < 13; j++){
        for (int k = 0; k < i; k++){
          int cs = dp[k][j-1]+cost(k,i);
          if (dp[i][j] > cs){
            dp[i][j] = cs;
            trace[i][j] = k;
          }
        }
      }
    }

    vector<int>  ans(12,0);
    int i = 30, j = 12;
    while(j){
      int prev = trace[i][j];
      ans[j-1] = prev;
      i = prev;
      j = j - 1;
    }

    for (size_t i = 1; i < ans.size(); i++){
      printf("%c", get_chr(ans[i]));
    }
    printf("\n");
  }
}

    
