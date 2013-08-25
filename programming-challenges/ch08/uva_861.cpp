/*
 * Algorithm:   dp
 * Complexicy:  2^N * N
 * IndexBased:  0
 * Trick:       bits state
 * LayOut:
 *  DFS()
 */

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<utility>
using namespace std;

const int MAXN = 8;

int dfs(int n, int x, int y, int k, int diagmask, int bdiagmask, int parity){
  if (k == 0){
    return 1;
  }
  int s = 0;
  while (x < n){
    while (y < n){
      int diag = 1 << (x + y);
      int bdiag = 1 << (x - y + n);
      if ((x + y) % 2 != parity || (diag & diagmask) || (bdiag & bdiagmask)){
        y++;
        continue;
      }
      s += dfs(n, x, y + 1, k - 1, diagmask | diag, bdiagmask | bdiag, parity);
      y++;
    }
    x++;
    y = 0;
  }
  return s;
}

int cache[MAXN + 1][MAXN * MAXN + 1];
int cache1[MAXN + 1][MAXN * MAXN + 1][2];
int dfs1(int n, int k, int parity){
  int &s = cache1[n][k][parity];
  if (s != -1){
    return s;
  }
  return s = dfs(n, 0, 0, k, 0, 0, parity);
}

int main(){
  int n, k;
  fill(&cache[0][0], &cache[MAXN][MAXN * MAXN], -1);
  fill(&cache1[0][0][0], &cache1[MAXN][MAXN * MAXN][1] + 1, -1);
  while (cin >> n >> k && n){
    int &s = cache[n][k];
    if (s == -1){
      s = 0;
      for (int i = 0; i <= k; i++){
        s += dfs1(n, i, 0) * dfs1(n, k - i, 1);
      }
    }
    cout << s << endl;
  }
}
    
