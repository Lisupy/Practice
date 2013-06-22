/*
 * Algorithm:   union-find
 * Complexity:   
 * Trick:       the inverse of the vertex
 * IndexBased   0
 * LayOut:
 *  init();
 *  check();
 */


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cassert>
using namespace std;



const int MAXN = 512;
int n;
int p[MAXN];

void init(){
  for (int i = 0;i < MAXN; i++){
    p[i] = i;
  }
}

int find(int v){
  return (p[v] == v) ? v : ( p[v] = find(p[v]) );
}

void join(int u, int v){
  int pu = find(u);
  int pv = find(v);
  if (pu != pv){
    p[pu] = pv;
  }
}

bool is_valid(){
  for (int i = 0; i < n; i++){
    if (find(i) == find(i + n)){
      return false;
    }
  }
  return true;
}

int main(){
  while (cin >> n && n){
    init();
    int l;
    cin >> l;
    for (int i = 0; i < l; i++){
      int u, v;
      cin >> u >> v;
      join(u, v + n);
      join(v, u + n);
    }
    bool valid = is_valid();
    if (!valid){
      cout << "NOT ";
    }
    cout << "BICOLORABLE." << endl;
  }
}
