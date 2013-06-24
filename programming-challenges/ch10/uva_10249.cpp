#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;


const int MAXN = 128;

int M, N;
int cap[MAXN][MAXN];
int flow[MAXN][MAXN];

int teamTotal;
int tableTotal;
int team[MAXN];
int table[MAXN];
int S, T;

void debug(){
  cout << endl;
  for (int i = 0; i <= T; i++){
    for (int j = 0; j <= T; j++){
      cout << cap[i][j] << "," << flow[i][j] << " ";
    }
    cout << endl;
  }
}

int input(){
  cin >> M >> N;
  if (M == 0){
    return 0;
  }
  for (int i = 1; i <= M; i++){
    cin >> team[i];
  }
  for (int i = 1; i <= N; i++){
    cin >> table[i];
  }
  S = 0, T = M + N + 1;
  teamTotal = 0;
  tableTotal = 0;
  memset(cap, 0, sizeof(cap));
  memset(flow, 0, sizeof(flow));

  //for (int i = 1; i <= M; i++){
  //  cout << team[i];
  //}
  //cout << endl;
  for (int i = 1; i <= M; i++){
    cap[S][i] += team[i];
    teamTotal += team[i];
  }
  //debug();
  for (int i = 1; i <= N; i++){
   cap[i + M][T] += table[i];
   tableTotal += table[i];
  }
  for (int i = 1; i <= M; i++){
    for (int j = 1; j <= N; j++){
      cap[i][j + M] = 1;
    }
  }
  return 1;
}

bool visited[MAXN];
int dfs(int s, int limit){
  if (visited[s]){
    return 0;
  }
  visited[s] = true;
  if (s == T){
    return limit;
  }
  if (cap[s][T] > flow[s][T]){
    int f = dfs(T, min(limit, cap[s][T] - flow[s][T]));
    if (f != 0){
      flow[s][T] += f;
      flow[T][s] -= f;
      return f;
    }
  }
  for (int i = 0; i <= T; i++){
    if (cap[s][i] > flow[s][i]){
      int f = dfs(i, min(limit, cap[s][i] - flow[s][i]));
      if (f != 0){
        flow[s][i] += f;
        flow[i][s] -= f;
        return f;
      }
    }
  }
  return 0;
}
void solve(){
  while (true){
    memset(visited, false, sizeof(visited));
    int ret = dfs(S, 0xffffff);
    if (ret == 0){
      break;
    }
  }
//  debug();
  int s_out = 0;
  for (int i = 0; i <= T; i++){
    s_out += flow[S][i];
  }
  if (s_out != teamTotal){
    cout << "0" << endl;
    return;
  }
  cout << 1 << endl;
  for (int i = 1; i <= M; i++){
    bool found = false; 
    for (int j = 1; j <= N; j++){
      if (flow[i][j + M]){
        if (found){
          cout << " ";
        }
        found = true;
        cout << j;
      }
    }
    cout << endl;
  }
}


int main(){
  while (input()){
    solve();
  }
}

