#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;


const int MAXN = 30*1024;
const int MAXP = 100*1024;

int p[MAXN];
int c[MAXN];
int h[MAXN];

int N;
int P;
void dbg(){
  if(true)
    return;
  for (int i = 1; i <= N; i++){
    printf("%2d", i);
  }
  printf("\n");
  for (int i = 1; i <= N; i++){
    printf("%2d", p[i]);
  }
  printf("\n");
  for (int i = 1; i <= N; i++){
    printf("%2d", h[i]);
  }
  printf("\n");
  for (int i = 1; i <= N; i++){
    printf("%2d", c[i]);
  }
  printf("\n");
}
void init(){
  for (int i = 1; i <= N; i++){
    p[i] = i;
    c[i] = 1;
    h[i] = 0;
  }
}

int find(int s)
{
  int root = s;
  int height = 0;
  while(p[root] != root){
    height += h[root];
    root = p[root]; 
  }
  while(p[s] != root){
    int bheight = height - h[s]; 
    int bps = p[s];

    p[s] = root;  
    h[s] = height;
    
    s = bps;
    height = bheight;
  }
  return root;
}

int count(int s)
{
  int root = find(s);
  return c[root] - h[s] - 1;
}

void join(int X, int Y)
{
  int rootX = find(X);
  int rootY = find(Y);
  assert(rootX != rootY); 
  p[rootY] = rootX;
  h[rootY] += c[rootX];
  c[rootX] += c[rootY];
}
int main()
{
  N = MAXN-1;
  init();
  scanf("%d\n", &P);
  while(P--){
    char op;
    scanf("%c", &op);
    if (op == 'M'){
      int X,Y;
      scanf(" %d %d\n", &X, &Y);
      join(X,Y);
    }
    if (op == 'C'){
      int X;
      scanf(" %d\n", &X);
      printf("%d\n", count(X));
    }
    //dbg();
  }
}

