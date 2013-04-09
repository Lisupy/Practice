#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;


const int MAXN = 1024*8;

char s[MAXN];
int dp[4][MAXN];
int N;

int main(){
  scanf("%d",&N);
  scanf("%s", s);
  fill(dp[0], dp[0]+N, 0);
  fill(dp[1], dp[1]+N, 0);
  for (int range_len = 2; range_len <= N; range_len++){
    int idx = range_len%4;
    int last_idx = (range_len-1)%4;
    int last_idx2 = (range_len-2)%4;
    for (int left = 0; left + range_len <= N; left++){
    //  vector<int> a;
    //  a.push_back(dp[last_idx][left]+1);
    //  a.push_back(dp[last_idx][left+1]+1);
    //  a.push_back(dp[last_idx2][left+1]+(s[left]==s[left+range_len-1]?0:2));
    //  dp[idx][left] =*min_element(a.begin(),a.end());
      dp[idx][left]=min(min(dp[last_idx][left]+1,dp[last_idx][left+1]+1),dp[last_idx2][left+1]+(s[left]==s[left+range_len-1]?0:2));
    }
  }
  printf("%d\n", dp[N%4][0]);
}

