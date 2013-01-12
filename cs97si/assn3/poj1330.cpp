#include<cstdio>
#include<algorithm>
#include<iostream>
#include<map>
#include<cstring>
using namespace std;

const int MAXN=10010;
int father[MAXN];
bool visited[MAXN];

inline void init(int n){
  memset(father,0,sizeof(father));
  memset(visited, 0, sizeof(visited));
}

inline void set_father(int v, int f){
  father[v] = f;
}

int travel(int v){
  do{
    if (visited[v])
      return v;
    visited[v] = true;
    v = father[v];
  }while(v != 0);
  return v;
}

int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    int N;
    scanf("%d", &N);
    init(N);
    for (int i = 1; i <= N-1; i++){
      int v,f;
      scanf("%d%d", &f, &v);
      set_father(v,f);
    }
    int v1,v2;
    scanf("%d%d",&v1,&v2);
    travel(v1);
    printf("%d\n", travel(v2));
  }
}
