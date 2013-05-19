// dp[i][used][score_diff]
// dp_score[i][used][score_diff]
// 数组偏移，+1


#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 0xFFFFFF;
const int MAXN = 201;
const int MAXM = 21;
const int MAXSCORE = 20 * MAXM  * 2 + 1;

int s1[MAXN], s2[MAXN];
bool dp[MAXN][MAXM][MAXSCORE];
int dp_score[MAXN][MAXM][MAXSCORE];

struct Trace{
  int i, j, k;
};
Trace dp_trace[MAXN][MAXM][MAXSCORE];

int score_to_int(int score){
  return score + MAXSCORE / 2;
}

int int_to_score(int i){
  return i - MAXSCORE / 2;
}

void reset(){
 // fill(&dp[0][0][0], &dp[MAXN - 1][MAXM - 1][MAXSCORE-1] + 1, false);
 memset(dp, 0, sizeof(dp));
//  fill(&dp_score[0][0][0], &dp_score[MAXN - 1][MAXM - 1][MAXSCORE - 1] + 1, 0);
  memset(dp_score, 0, sizeof(dp_score));
  dp[0][0][score_to_int(0)] = true;
}

int n, m;
void pr_trace(int i, int j, int k){
  Trace &tr = dp_trace[i][j][k];
  if (i == 0 || j == 0 || k == 0){
    return ;
  }
  if (tr.j == j){
    pr_trace(tr.i, tr.j, tr.k);
  }else{
    pr_trace(tr.i, tr.j, tr.k);
    printf(" %d", i);
  }
}
int main(){
  int TEST_CASE = 0;
  while (scanf("%d %d", &n, &m) != EOF){
    for (int i = 1; i <= n; i++){
      scanf("%d %d", &s1[i], &s2[i]);
    }

    reset();

    for (int i = 1; i <= n; i++){
      for (int j = 0; j<= m; j++){
        for (int k = 0; k < MAXSCORE; k++){
          bool &s = dp[i][j][k];
          Trace &tr = dp_trace[i][j][k];
          int &score = dp_score[i][j][k];

          s = dp[i-1][j][k];
          tr = {i - 1, j, k}; 
          score = dp_score[i-1][j][k]; 

          int diff = s1[i] - s2[i];
          int t = k - diff;
          if (0 <= t && t < MAXSCORE && 0 <= j-1&& dp[i-1][j-1][t]){
            if (!s || score < dp_score[i-1][j-1][t] + s1[i] + s2[i]){
              s = dp[i-1][j-1][t];
              tr = {i-1, j-1, t};
              score = dp_score[i-1][j-1][t] + s1[i] + s2[i];
            }
          }
          if (s){
        //    printf("%d %d %d(%d) ,%dn", i, j, k, int_to_score(k), score);
          }
        }
      }
    }

    int ans_diff = INF;
    int ans_score = 0; 
    for (int i = 1; i < MAXSCORE; i++){
      int score = int_to_score(i);
      if (dp[n][m][i]){
        if (abs(ans_diff) > abs(score)){
          ans_diff = score;
          ans_score = dp_score[n][m][i];
        }else if (abs(ans_diff) == abs(score)){
          if (ans_score < dp_score[n][m][i]){
            ans_diff = score;
            ans_score = dp_score[n][m][i];
          }
        }
      }
    }

    printf("Jury #%d\n", ++TEST_CASE);
    printf("Best jury has value %d for prosecution and value %d for defence:\n", (ans_score + ans_diff)/2, (ans_score - ans_diff)/2);

    pr_trace(n, m, score_to_int(ans_diff));
    printf("\n");
  }
}


