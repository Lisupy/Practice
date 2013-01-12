#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

const bool dbg = false;
const int MAXN = 128*1024;
int N;
int M;

int Min[MAXN*2*4  +1];
int Max[MAXN*2*4  +1];
int LMin[MAXN*2*4 +1];
int LMax[MAXN*2*4 +1];
int RMin[MAXN*2*4 +1];
int RMax[MAXN*2*4 +1];
int Sum[MAXN*2*4  +1];
int a[MAXN];
int S;

#define m ((l+r)/2)
#define lson l,m,(idx*2)
#define rson (m+1),r,(idx*2+1)
#define root l,r,idx

void pushup(int l, int r, int idx){
  assert((lson)<= MAXN*2*4);
  assert((rson)<= MAXN*2*4);
  assert((root)<= MAXN*2*4);
  LMin[idx] = min(LMin[lson], Sum[lson]+LMin[rson]);
  LMax[idx] = max(LMax[lson], Sum[lson]+LMax[rson]);
  RMin[idx] = min(RMin[rson], Sum[rson]+RMin[lson]);
  RMax[idx] = max(RMax[rson], Sum[rson]+RMax[lson]);
  Sum[idx]  = Sum[lson] + Sum[rson];
  Min[idx]  = min(min(Min[lson], Min[rson]), RMin[lson]+LMin[rson]);
  Max[idx]  = max(max(Max[lson], Max[rson]), RMax[lson]+LMax[rson]);
}

void update(int l, int r, int idx, int L, int R, int value){
  if (R<l || r < L)return;
  if (l == r){
    Min[idx]  = value;
    LMin[idx] = value;
    RMin[idx] = value;
    Max[idx]  = value;
    LMax[idx] = value;
    RMax[idx] = value;
    Sum[idx]  = value;
    return;
  }
  update(lson, L, R, value);
  update(rson, L, R, value);
  pushup(root);
}

int main()
{
  scanf("%d", &N);
  for (int i = 1; i <= N; i++){
    scanf("%d", a+i);
  }

  if(dbg) cout<<"=="<<endl;
  for (int i = 1; i <= N; i++){
    S+=a[i];
    update(1,2*N, 1, i  , i  , a[i]);
    update(1,2*N, 1, i+N, i+N, a[i]);
  }

  if(dbg)cout<<"=="<<S<<endl;

  scanf("%d", &M);
  while(M--){
    int A,B;
    scanf("%d%d", &A, &B);
    S = S - a[A] + B;
    a[A] = B;
    update(1, 2*N, 1, A,   A,   a[A]);
    update(1, 2*N, 1, A+N, A+N, a[A]);
    if(dbg)printf(" %d, %d, %d\n", S, Min[1], Max[1]);
    if(S>0){
      printf("%d\n", S-Min[1]);
    }
    else{
      printf("%d\n", Max[1]);
    }
  }
}
