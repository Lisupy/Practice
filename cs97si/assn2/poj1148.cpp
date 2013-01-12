#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cassert>
using namespace std;


const int MAXN = 10*1024;

int N;
int x[MAXN],y[MAXN];
int dx[MAXN],dy[MAXN];
char sx[5]={0,'+','-','-','+'};
char sy[5]={0,'+','+','-','-'};
int R[MAXN];
inline char get_sign(int n){
  return n<0?'-':'+';
}
inline int set_sign(int n, char c){
  return c=='-'?-n:n;
}
inline char neg_sign(char c){
  return c=='-'?'+':'-';
}
void sol_2d(int d[MAXN],int a[MAXN], char s[5],int R[MAXN]){
  sort(a, a+N);
  int l = 0, r = N-1;
  char sr = s[R[r]];
  char sl = 0;
  if (l % 2 == r % 2)
    sl = sr;
  else
    sl = neg_sign(sr);
  for (int i = r; i > 0; i--){
    if (s[R[i-1]] != sr){
      d[i] = set_sign(a[r], sr);
      r--;
      sr = neg_sign(sr);
    }
    else{
      d[i] = set_sign(a[l],sl);
      l++;
      sl = neg_sign(sl);
    }
  }
  d[0] = set_sign(a[l],sl);
}

int main(){
  scanf("%d",&N);
//  assert(N%2==0);
  for (int i = 0; i <N; i++)
    scanf("%d", x+i);
  for (int i = 0; i <N; i++)
    scanf("%d", y+i);
  for (int i = 0; i <N; i++)
    scanf("%d", R+i);
  sol_2d(dx,x,sx,R);
  sol_2d(dy,y,sy,R);
  for (int i = 0; i < N; i++)
    printf("%c%d %c%d\n", get_sign(dx[i]),abs(dx[i]),get_sign(dy[i]),abs(dy[i]));
}
