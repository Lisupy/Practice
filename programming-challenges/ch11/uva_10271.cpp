#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

const long long MAXN = 1024;
const long long MAXL = 2048*3;
const long long MAXK = 2024*3;

long long a[MAXK];
long long b[MAXK];
long long dp[2][MAXL];
long long dp1[2][MAXL];
int K;
int N;
int main(){
  long long T;
  cin >> T;
  while (T--){
    cin >> K >> N;
    for (long long i = 0; i < N; i++){
   //   cin >> a[i];
      int t;
      scanf("%d", &t);
      a[i] = t;
      b[i] = a[i];
    }
    for (long long i = N - 1; i - 1 >= 0; i--){
      a[i] -= a[i - 1];
      a[i] = a[i] * a[i];
    }
    a[N] = 0xffffff; 

    reverse(a + 1, a + N + 1);

    K += 8;
    fill(&dp[0][0], &dp[1][MAXL - 1] + 1, 0xffffff);
    fill(&dp1[0][0], &dp1[1][MAXL - 1] + 1, 0xffffff);
    dp[0][0] = 0;
    for (int i = 0; i <= N; i++){
      dp1[0][i] = 0;
    }
    for (int i = 1; i <= K; i++){
      int curr = i % 2;
      int prev = (i + 1) % 2;
 //     printf("====%d\n", i);
      fill(dp[curr], dp[curr] + MAXL, 0xffffff);
      fill(dp1[curr], dp1[curr] + MAXL, 0xffffff);
      for (int j = i * 3; j <= N; j++){
        if (j - 2 >= 0){
          dp[curr][j] = a[j] + dp1[prev][j - 2];
          dp1[curr][j] = min(dp[curr][j], dp1[curr][j - 1]);
        }
  //      printf("%lld=> %lld %lld   ", a[j], dp[curr][j], dp1[curr][j]);
      }
   //   printf("\n");
    }
    cout << dp1[K % 2][N] << endl;
  }
}

