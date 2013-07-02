#include<iostream>
#include<cmath>
using namespace std;


int main(){
  long long n;
  while (cin >> n && n > 0){
    if (n == 1){
      n = 0;
    }
    cout << n * 25 << "%" << endl;
  }
}
