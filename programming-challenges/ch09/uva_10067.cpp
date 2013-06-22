/*
 * Algorithm:   BFS
 * Complexity:  10^4
 * IndexBased:  0
 * TrciK:
 * LayOut:
 *  struct State{};
 *  visited;
 *  reset();
 *  input();
 *  BFS();
 */

#include<algorithm>
#include<numeric>
#include<iostream>
#include<queue>
#include<cassert>
using namespace std;

struct State{
  int a[4];
  State(){}
  State(int c[4]){
    for (int i = 0; i < 4; i++){
      a[i] = c[i];
    }
  }
  State (int n){
    fromInt(n); 
  }
  void fromInt(int n){
    for (int i = 3; i >= 0; i--){
      a[i] = n % 10;
      n /= 10;
    }
  }
  int toInt(){
    int s = 0;
    for (int i = 0; i < 4; i++){
      s = s * 10 + a[i];
    }
    return s;
  }
};

int step[10 * 1024];

int BFS(int s, int t){
  if (s == t){
    return 0;
  }
  queue<int> Q;
  Q.push(s);
  step[s] = 0;
  while (!Q.empty()){
    int u = Q.front();
    Q.pop();
    int du = step[u];
    State su(u);
    for (int i = 0; i < 4; i++){
      for (int j = -1; j <= 1; j += 2){
        State sv(su);
        sv.a[i] = (sv.a[i] + j + 10) % 10;
        int v = sv.toInt();
        if (step[v] == -1){
          Q.push(v);
          step[v] = du + 1;
        }
      }
    }
  }
  return step[t] >= 0 ? step[t] : -1;
}


int read_st_int(){
  State st;
  for (int i = 0; i < 4; i++){
    cin >> st.a[i];
  }
  return st.toInt();
}

void reset(){
  fill(step, step + 10 * 1024, -1);
}

int main(){
  int N;
  cin >> N;
  while (N--){
    reset();
    int s = read_st_int();
    int t = read_st_int();
    int n;
    cin >> n;
    while (n--){
      int u = read_st_int();
      step[u] = -2;
    }
    int res = BFS(s, t);
    cout << res << endl;
  }
}

