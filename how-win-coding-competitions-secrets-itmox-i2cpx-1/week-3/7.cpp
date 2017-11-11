#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<numeric>
#include<map>
using namespace std;
struct Range {
  long long tot;
  int L, R;
};
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int B; cin >> B;
  int N; cin >> N;
  vector<Range> gardens(N); for (auto &g: gardens) cin >> g.tot >> g.L >> g.R;
  int M; cin >> M;
  vector<Range> inspectors(M); for (auto &i: inspectors) cin >> i.L >> i.R; 
  map<int, int> index;
  for (auto g: gardens) index[g.L] = index[g.R + 1] = 1;
  for (auto g: inspectors) index[g.L] = index[g.R + 1] = 1;
  int cnt = 0;
  for (auto &it: index) it.second = cnt++;
  vector<Range> Stat(cnt);
  for (auto it: index) {
    Stat[it.second].L = it.first;
    if (it.second - 1 >= 0) Stat[it.second - 1].R = it.first - 1;
  }
  for (auto g: gardens) {
    Stat[index[g.L]].tot += g.tot;
    Stat[index[g.R + 1]].tot -= g.tot;
  }
  {
    long long cur = 0;
    long long lastTot = 0;
    for (auto &s: Stat) {
      cur += s.tot;
      s.tot = lastTot + cur * (s.R - s.L + 1); 
      lastTot = s.tot;
    }
  }
  for (auto i: inspectors) {
    cout << Stat[index[i.R + 1] - 1].tot - (index[i.L] - 1 >= 0?Stat[index[i.L] - 1].tot:0) << endl;
  }
}