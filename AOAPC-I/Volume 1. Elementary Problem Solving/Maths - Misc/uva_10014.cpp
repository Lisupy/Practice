#include<iostream>
#include<cstdio>
using namespace std;



int main(){
  int TestNum;
  cin >> TestNum;
  while (TestNum--){

    int n;
    cin >> n;
    double a1, an1;
    cin >> a1 >> an1;
    if (n == 0){
      printf("%.02lf\n", an1);
    }else{
      double c, sc1, sc2;
      sc1 = 0;
      sc2 = 0;
      for (int i = 1; i <= n; i++){
        cin >> c;
        sc1 += c;
        sc2 += c * i;
      }
      double ss = a1 + an1 - sc1 * 2 ;
      double ans = ss + (sc2 * 2 - a1 - an1*n)/ (n + 1);
      printf("%.02lf\n", ans);
    }
    if (TestNum){
      cout << endl;
    }
  }
}


