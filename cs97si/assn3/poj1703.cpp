#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cctype>

using namespace std;

const int MAX_N = 100*1024;
const int MAX_M = 100*1024;
const int MAX_T = 32;
int T;
int N;
int M;

int p[MAX_N*2];

void Init(int n)
{
  for (int i = 1; i <= n; i++)
    p[i] = i;
}

int Find(int x)
{
  int root = x;
  while(root != p[root])
    root = p[root];
  while(p[x] != root){
    int px = p[x];
    p[x] = root;
    x = px;
  }
  return root;
}

void Union(int x, int y)
{
  int rx = Find(x);
  int ry = Find(y);
  p[rx] = ry;
}

int main()
{
  scanf("%d\n", &T);
  while(T--){
    scanf("%d%d\n", &N,&M);
    Init(2*N);
    while(M--){
      char op;
      int a,b;
      scanf("%c %d %d\n", &op, &a, &b); 
      if (op == 'A'){
        int ra = Find(a);
        int ropa = Find(a+N);
        int rb = Find(b);
        if (ra == rb){
          printf("In the same gang.\n");
        }
        else if (ropa == rb){
          printf("In different gangs.\n");
        }
        else{
          printf("Not sure yet.\n");
        }
      }
      if (op == 'D'){
        Union(a,  b+N);
        Union(a+N,b);
      }
    }
  }
}
