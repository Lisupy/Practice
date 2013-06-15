/*
 * Algorithm: sort, find
 * Complexity: sort
 * IndexBased: 0
 * Trick:
 * LayOut:
 *  map<string, int> turtlesid;
 *  vector<string> turtles;
 *  reset()
 *  input()
 *  solove()
 */


#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include<cassert>
using namespace std;


map<string, int> turtlesid;
vector<string> start_turtles;
vector<string> end_turtles; 
int n;

void reset(){
  turtlesid.clear();
  start_turtles.clear();
  end_turtles.clear();
}

void input(){
  cin >> n;
  cin.ignore();
  start_turtles.resize(n);
  end_turtles.resize(n);
  for (int i = 0; i < n; i++){
    getline(cin, start_turtles[i]);
  }
  for (int i = 0; i < n; i++){
    getline(cin, end_turtles[i]);
    turtlesid[end_turtles[i]] = i;
  }
}

void solve(){
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    a[i] = turtlesid[start_turtles[i]];
  }
  vector<int> errors;

  int last = n - 1;
  while (last >= 0){
    vector<int>::iterator it = find(a.begin(), a.end(), last);
    if (it == a.end()){
      break;
    }else{
      a.erase(it, a.end());
    }
    last--;
  }

  while (last >= 0){
    cout << end_turtles[last] << endl;
    last--;
  }
}

int main(){
  int cases;
  cin >> cases;
  while (cases--){
    reset();
    input();
    solve();
    cout << endl;
  }
}
  
