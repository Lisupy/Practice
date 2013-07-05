#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<cctype>
#include<iostream>
using namespace std;


const int MAXN = 10 * 1024;
vector<char> layers[MAXN];

string s;

void dfs(int from, int to, int depth){
  //cout << from << ", " << to << "==>" << depth << endl;
  layers[depth].push_back(s[to]);
  if (from == to){
    return;
  }
  int pos = to - 1;
  int cnt = 0;
  while (cnt != -1){
    if (isupper(s[pos])){
      cnt++;
    }else{
      cnt--;
    }
    pos--;
  }
  dfs(from, pos, depth + 1);
  dfs(pos + 1, to - 1, depth + 1);
}
void reset(){
  for (int i = 0; i < MAXN; i++){
    layers[i].clear();
  }
}

void output(){
  for (int i = MAXN - 1; i >= 0; i--){
    for (vector<char>::reverse_iterator it = layers[i].rbegin(); it != layers[i].rend(); it++){
      cout << *it;
    }
  }
  cout << endl;
}

int main(){
  int T;
  cin >> T;
  while (T--){
    reset();
    cin >> s;
    dfs(0, s.size() - 1, 0);
    output();
  }
}
