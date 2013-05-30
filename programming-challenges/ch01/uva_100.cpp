//Algorithm:  brute-force, simulate, memo
//Complexity: N = 10^6 * ?, O(N)
//IndexBased: 0
//Trick:      i may be less than j

#include<cstdio>
#include<algorithm>
#include<iostream>
#include<map>
#include<cassert>
using namespace std;


const int MAXN = 1024 * 1024;

int cycle_length[MAXN];


#if 0
int get_cycle_length(int n){
  assert(n <= MAXN * 10);

  int &result = cycle_length[n];
  if (result != -1){
    return result;
  }

  if (n == 1){
    result = 1;
  }else if (n % 2 == 0){
    result = get_cycle_length(n / 2) + 1;
  }else{
    result = get_cycle_length(n * 3 + 1) + 1;
  }

  return result;
}
#endif

int get_cycle_length(unsigned n){
  int result = 1;
  while (n != 1){
    if (n % 2 == 0){
      n /= 2;
    }else{
      n = n * 3 + 1;
    }
    result++;
  }
  return result;
}

void init(){
  fill_n(cycle_length, MAXN, -1);
  cycle_length[1] = 1; 

  for (int i = 1; i < MAXN; i++){
    cycle_length[i] = get_cycle_length(i);
  }
}

int max_cycle(int from, int to){
  return *max_element(cycle_length + from, cycle_length + to + 1);
}

int main(){
  init();

  int i, j;

  while (cin >> i >> j){
    int from = i, to = j;
    if (from > to){
      swap(from, to);
    }
    cout << i << " " << j << " " << max_cycle(from, to) << endl;
  }

}
