#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
using namespace std;
const bool dbg = false;
const int MAXN = 250*1024;
const int MAXV = 128;
const int MOD = 1000*1000;
int N;
int X[MAXN];
int V[MAXN];
int id[MAXN];
int t[MAXN];

void dbg_p()
{
  if(!dbg)
    return;
  printf("\n======\n");
  for (int i = 0; i < N; i++){
    printf("%2d", i);
  }
  printf("\n");
  for (int i = 0; i < N; i++){
    printf("%2d", X[i]);
  }
  printf("\n");
  for (int i = 0; i < N; i++){
    printf("%2d", V[i]);
  }
  printf("\n");
  for (int i = 0; i < N; i++){
    printf("%2d", id[i]);
  }
  printf("\n=========\n");
}
int psss_count;

inline int lowbit(int x)
{
  return x&-x;
}

inline int count(int a[], int x)
{
  int s = 0;
  while(x!=0){
    if (dbg){
      printf("  %d:%d\n", x, a[x]);
    }
    s+=a[x];
    x-=lowbit(x);
  }
  return s;
}

inline void add(int a[], int an, int x, int t)
{
  while(x<an){
    a[x]+=t;
    x+=lowbit(x);
  }
}

long long reverse_num(int a[], int an)
{
  long long ans = 0;
  int c[MAXV];
  memset(c, 0, sizeof(c));
  for(int i = 0; i < an; i++){
    if(dbg){printf("%d: %d\n",i,a[i]);}
    int cc = count(c, a[i]);
    if(dbg){printf("\n%d\n\n",cc);}
    ans += i - cc;
    add(c, MAXV, a[i] , 1);
  }
  return ans;
}
typedef struct pass_event{
  int timex,timev;
  int shipi, shipj;
  int idx;
  pass_event(int i){
    idx = i;
    shipi = id[i];
    shipj = id[i+1];
    timex = X[i+1]-X[i];
    timev = V[i]-V[i+1];
  }
}pass_event;

struct cmp{
  bool operator()(const struct pass_event &e1, const struct pass_event &e2)
  {
    if(e1.timex*e2.timev==e1.timev*e2.timex)
      return e1.idx>e2.idx;
    return e1.timex*e2.timev>e1.timev*e2.timex;
  }
};
//bool cmp(const struct pass_event &e1, const struct pass_event &e2)
//{
//  return e1.timex*e2.timev>e1.timev*e2.timex;
//}

priority_queue<pass_event, vector<pass_event>, cmp> Q;

void check_and_add_event(int i)
{
  if (0 <= i && i+1 < N){
    if(V[i] > V[i+1]){
      pass_event e(i);
      Q.push(e);
    }
  }
}
void gen(int times)
{
  for (int i = 0; i < N; i++){
    id[i] = i + 1;
  }

  for (int i = 0; i < N - 1; i++){
    check_and_add_event(i);
  }

  for (int i = 0; i < times; i++){
    while(Q.size()){
      dbg_p();
      pass_event e = Q.top(); Q.pop();
      if (dbg){printf("%d: %d %d\n", e.idx, e.shipi, e.shipj);}
      if (id[e.idx] == e.shipi && id[e.idx+1] == e.shipj){
        printf("%d %d\n", e.shipi, e.shipj);
        swap(id[e.idx], id[e.idx+1]);
        swap(X[e.idx],  X[e.idx+1]);
        swap(V[e.idx],  V[e.idx+1]);
        check_and_add_event(e.idx-1);
        check_and_add_event(e.idx+1);
        break;
      }
    }
  }
}

int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++){
    scanf("%d %d", X+i, V+i);
  }
  
  long long pass_times = reverse_num(V, N);
  printf("%d\n", (int)(pass_times % MOD));
  if (pass_times >= 10000)
    pass_times = 10000;
  gen(pass_times);
}
