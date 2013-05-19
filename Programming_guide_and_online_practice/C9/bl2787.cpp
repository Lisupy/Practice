#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<cstring>
#include<cctype>
using namespace std;


int a[4];
bool used[4];

enum ExpType{
  Value,
  OP
};
struct Exp{
  ExpType type;
  double value;
  char op;
};

Exp dfs_trace[7];

Exp ops[4] = {
  {OP, 0, '+'},
  {OP, 0, '-'},
  {OP, 0, '*'},
  {OP, 0, '/'},
};

bool DFS(int value_cnt, int op_cnt){
  if (value_cnt == 4 && op_cnt == 3){
    Exp s[7];
    int l = 0;
    for (int i = 0; i < 7; i++){
      Exp &e = dfs_trace[i];
      if (e.type == OP){
        double rhs = s[--l].value;
        double lhs = s[--l].value;
        double res = 0;
        switch(e.op){
        case '+': res = lhs + rhs; break;
        case '-': res = lhs - rhs; break;
        case '*': res = lhs * rhs; break;
        case '/': if (rhs != 0)res = lhs / rhs; break;
        }
        s[l].type = Value;
        s[l].value = res;
        l++;
      }else{
        s[l++] = e;
      }
    }
    return fabs(s[0].value - 24) < 1e-6;
  }else{
    if (value_cnt - op_cnt >= 2){
      for (int i = 0; i < 4; i++){
        dfs_trace[value_cnt+op_cnt] = ops[i];
        bool ok = DFS(value_cnt, op_cnt + 1);
        if (ok){
          return true;
        }
      }
    }
    for (int i = 0; i < 4; i++){
      if (!used[i]){
        used[i] = true;
        dfs_trace[value_cnt+op_cnt].type = Value;
        dfs_trace[value_cnt+op_cnt].value = a[i];
        bool ok = DFS(value_cnt + 1, op_cnt);
        used[i] = false;
        if (ok){
          return true;
        }
      }
    }
    return false;
  }
  return false;
}

int main(){
  while (cin >> a[0] >> a[1] >> a[2] >> a[3] && a[0]){
    bool ok = DFS(0, 0);
    if (ok){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
}
