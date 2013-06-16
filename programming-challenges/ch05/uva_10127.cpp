/*
 * Algorithm:  math
 */

#include<iostream>
using namespace std;

int main(){
  int n;
  while (cin >> n){
    int s = 1;
    int cnt = 1;
    while (s % n != 0){
      s = (s * 10 + 1) % n;
      cnt++; 
    }
    cout << cnt << endl;
  }
}
