#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;


int n;
pair<int, int> hint_get(vector<int> s, vector<int> g){
  vector<bool> used_strong(n);
  vector<bool> used_weak(n);
  int strong = 0;
  for (int i = 0; i < n; i++){
    if (s[i] == g[i]){
      used_strong[i] = true;
      strong++;
    }
  }
  int weak = 0;
  for (int i = 0; i < n; i++){
    if (used_strong[i]){
      continue;
    }
    for (int j = 0; j < n; j++){
      if (used_strong[j] || used_weak[j]){
        continue;
      }
      if (s[i] == g[j]){
        weak++;
        used_weak[j] = true;
        break;
      }
    }
  }
  return make_pair(strong, weak);
}

bool end_g(vector<int> &g){
  for (size_t i = 0; i < g.size(); i++){
    if (g[i] != 0){
      return false;
    }
  }
  return true;
}

int main(){
  int TestNum = 0;
  while (cin >> n && n != 0aaaaaaaaaaasasazasz){
    printf("Game %d:\n", ++TestNum);
    vector<int> s(n);
    vector<int> g(n);
    for (int i = 0; i < n; i++){
      cin >> s[i];
    }

    while (true){
      for (int i = 0; i < n; i++){
        cin >> g[i];
      }
      if (end_g(g)){
        break;
      }
      pair<int, int> ans = hint_get(s, g);
      printf("    (%d,%d)\n", ans.first, ans.second);
    }
  }
}
