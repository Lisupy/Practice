#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<algorithm>
using namespace std;


const int MAXS = 1024;
const int MAXV = 32767;
int S;
int a[MAXS+1][MAXS+1];

inline int lowbit(int x){
  return x&-x;
}

inline void addy(int X, int Y, int A){
  while(Y<=S){
    a[X][Y] += A;
    Y+=lowbit(Y);
  }
}

inline void add(int X, int Y, int A){
  while(X<=S){
    addy(X, Y, A);
    X+=lowbit(X);
  }
}

inline int queryy(int X, int Y){
  int s = 0;
  while(Y>0){
    s += a[X][Y];
    Y -= lowbit(Y);
  }
  return s;
}

inline int query(int X, int Y){
  int s = 0;
  while(X>0){
    s += queryy(X,Y);
    X -= lowbit(X);
  }
  return s;
}

int query_range(int L, int B, int R, int T){
  return query(R,T)-query(R,B-1) - query(L-1,T) + query(L-1,B-1);
}

int main(){
  int I;
  while(scanf("%d", &I)){
    switch(I){
    case 0:
      scanf("%d", &S);
      break;
    case 1:
      int X, Y, A;
      scanf("%d%d%d", &X, &Y, &A);
      add(X+1,Y+1,A);
      break;
    case 2:
      int L, B, R, T;
      scanf("%d%d%d%d", &L, &B, &R, &T);
      printf("%d\n", query_range(L+1,B+1,R+1,T+1));
      break;
    case 3:
      return 0;
    }
  }
}

