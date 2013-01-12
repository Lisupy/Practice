#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
bool dbg = true;
const int MAXN = 50*1024;
const int MAXD = 17;
int n;
typedef struct node{
  char label[16];
  int prior;
}node_t;

bool operator<(const node_t &n1, const node_t &n2)
{
  return strcmp(n1.label,n2.label)<0;
}

struct node nodes[MAXN];

int rmq[MAXD][MAXN];

void rmq_init()
{
  for (int i = 0; i < n; i++){
    rmq[0][i] = i;
  }
  int dd = 1;
  for (int d = 1; d < MAXD; d++){
    for (int i = 0; i < n; i++){
      rmq[d][i] = rmq[d-1][i];
      if (i+dd < n){
        if (nodes[rmq[d][i]].prior < nodes[rmq[d-1][i+dd]].prior)
          rmq[d][i] = rmq[d-1][i+dd];
      }
    }
    dd*=2;
  }
}
int rmq_query(int l, int r)
{
  int d = 0;
  int dd = 1;
  while(dd*2<r-l)
    dd*=2,d++;
  int a = rmq[d][l];
  int b = rmq[d][r-dd];
  if (nodes[a].prior > nodes[b].prior)
    return a;
  return b;
}

void dfs(int l, int r)
{
  if (l >= r)
    return;
  
  int root = rmq_query(l,r);
//  if (dbg)printf("==[%d,%d]:%d==",l,r,root);
  printf("(");
  dfs(l, root);
  printf("%s/%d", nodes[root].label, nodes[root].prior);
  dfs(root+1, r);
  printf(")");
}
int main()
{
  while(scanf("%d", &n)&&n){
    for (int i = 0; i < n ; i++){
      scanf(" %[^/]/%d",&nodes[i].label,&nodes[i].prior);
    }
    sort(nodes, nodes+n);
    rmq_init();
    dfs(0,n);
    printf("\n");
  }
}
