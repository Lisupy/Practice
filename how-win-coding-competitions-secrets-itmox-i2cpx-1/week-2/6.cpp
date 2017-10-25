#include<iostream>
#include<queue>
#include<cstdio>
#include<stack>
#include<string>
#include<numeric>
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; scanf("%d", &N);
  vector<int> top(N + 1);
  vector<long long> sum(N + 1);
  vector<int> prev(N + 1);
  prev[0] = -1;
  for (int i = 1; i <= N; i++) {
    int t, m; scanf("%d%d", &t, &m);
    if (m != 0) {
      prev[i] = t;
      top[i] = m;
      sum[i] = sum[t] + m;
    } else {
      prev[i] = prev[prev[t]];
      top[i] = top[prev[t]]; 
      sum[i] = sum[prev[t]];
    }
  }
  cout << accumulate(sum.begin(), sum.end(), 0ll) << endl;
}