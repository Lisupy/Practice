/*
 * Algorithm: count
 * Complexity: O(N)
 * IndexBased: 0
 * Trick: 
 * LayOut:
 *  reset();
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;



string a;
string b;
string x;

int cnt_a[256];
int cnt_b[256];
int cnt_x[256];

void reset(){
  memset(cnt_a, 0, sizeof(cnt_a));
  memset(cnt_b, 0, sizeof(cnt_b));
  memset(cnt_x, 0, sizeof(cnt_x));
}

int main(){
  while (getline(cin, a)){
    getline(cin, b);
  //  cout << "[" << a << "]" << endl;
   // cout << "[" << b << "]" << endl;
    reset();
    for (size_t i = 0; i < a.size(); i++){
      cnt_a[(int)a[i]]++;
    }
    for (size_t i = 0; i < b.size(); i++){
      cnt_b[(int)b[i]]++;
    }
    for (size_t i = 'a'; i <= 'z'; i++){
      cnt_x[i] = min(cnt_a[i], cnt_b[i]);
    }

    x = "";
    for (size_t i = 'a'; i <= 'z'; i++){
      x += string(cnt_x[i], i);
    }

    cout << x << endl;
  }
}


