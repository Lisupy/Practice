#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<numeric>
#include<iostream>
#include<algorithm>
using namespace std;


int sol_cnt;
int sol_s;
int sol_al;
int sol_a[1000];
int target;
int a_l;
int a[1000];


void dfs(int start_idx, int depth, int trace[], int s){
  if (start_idx == a_l){
    if (s == sol_s){
      sol_cnt++;
    }else if (s <= target && s > sol_s){
      sol_cnt = 1;
      sol_al = depth;
      copy(trace, trace + depth, sol_a);
      sol_s = s;
    }
  }else{
    int t = 0;
    for (int i = start_idx; i < a_l; i++){
      t = t * 10 + a[i];
      trace[depth] = t;
      if (s + t > target)
        return;
      dfs(i + 1, depth+1, trace, s + t);
    }
  }
}

int main(){
  char buf[12];
  while (scanf("%d%s", &target, buf) && target){
    a_l = strlen(buf);
    for (int i = 0; i < a_l; i++){
      a[i] = buf[i] - '0';
    }
    sol_cnt = 0;
    sol_s = 0;
    int trace[12];
    dfs(0, 0, trace, 0);
    if (sol_cnt == 1){
      printf("%d", sol_s);
      for (int i = 0; i < sol_al; i++){
        printf(" %d", sol_a[i]);
      }
      printf("\n");
    }else if (sol_cnt == 0){
      printf("error\n");
    }else if (sol_cnt >= 2){
      printf("rejected\n");
    }
  }
}




