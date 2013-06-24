#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

const int MAXN = 1024;

int nk, np;

int nks[MAXN];
vector<int> nps[MAXN];
int mat[MAXN][MAXN];
int match[MAXN];
int visited[MAXN];
int nk_total = 0;


int input(){
  cin >> nk >> np;
  if (nk == 0){
    return 0;
  }
  for (int i = 1; i <= nk; i++){
    cin >> nks[i];
    nks[i] += nks[i - 1];
  }
  nk_total = nks[nk];

  for (int i = 1; i <= np; i++){
    int  j;
    cin >> j;
    nps[i].resize(j);
    for (int k = 0; k < j; k++){
      cin >> nps[i][k];
    }
  }
  return 1;
}

void preprocess(){
  memset(mat, 0, sizeof(mat));
  for (int j = 1; j <= np; j++){
    for (size_t k = 0; k < nps[j].size(); k++){
      int p = nps[j][k];
      for (int u = nks[p - 1]; u < nks[p]; u++){
        mat[j][u] = 1;
      }
    }
  }
}
bool dfs(int u){
  if (visited[u]){
    return false;
  }
  visited[u] = true;
  for (int i = 0; i < MAXN; i++){
    if (mat[u][i]){
      if (match[i] == -1 || dfs(match[i])){
        match[i] = u;
        return true;
      }
    }
  }
  return false;
}

void solve(){
  int matchCnt = 0;
  fill(match, match + MAXN, -1);
  for (int i = 1; i <= np; i++){
    memset(visited, false, sizeof(visited));
    if (dfs(i)){
      matchCnt++;
    }
  }
  //cout << "Fuck" << endl;
  //cout << matchCnt << endl;
  if (matchCnt < nk_total){
    cout << 0 << endl;
    return;
  }
  cout << 1 << endl;
  for (int i = 1; i <= nk; i++){
    bool found = false;
    for (int j = nks[i - 1]; j < nks[i]; j++){
      if (match[j] != -1){
        if (found){
          cout << " ";
        }
        found = true;
        cout << match[j];
      }
    }
    cout << endl;
  }
}

int main(){
  while (input()){
    preprocess();
    solve();
  }
}

