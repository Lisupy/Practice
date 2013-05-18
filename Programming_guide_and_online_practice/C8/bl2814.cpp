#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstring>
#include<cctype>
#include<string>
#include<map>
#include<set>
#include<queue>
using namespace std;
const int INF = 0xffffff;
struct {
  int n;
  char clocks[12];
} mvs[] = {
  {1, "ABDE"}, 
  {2, "ABC "},
  {3, "BCEF"},
  {4, "ADG "},
  {5, "BDEFH"},
  {6, "CFI "},
  {7, "DEGH"},
  {8, "GHI "},
  {9, "EFHI"},
};

vector< vector<int> > moves(9, vector<int>());
void init(){
  for (int i = 0; i < 9; i++){
    for (int j = 0; mvs[i].clocks[j]; j++){
      char ch = mvs[i].clocks[j];
      if (isupper(ch)){
        moves[i].push_back(ch-'A');
      }
    }
  }
}



bool DFS(int idx, int end, int next, int a[9], int steps[9]){
  int b_state[9];

  if (idx > end){
    return false;
  }
  if (idx == end){
    memcpy(b_state, a, sizeof(int)*9);
    for (int i = 0; i < 9; i++){
      if (b_state[i]){
        return false;
      }
    }
    for (int i = 0; i < end; i++){
      if (i != 0){
        printf(" ");
      }
      printf("%d", steps[i]+1);
    }
    printf("\n");
    return true;
  }
  for (int i = next; i < 9; i++){
    memcpy(b_state, a, sizeof(int)*9);
    steps[idx] = i;
    const vector<int> &move = moves[i];
    for (size_t j = 0; j < move.size(); j++){
        b_state[move[j]]++;
        b_state[move[j]]%=4;
    }
    bool ok = DFS(idx+1, end, i + 1, b_state, steps);
    if (ok){
      return true;
    }
    steps[idx + 1] = i;
    for (size_t j = 0; j < move.size(); j++){
        b_state[move[j]]++;
        b_state[move[j]]%=4;
    }
    ok = DFS(idx+2, end, i + 1, b_state, steps);
    if (ok){
      return true;
    }
    steps[idx+2] = i;
    for (size_t j = 0; j < move.size(); j++){
        b_state[move[j]]++;
        b_state[move[j]]%=4;
    }
    ok = DFS(idx+3, end, i + 1, b_state, steps);
    if (ok){
      return true;
    }
  }
  return false;
}

int main(){
  init();
  int a[9];
  for (int i = 0; i < 9; i++){
    scanf("%d", &a[i]);
  }
  int steps[32];
  for (int i = 0; i <= 27; i++){
    if (DFS(0, i, 0, a, steps)){
      break;
    }
  }
}
