#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;


struct State{
  bool row_occupy[9];
  bool cor_occupy[20];
  bool xcor_occupy[20];

  bool is_valid(int x, int y){
    if (row_occupy[y]){
      return false;
    }
    if (cor_occupy[x + y]){
      return false;
    }
    if (xcor_occupy[x - y + 8]){
      return false;
    }
    return true;
  }
  
  void set(int x, int y){
    row_occupy[y] = true;
    cor_occupy[x + y] = true;
    xcor_occupy[x - y + 8] = true;
  }

  void unset(int x, int y){
    row_occupy[y] = false;
    cor_occupy[x + y] = false;
    xcor_occupy[x - y + 8] = false;
  }
};

State s;
struct Sol{
  int row[9];
};

Sol sol;
vector<Sol> sols;
void DFS(int line){
  if (line == 9){
    sols.push_back(sol);
    return;
  }
  for (int i = 1; i <= 8; i++){
    if (s.is_valid(line, i)){
      s.set(line, i);
      sol.row[line] = i;
      DFS(line + 1);
      s.unset(line, i);
    }
  }
}

int main(){
  DFS(1);
  int n;
  cin >> n;
  while (n--){
    int b;
    cin >> b;
    for (int j = 1; j <= 8; j++){
      printf("%d", sols[b-1].row[j]);
    }
    printf("\n");
  }
}
