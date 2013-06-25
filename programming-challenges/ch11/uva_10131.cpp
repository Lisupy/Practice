

#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;


struct Ele{
  int w, s;
  int id;
};

bool cmp1(const Ele &a, const Ele &b){
  return a.w < b.w;
}

const int MAXN = 1024;
Ele es[MAXN];
int n;

int dp[MAXN];
int pre[MAXN];
int main(){
  while (cin >> es[n].w >> es[n].s){
    es[n].id = n + 1;
    n++;
  }

  sort(es, es + n, cmp1);

  fill(pre, pre + n, -1);
  for (int i = 0; i < n; i++){
    dp[i] = 0;
    for (int j = 0; es[j].w < es[i].w; j++){
      if (es[j].s > es[i].s){
        if (dp[j] + 1 > dp[i]){
          dp[i] = dp[j] + 1;
          pre[i] = j;
        }
      }
    }
  }

  vector<int> res;
  int pos = max_element(dp, dp + n) - dp;
  while (pos != -1){
    res.push_back(pos);
    pos = pre[pos];
  }
  reverse(res.begin(), res.end());
  cout << res.size() << endl;
  for (size_t i = 0; i < res.size(); i++){
    cout << es[res[i]].id << endl;
  }
}
