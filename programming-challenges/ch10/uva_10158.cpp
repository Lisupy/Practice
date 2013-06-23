#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;


const int MAXN = 1024 * 20;


int p[MAXN];

void p_init(){
  for (int i = 0; i < MAXN; i++){
    p[i] = i;
  }
}

int find(int u){
  return p[u] == u ? u : (p[u] = find(p[u]));
}

void join(int u, int v){
  int pu = find(u);
  int pv = find(v);
  if (pu != pv){
    p[pu] = pv;
  }
}


int main(){
  int n;
  cin >> n;
  p_init();
  int c, x, y;
  while (cin >> c >> x >> y && c){
    switch(c){
    case 1:
      if (find(x) == find(y + n)){
        cout << -1 << endl;
        break;
      }
      join(x, y);
      join(x + n, y + n);
      break;
    case 2:
      if (find(x) == find(y)){
        cout << -1 << endl;
        break;
      }
      join(x, y + n);
      join(x + n, y);
      break;
    case 3:
      if (find(x) == find(y)){
        cout << 1 << endl;
      }else{
        cout << 0 << endl;
      }
      break;
    case 4:
      if (find(x) == find(y + n)){
        cout << 1 << endl;
      }else{
        cout << 0 << endl;
      }
      break;
    }
  }
}

