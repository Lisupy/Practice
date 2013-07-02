#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;



int main(){
  int N;
  while (cin >> N && N){
    int l = 0;
    while ((l + 1) * (l + 1) < N){
      l++;
    }
    int remain = N - l * l;
    int x, y;
    if (remain <= l){
      x = remain;
      y = l + 1;
    }else{
      x = l + 1;
      y = 2 * l + 2 - remain;
    }
    if (l % 2 == 0){
      swap(x, y);
    }
    cout << x << " " << y << endl;
  }
}
