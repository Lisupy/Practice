#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;


int main(){
  int TestNum = 0;
  int n;
  while (cin >> n && n){
    vector<int> h(n);
    for (int i = 0; i < n; i++){
      cin >> h[i];
    }
    int sum = accumulate(h.begin(), h.end(), 0);
    int average = sum / n;
    int cnt = 0;
    for (int i = 0; i < n; i++){
      if (h[i] < average){
        cnt += average - h[i];
      }
    }
    cout << "Set #" << ++TestNum << endl;
    cout << "The minimum number of moves is " << cnt << "." << endl;
    cout << endl;
  }
}
