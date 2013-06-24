#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 128;
map<string, int> ids;
string citys[MAXN];
vector<int> lks[MAXN];
bool is_cut[MAXN];
int pre[MAXN];

int dfs_clock = 1;
void reset(){
  dfs_clock = 1;
  ids.clear();
  for (int i = 0; i < MAXN; i++){
    lks[i].clear();
  }
  memset(is_cut, false, sizeof(is_cut));
  memset(pre, 0, sizeof(pre));
}

int dfs(int s, int fa){
  int lows = pre[s] = dfs_clock++;
  int child = 0;
  vector<int> &lk = lks[s];
  for (size_t i = 0; i < lk.size(); i++){
    int t = lk[i];
    if (!pre[t]){
      child++;
      int lowt = dfs(t, s);
      lows = min(lows, lowt);
      if (lowt >= pre[s]){
        is_cut[s] = true;
      }
    }else if (pre[t] < pre[s] && t != fa){
      lows = min(lows, pre[t]);
    }
  }
  if (fa == -1 && child == 1){
    is_cut[s] = false;
  }
  return lows;
}


int N;
int main(){
  int TestNum = 0;
  while (cin >> N && N){
    reset();
    for (int i = 0; i < N; i++){
      string s;
      cin >> s;
      citys[i] = s;
      ids[s] = i;
    }

    int R;
    cin >> R;
    while (R--){
      string s, t;
      cin >> s >> t;
      int si = ids[s];
      int ti = ids[t];
      lks[si].push_back(ti);
      lks[ti].push_back(si);
    }

    for (int i = 0; i < N; i++){
      if(pre[i] == 0){
        dfs(i, -1);
      }
    }

    vector<string> res;
    for (int i = 0; i < N; i++){
      if (is_cut[i]){
        res.push_back(citys[i]);
      }
    }

    sort(res.begin(), res.end());
    if (TestNum){
      cout << endl;
    }
    cout << "City map #" << ++TestNum << ": " << res.size() << " camera(s) found" << endl;
    for (size_t i = 0; i < res.size(); i++){
      cout << res[i] << endl;
    }
  }
}


  



