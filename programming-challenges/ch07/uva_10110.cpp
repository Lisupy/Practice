#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;


long long n;

int main(){
  while (cin >> n && n){
    long double t = n;
    long long m = sqrt(t);
    if (m * m == n){
      cout << "yes" << endl;
    }else{
      cout << "no" << endl;
    }
  }
}
