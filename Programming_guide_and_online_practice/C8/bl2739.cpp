#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int n;
  cin >> n;

  while (n--){
    double a,b;
    cin >> a >> b;
    double loga = log(a);
    double logb = log(b);

    for (int x = 0; x <= 32; x++){
      if (x * loga <= logb && logb < (x + 1) * loga){
        cout << x << endl;
        break;
      }
    }
  }
}
