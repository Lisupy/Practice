#include<iostream>
#include<deque>
#include<cstdio>
using namespace std;


int intMod(int n, int mod){
  return (n % mod + mod) % mod;
}

void solve(int N, int k, int m){
  deque<int> a(N);
  for (int i = 0; i < N; i++){
    a[i] = i + 1;
  }
  int first = 0;
  int second = N - 1;
  int round_cnt = 0;
  while (!a.empty()){
    int next_first = intMod(first + k - 1, a.size());
    int next_second = intMod(second - m + 1, a.size()) ;
    //cout << next_first << ", " << next_second << endl;
    if (round_cnt++){
      printf(",");
    }
    if (next_first == next_second){
      printf("%3d", a[next_first]);
      a.erase(a.begin() + next_first);
      if (a.size() > 0){
        next_second = intMod(next_second - 1, a.size());
        first = next_first;
        second = next_second;
      }
    }else{
      printf("%3d%3d", a[next_first], a[next_second]);
      a.erase(a.begin() + next_first);
      if (next_second > next_first){
        next_second--;
      }
      a.erase(a.begin() + next_second);
      if (next_first > next_second){
        next_first--;
      }
      if (a.size() > 0){
        next_second = intMod(next_second - 1, a.size());
        first = next_first;
        second = next_second;
      }
    }
  }
  printf("\n");
}

int main(){
  int N, k, m;
  while (cin >> N >> k >> m && N){
    solve(N, k, m);
  }
}


