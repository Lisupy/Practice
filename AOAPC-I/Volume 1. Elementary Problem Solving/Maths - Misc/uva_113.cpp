#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
using namespace std;




int main(){
  double n, p;
  while (cin >> n >> p){
    cout << (int)round( pow(p, 1.0/n) ) << endl;
//    printf("%.0lf\n", pow(p, 1.0/n));
  }
}
