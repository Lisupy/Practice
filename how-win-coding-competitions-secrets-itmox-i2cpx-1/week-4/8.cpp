#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<functional>
#include<numeric>
#include<map>
#include<set>
#include<cstring>
#include<string>
using namespace std;
int n, m, k;
const int MAXN = 1013 * 1013;
const int MAXM = 5 * 1000 * 1000 * 10 + 13;
char s[MAXM];
int ord[MAXN];
int cnt[256];
int ord2[MAXN];
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d%d%d", &n, &m, &k);
  int sz = 0;
  for (int i = 0; i < m; i++) {
    scanf("%s", s + sz);
    sz += n;
  }
  iota(ord, ord + n, 0);

  for (int i = 0; i < k; i++) {
    memset(cnt, 0, sizeof(cnt));
    sz -= n;
    char *p = s + sz;
    for (int j = sz + n - 1; j >= sz; j--) {
      cnt[s[j]]++;
    }
    partial_sum(cnt, cnt + 256, cnt);
    for (int j = n - 1; j >= 0; j--) {
      ord2[--cnt[p[ord[j]]]] = ord[j];
    }
    for (int j = 0; j < n; j++) ord[j] = ord2[j];
  }
  for (int i = 0; i < n; i++) {
    printf("%d", ord[i] + 1);
    if (i != n - 1) printf(" ");
    else printf("\n");
  }
}