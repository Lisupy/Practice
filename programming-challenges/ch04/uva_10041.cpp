/*
 * Algorithm:  median, sum
 * Complexity: O(n)
 * IndexBased: 0
 * Trick:   nth_element, accumulate, for_each
 * LayOut:
 *    reset();
 *    input();
 *    process();
 */


#include<vector>
#include<algorithm>
#include<numeric>
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

const int MAXR = 512;

int r;
int s[MAXR];

int reset(){
  return 1;
}

void input(){
  cin >> r;
  for (int i = 0; i < r; i++){
    cin >> s[i];
  }
}

int process(){
  nth_element(s, s + r/2, s + r);
  int median = s[r / 2];
  int sum = 0;
  for (int i = 0; i < r; i++){
    sum += abs(s[i] - median);
  }
  return sum;
}
    
int main(){
  int T;
  cin >> T;
  while (T--){
    reset();
    input();
    int ans = process();
    cout << ans << endl;
  }
}
