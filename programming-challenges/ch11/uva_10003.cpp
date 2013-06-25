#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;


const int MAXN = 64;
const int INF = 0xffffff;
int n;
int dp[MAXN][MAXN];
int c[MAXN];
int cs[MAXN];

int DP(int l, int r){
  int &s = dp[l][r];
  if (s != INF){
    return s;
  }
  if (l == r){
    s = 0;
  }if (l + 1 == r){
    s = c[l] + c[r];
  }else{
    int total = cs[r] - cs[l - 1];
    for (int i = l; i <= r; i++){
      int t = DP(l, i) + DP(i + 1, r) + total;
      if (s > t){
        s = t;
      }
    }
  }
  return s;
}

int main(){
  int l;
  while (cin >> l && l){
    cin >> n;
    for (int i = 1; i <= n; i++){
      cin >> cs[i];
      c[i] = cs[i] - cs[i - 1];
    }
    n++;
    c[n] = l - cs[n - 1];
    cs[n] = l;
    fill(&dp[0][0], &dp[MAXN - 1][MAXN - 1], INF);
    int ans = DP(1, n);
    cout << "The minimum cutting is " << ans << "." << endl;
  }
}
