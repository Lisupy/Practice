#include<iostream>
#include<cmath>
using namespace std;


int nbitsGetFromYear(int year){
  return pow(2, (year - 1960) / 10) * 4;
}


int solve(int year){
  int nbits = nbitsGetFromYear(year);
  //cout << nbits << endl;

  double s = 0;
  int n = 1;
  while (s < nbits){
    s += log(n + 1) / log(2);
    n++;
  }
  return n - 1;
}


int main(){
  int y;
  while (cin >> y && y){
    cout << solve(y) << endl;
  }
}
