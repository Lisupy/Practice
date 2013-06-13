/* 
 * Algorithm:   bits_dp,
 * Complexity: (1<<13)*64*13*13
 * IndexBased:   1
 * Trick:      Index_down_count_for_dp;    
 * LayOut:
 *  input();
 *  reset();
 *  dp();
 *  output();
 */


#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

const int INF = 0xffffff;
int dices[13][5];
int dp[1<<13][64];
int prev1[1<<13][64];
int prev2[1<<13][64];
int prev_round[1<<13][64];
void reset(){
  fill(&dp[0][0], &dp[(1<<13) - 1][63] + 1, -1);
  dp[0][0] = 0;
}

int input(){
  if (cin>>dices[0][0]){
    for (int i = 1; i <= 4; i++){
      cin >> dices[0][i];
    }
    sort(dices[0], dices[0]+5);
    for (int i = 1; i < 13; i++){
      for (int j = 0; j < 5; j++){
        cin >> dices[i][j];
      }
      sort(dices[i], dices[i] + 5);
    }
    return 1;
  }else{
    return 0;
  }
}
int cal_nbits(int n){
  int s = 0;
  while (n){
    s++;
    n &= n -1;
  }
  return s;
}

void process(){
  for (int round = 0; round < 13; round++){
    int (&a)[5] = dices[round];
    for (int st1 = (1 << 13) - 1; st1 >= 0; st1--){
      int nbits = cal_nbits(st1);
      if (nbits != round){
        continue;
      }
      for (int st2 = 63; st2 >=0; st2--){
        int &s = dp[st1][st2];
        if (s == -1){
          continue;
        }
        int score = 0;
        for (int cat = 0; cat < 13; cat++){
          if ((st1 & (1 << cat)) != 0){
            continue;
          }
          score = 0;
          switch(cat){
          case 0:
          case 1:
          case 2:
          case 3:
          case 4:
          case 5:
            for (int i = 0; i < 5; i++){
              if (a[i] == cat + 1){
                score += cat + 1;
              }
            }
            break;
          case 6:
            score = accumulate(a, a + 5, 0);
            break;
          case 7:
            if (a[0] == a[2] || a[1] == a[3] || a[2] == a[4]){
              score = accumulate(a, a + 5, 0);
            }
            break;
          case 8:
            if (a[0] == a[3] || a[1] == a[4]){
              score = accumulate(a, a + 5, 0);
            }
            break;
          case 9:
            if (a[0] == a[4]){
              score = 50;
            }
            break;
          case 10:
            if ((a[0] + 1 == a[1] && a[1] + 1 == a[2] && a[2] + 1 == a[3])
              || (a[1] + 1 == a[2] && a[2] + 1 == a[3] && a[3] + 1 == a[4])){
              score = 25;
            }
            break;
          case 11:
            if (a[0] + 1 == a[1] && a[1] + 1 == a[2] && a[2] + 1 == a[3] && a[3] + 1 == a[4]){
              score = 35;
            }
            break;
          case 12:
            if ((a[0] == a[2] && a[3] == a[4]) || (a[0] == a[1] && a[2] == a[4])){
              score = 40;
            }
            break;
          }
          int next_st1 = st1 | (1 << cat);
          int next_st2 = st2 + (cat < 6 ? score : 0);
          if (next_st2 >= 63 && cat < 6){
            next_st2 = 63;
            if (st2 < 63){
              score += 35; 
            }
          }
          if (s + score > dp[next_st1][next_st2]){
            dp[next_st1][next_st2] = s + score;
            prev1[next_st1][next_st2] = st1;
            prev2[next_st1][next_st2] = st2;
            prev_round[next_st1][next_st2] = round;
          }
        }
      }
    }
  }
}


void output(){
  int best = -1;
  int best_st1, best_st2;
  int st1 = (1 << 13) - 1;
    for (int st2 = 0; st2 < 64; st2++){
      if (dp[st1][st2] > best){
        best = dp[st1][st2];
        best_st1 = st1;
        best_st2 = st2;
      }
    }

  int bouns = 0;
  if (best_st2 == 63){
    bouns = 35;
  }

  int choices[13] = {0};
  while (best_st1 != 0){
    int prev_st1 = prev1[best_st1][best_st2];
    int prev_st2 = prev2[best_st1][best_st2];
    int sel_st = best_st1 ^ prev_st1;
    int sel;
    for (int i = 0; i < 13; i++){
      if ((1 << i) == sel_st){
        sel = i;
        break;
      }
    }
    choices[sel] = dp[best_st1][best_st2] - dp[prev_st1][prev_st2] - (best_st2 >= 63 && prev_st2 < 63? 35 : 0);
    best_st1 = prev_st1;
    best_st2 = prev_st2;
  }

  for (int i = 0; i < 13; i++){
    printf("%d ", choices[i]);
  }
  printf("%d %d\n", bouns, best);
}

int main(){
  while (input()){
    reset();
    process();
    output();
  }
}

            
