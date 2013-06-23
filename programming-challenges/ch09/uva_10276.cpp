#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const int MAXN = 1310;
vector<int> mat[MAXN];
int used[MAXN];
int path[MAXN];

bool dfs(int p, int n){
  for (size_t j = 0; j < mat[p].size(); j++){
    int i = mat[p][j];
    if (!used[i]){
      used[i] = true;
      if (path[i] == 0 || dfs(path[i], n)){
        path[i] = p;
        return true;
      }
    }
  }
  return false;
}

void build(int n){
  for (int i = 1; i <= n; i++){
    mat[i].clear();
  }
  for (int i = 1; i <= n; i++){
    for (int j = i + 1; j <= n; j++){
      int s = i + j;
      int t = sqrt(s);
      if (t * t == s){
        mat[i].push_back(j);
      }
    }
  }
}
int cache[MAXN];
int get_tower_num(int n){
  if (cache[n] != 0){
    return cache[n];
  }

  build(n);  
  int match_num = 0;
  memset(path, 0, sizeof(path));
  for (int i = 1; i <= n; i++){
    memset(used, 0, sizeof(used));
    if (dfs(i, n)){
      match_num++;
    }
  }
  return cache[n] = n - match_num;
}


int main(){
  int T;
  cin >> T;
  while (T--){
    int N;
    cin >> N;
    int l = 1, r = MAXN;
    while (l < r){
      int mid = (l + r) / 2;
      int need = get_tower_num(mid);
      if (need > N){
        r = mid - 1;
      }else{
        l = mid + 1;
      }
    }
    if (get_tower_num(l) > N){
      l--;
    }
    cout << l << endl;
  }
}
