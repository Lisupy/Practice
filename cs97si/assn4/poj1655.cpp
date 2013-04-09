#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXT = 32;
const int MAXN = 20*1024;

int t;
int N;

vector<int> link[MAXN];
int descendants_num[MAXN];
int balance[MAXN];
bool visited[MAXN];
int best_balance;
int best_node;
void input(){
  for (int i = 1; i <= N; i++){
    link[i] = vector<int>();
  }

  scanf("%d", &N);
  int s, t;
  for (int i = 0; i < N-1; i++){
    scanf("%d%d", &s, &t);
    link[s].push_back(t);
    link[t].push_back(s);
  }
}

void dfs(int s){
  if(visited[s])
    return;
  visited[s] = true;
  descendants_num[s] = 1;
  balance[s] = 0; 
  for (int i = 0; i < link[s].size(); i++){
    int t = link[s][i];
    if (visited[t])
      continue; 
    dfs(t);
    if (balance[s] < descendants_num[t]){
      balance[s] = descendants_num[t];
    }
    descendants_num[s] += descendants_num[t];
  }
  int up_descendants = N - descendants_num[s];
  if (balance[s] < up_descendants){
    balance[s] = up_descendants;
  }
  if (best_balance > balance[s]){
    best_balance = balance[s];
    best_node = s;
  }
}

void solove(){
  memset(visited, 0, sizeof(visited));
  best_balance = N;  
  dfs(1);
}

void output(){
  printf("%d %d\n", best_node, best_balance);
}


int main(){
  scanf("%d", &t);
  while(t--){
    input();
    solove();
    output();
  }
}
