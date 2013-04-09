#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<limits>
using namespace std;

const int MAXN = 128;
int m[MAXN][MAXN];
int sum[MAXN][MAXN];
int ans = numeric_limits<int>::min();
int N;

int main(){
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      scanf("%d", &m[i][j]);


//  for (int i = 0; i < N; i++)
//    partial_sum(m, m+N, sum);

  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      m[i][j] += m[i-1][j];


  for (int l1 = 1; l1 <= N; l1++){
    for (int l2 = l1+1; l2 <= N+1; l2++){
      int s = 0;
      for (int i = 0; i < N; i++){
       // s += value(l1, l2, i);
        s += m[l2-1][i] - m[l1-1][i];
        if (s > ans) ans = s;
        if (s < 0) s = 0;
      }
    }
  }
  printf("%d\n", ans);
}
