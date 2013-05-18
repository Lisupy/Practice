#include<cstdio>
#include<cstring>
#include<iostream>
#include<numeric>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 100;

int a[MAXN];
bool used[MAXN];
int s;
int n;
int max_a;

bool DFS(int start_idx, int remain, int totalone, int need){
  if (need == 0){
    return true;
  }
  for (int i = start_idx; i < n; i++){
    if (used[i])
      continue;
    if (i - 1 >= 0 && a[i] == a[i -1] && !used[i-1]){
      continue;
    }
    if (remain < a[i]) continue;
    if (remain == a[i]) {
      used[i] = true;
      bool ok = DFS(0, totalone, totalone, need - 1);
      used[i] = false;
      return ok;
    }
    if (remain > a[i]){
      used[i] = true;
      bool ok = DFS(i+1, remain-a[i], totalone, need);
      used[i] = false;
      if (ok){
        return true;
      }
      // 这个优化我没想到
      if (remain == totalone)
        return false;
    }
  }
  return false;
}

int main(){
  
  while (scanf("%d", &n) && n){
    for (int i = 0; i < n; i++){
      scanf("%d", &a[i]);
    }
    memset(used, 0, sizeof(used));

    sort(a, a+n);
    reverse(a, a+n);

    max_a = a[0];

    s = 0;
    for (int i = 0; i < n; i++){
      s += a[i];
    }
  
    int ans = -1;
    for (int i = max_a; i <= s; i++){
      if (s % i != 0) continue;
      int cnt = s / i;
      if (DFS(0, i, i, cnt) ){
        ans = i;
        break;
      }
    }
    printf("%d\n", ans);
  }
}


