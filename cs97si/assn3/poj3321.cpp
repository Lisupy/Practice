#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<list>
#include<cassert>
using namespace std;

const int MAX_N = 100*1024;
const int MAX_M = 100*1024;
int N;
int M;
int g[MAX_N];
int node[MAX_N*2];
int Next[MAX_N*2];

int USED = 1;

int l[MAX_N];
int r[MAX_N];
int apple[MAX_N];
int a[MAX_N];
int NEW = 1;

void build(int root)
{
  assert(node[root] != 0);
  if (l[root] != 0)
    return;
  l[root] = NEW;
  for (int i = g[root]; i !=  0; i = Next[i]) {
    build(node[i]);
  }
  r[root] = NEW++;
}

inline int lowbit(int x){
  return x&-x;
}

int query(int x){
  int s = 0;
  while(x>0){
    s+=a[x];
    x-=lowbit(x);
  }
  return s;
}

void add(int x, int d){
  while(x<MAX_N){
    a[x] += d;
    x+=lowbit(x);
  }
}

void add_fork(int u, int v){
  Next[USED] = g[u];
  node[USED] = v;
  g[u] = USED;
  USED++;
}
int main()
{
  scanf("%d", &N);
  for (int i = 1; i <= N-1; i++){
    int u,v;
    scanf("%d%d", &u, &v);
    add_fork(u,v);
    add_fork(v,u);
  }
  build(1);
  for (int i = 1; i <= N; i++){
    apple[i] = 1;
    add(r[i], 1);
  }

  scanf("%d", &M);
  for (int i = 0; i < M; i++){
    char op[10];
    int x;
    scanf("%s %d", op, &x);
    if (op[0] == 'C'){
      if (apple[x] == 0){
        add(r[x], 1);
        apple[x] = 1;
      }
      else{
        add(r[x], -1);
        apple[x] = 0;
      }
    }
    if (op[0] == 'Q'){
      printf("%d\n", query(r[x]) - query(l[x] - 1));
    }
  }
}
