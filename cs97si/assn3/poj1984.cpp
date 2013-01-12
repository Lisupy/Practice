#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
bool dbg = false;
const int MAX_N = 40*1024;
const int MAX_M = 40*1024;
const int MAX_L = 1000;
const int MAX_K = 10*1024;
int N,M;
int K;


int p[MAX_N];
int dis_x[MAX_N];
int dis_y[MAX_N];
void dbg_pr(){
  if(!dbg)
    return;
  printf("==dbg\n");
  for (int i = 1; i <= N; i++)
    printf("%2d ", i);
  printf("\n");
  for (int i = 1; i <= N; i++)
    printf("%2d ", p[i]);
  printf("\n");
  for (int i = 1; i <= N; i++)
    printf("%2d ", dis_x[i]);
  printf("\n");
  for (int i = 1; i <= N; i++)
    printf("%2d ", dis_y[i]);
  printf("\n");
}
void init(){
  for (int i = 1; i <= N; i++){
    p[i] = i;
    dis_x[i] = 0;
    dis_y[i] = 0;
  }
}

int find_p(int s){
  int root = s;
  int x = 0, y = 0;
  while(p[root] != root){
    x += dis_x[root];
    y += dis_y[root];
    root = p[root];
  }

  int t = s;
  while(p[t] != root){
    int tt = p[t];
    int tx = x - dis_x[t];
    int ty = y - dis_y[t]; 
    dis_x[t] = x;
    dis_y[t] = y;
    p[t] = root;
    t = tt;
    x = tx;
    y = ty;
  }
  return root;
}
void join(int F1, int F2, int L, char D){
  int root_F1 = find_p(F1);
  int root_F2 = find_p(F2);
  p[root_F1] = root_F2;
  dis_x[root_F1] = dis_x[F2] - dis_x[F1]; 
  dis_y[root_F1] = dis_y[F2] - dis_y[F1]; 
  switch(D){
    case 'N':
      dis_y[root_F1] -= L;
      break;
    case 'E':
      dis_x[root_F1] -= L;
      break;
    case 'S':
      dis_y[root_F1] += L;
      break;
    case 'W':
      dis_x[root_F1] += L;
      break;
  }
}

int compute(int F1, int F2){
  int root_F1 = find_p(F1);
  int root_F2 = find_p(F2);
  if(dbg)printf("root(%d,%d):%d %d\n", F1, F2, root_F1, root_F2);
  if (root_F1 != root_F2)
    return -1;
  return abs(dis_x[F1] - dis_x[F2]) + abs(dis_y[F1] - dis_y[F2]);
}

typedef struct road{
  int F1, F2;
  int L;
  char D;
}road;
struct road roads[MAX_M];
typedef struct query{
  int idx;
  int F1, F2; 
  int I;
  int ans;
}query;
bool cmpI(const struct query q1, const struct query q2){
  return q1.I < q2.I;
}
bool cmpidx(const struct query &q1, const struct query &q2){
  return q1.idx< q2.idx;
}
struct query querys[MAX_K];
int main(){
  scanf("%d%d", &N, &M);
  init();

  for (int i = 1; i <= M; i++){
    scanf("%d %d %d %c\n", &roads[i].F1, &roads[i].F2, &roads[i].L, &roads[i].D);
  }

  scanf("%d", &K);
  for (int i = 1; i <= K; i++){
    querys[i].idx = i;
    scanf("%d%d%d", &querys[i].F1, &querys[i].F2, &querys[i].I);
  }
  sort(&querys[1], &querys[K+1], cmpI);

  int r = 1;
  for (int i = 1; i <= K; i++){
    if(dbg){printf("query:%d\n", i);} 
    while(r<=querys[i].I){
      if(dbg){
        printf("roads[%d]:%d %d %d %c\n",r, roads[r].F1,roads[r].F2,roads[r].L, roads[r].D);
      }
      join(roads[r].F1, roads[r].F2, roads[r].L, roads[r].D);
      r++;
    }
    dbg_pr();
    if(dbg){
      printf("query[%d]:%d %d\n", i , querys[i].F1, querys[i].F2);
    }
    querys[i].ans = compute(querys[i].F1, querys[i].F2);
  }
  sort(querys+1, querys+K+1, cmpidx);
  for (int i = 1; i <= K; i++){
    if(dbg){
      printf("query[%d]:%d %d\n", i , querys[i].F1, querys[i].F2);
    }
    printf("%d\n", querys[i].ans);
  }
}
