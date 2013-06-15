/*
 * Algorithm:   sort with special compare
 * Complexity:  sort
 * IndexBased:  1
 * Trick:
 * LayOut:
 *  reset();
 *  input();
 *  solve();
 */

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

struct Job{
  int id;
  int T;
  int S;
};

Job jobs[1024];

int n;


void reset(){

}

void input(){
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> jobs[i].T >> jobs[i].S;
    jobs[i].id = i;
  }
}

bool cmp(const Job& a, const Job& b){
  return a.T * b.S < b.T * a.S;
}

void solve(){
  sort(jobs + 1, jobs + 1 + n, cmp);
  for (int i = 1; i <= n; i++){
    cout << jobs[i].id;
    if (i == n){
      cout << endl;
    }else{
      cout << " ";
    }
  }
}
int main(){
  int cases;
  cin >> cases;
  while (cases--){
    reset();
    input();
    solve();
    if (cases){
      cout << endl;
    }
  }
}

