#include<algorithm>
#include<cstring>
#include<iostream>
#include<sstream>
#include<cassert>
using namespace std;

const int MAXN = 128;
const int MAXL = 256; 
const long long INF = 2000000000;
int L;
int N;
long long dp[2][MAXL];
int dist[MAXN], cost[MAXN];
int DDD;
int main(){
  int T;
  cin >> T;
  cin.ignore();
  string line1; 
  getline(cin, line1);  
  while (T--){
    cin >> DDD; 
    N = 1;
    dist[0] = 0;
    cin.ignore();
    string line;
    while (getline(cin, line) && line.size() > 0){
    //  cout << "[" << line << "]" << endl;
      istringstream iss(line);
      iss >> dist[N] >> cost[N];
      //assert(0 <= dist[N] && dist[N] <= DDD);
      if (0 <= dist[N] && dist[N] <= DDD){
        N++;
      }else{
    //    cout << 1 / 0 << endl;
      }
    }
    
    N--;
    assert(dist[0] >= 0);
    assert(dist[N] <= DDD);
    fill(&dp[0][0], &dp[1][MAXL - 1] + 1, INF);
    for (int i = 0; i <= 100; i++){
      dp[0][i] = 0;
    }
    for (int i = 1; i <= N; i++){
      int curr = i % 2;
      int prev = (i + 1) % 2;
  //    fill(dp[curr], dp[curr] + MAXL, INF);
      int d = dist[i] - dist[i - 1];
      for (int j = 0; j <= 200; j++){
        dp[curr][j] = INF;
        if (j >= 1){
          dp[curr][j] = min(dp[curr][j], dp[curr][j - 1] + cost[i]);
        }
        if (j + d <= 200){
          dp[curr][j] = min(dp[curr][j], dp[prev][j + d]);
        }
      }
    }
    if (DDD - dist[N] > 100){
      cout << "Impossible" << endl;
      continue;
    }
    long long ans = dp[N % 2][100 + DDD - dist[N]];
    if (ans >= INF){
      cout << "Impossible" << endl;
    }else{
      cout << ans << endl;
    }
    if (T){
      cout << endl;
    }
  }
}



