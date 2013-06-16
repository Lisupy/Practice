/*
 * algorithm:   
 * complexity:
 * trick:       get_reverse
 * IndexBased:  0
 * LayOut:
 *    get_int_reverse
 */

#include<algorithm>
#include<iostream>
#include<string>
using namespace std;


unsigned int get_reverse_int(unsigned int n){
  unsigned int s = 0;
  while (n != 0){
    s = s * 10 + n % 10;
    n = n / 10;
  }
  return s;
}


int main(){
  int N;
  cin >> N;
  while (N--){
    unsigned int P;
    cin >> P;
    int cnt = 0;
    unsigned int RP = get_reverse_int(P);
    while (P != RP){
      P = P + RP;
      RP = get_reverse_int(P);
      cnt++;
    }
    cout << cnt << " " << P << endl;
  }
}

