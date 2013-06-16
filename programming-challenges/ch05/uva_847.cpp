/*
 * Algorithm:  math
 */

#include<iostream>
using namespace std;

int main(){
  //long n;
  double n;
  while (cin >> n){
    while (n > 18){
      n /= 18;
    }
    if (1 < n && n <= 9){
      cout << "Stan wins." << endl;
    }else{
      cout << "Ollie wins." << endl;
    }
  }
}
