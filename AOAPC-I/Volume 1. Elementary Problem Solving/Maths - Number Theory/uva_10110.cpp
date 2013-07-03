#include<iostream>
#include<cmath>
using namespace std;


long long isSquareNumer(long long n){
  long long root = sqrt(n);
  return root * root  == n;
}


int main(){
  long long n;
  while (cin >> n && n){
    if (isSquareNumer(n)){
      cout << "yes" << endl;
    }else{
      cout << "no" << endl;
    }
  }
}
