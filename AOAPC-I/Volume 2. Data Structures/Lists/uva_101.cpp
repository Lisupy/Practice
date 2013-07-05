#include<iostream>
#include<vector>
#include<cstdio>
#include<list>
#include<iterator>
#include<algorithm>
using namespace std;



vector<vector<int> > as;

int find_n(int n){
  for (size_t i = 0; i < as.size(); i++){
    vector<int> &a = as[i];
    if (find(a.begin(), a.end(), n) != a.end()){
      return i;
    }
  }
  return -1;
} 

void return_on_n(int ni, int n){
  vector<int> &a = as[ni];
  while (a.back() != n){
    as[a.back()].push_back(a.back());
    a.pop_back();
  }
}

void move_n(int from_i, int n, int to_i){
  vector<int> &from = as[from_i];
  vector<int> &to   = as[to_i];
  vector<int>::iterator it = find(from.begin(), from.end(), n);
  copy(it, from.end(), back_inserter(to));
  from.erase(it, from.end());
}

void debug(){
  for (size_t i = 0; i < as.size(); i++){
    printf("%3lu:  ", i);
    vector<int> &a = as[i];
    for (size_t j = 0; j < a.size(); j++){
      printf("%3d ", a[j]);
    }
    printf("\n");
  }
}
int n;
void init(){
  as.clear();
  as.resize(n);
  for (int i = 0; i < n; i++){
    as[i].push_back(i);
  }
}

void output(){
  for (size_t i = 0; i < as.size(); i++){
    printf("%lu:", i);
    vector<int> &a = as[i];
    for (size_t j = 0; j < a.size(); j++){
      printf(" %d", a[j]);
    }
    printf("\n");
  }
}
int main(){
  cin >> n;
  init();
  string cmd1, cmd2;
  int a, b;
  while (cin >> cmd1 >> a >> cmd2 >> b && cmd1 != "quit"){
    int ai = find_n(a);
    int bi = find_n(b);
    if (ai == bi ){
      continue ;
    } 
    if (cmd1 == "move" && cmd2 == "onto"){
      return_on_n(ai, a);
      return_on_n(bi, b);
    }
    if (cmd1 == "move" && cmd2 == "over"){
      return_on_n(ai, a);
    }
    if (cmd1 == "pile" && cmd2 == "onto"){
      return_on_n(bi, b);
    }
    move_n(ai, a, bi);
  //  debug(); 
  }
  output();
}
  

