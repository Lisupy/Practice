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
int C[6013*6000+13];
int tmp[6013*6000+13];
int cnt[257];
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N, M; scanf("%d%d", &N, &M);
  vector<int> A(N); for (auto &a: A) scanf("%d", &a);
  vector<int> B(M); for (auto &b: B) scanf("%d", &b);
  int sz = 0;
  for (auto a: A) {
    for (auto b: B) {
      C[sz++] = a * b;
    }
  }
  for (int i = 0; i < 4; i++) {
    memset(cnt, 0, sizeof(cnt));
    int off = 8 * i;
    for (int j = 0; j < sz; j++) {
      int c = C[j];
      ++cnt[(c >> off) & 255];
    }
    partial_sum(cnt, cnt + 256, cnt);
    for (int j = N * M - 1; j >= 0; j--) {
      tmp[--cnt[(C[j] >> off) & 255]] = C[j];
    }
    for (int j = 0; j < sz; j++) C[j] = tmp[j];
  }
  long long tot = 0;
  for (int i = 0; i < sz; i += 10) tot += C[i];
  cout << tot << endl;
}