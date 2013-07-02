#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;



#define eps 0.000001
int main(){
  long long H, S;
  while (cin >> H >> S && H){
    if (H == 1 && S == 1){
      cout << "0 1" << endl;
      continue;
    }
    long long N, k;
    for (k = 1; k <= H; k++){
      N = round(powl(S, 1.0 / k));
      if (powl(N, k) == S && powl(N + 1, k)  == H){
        break;
      }
    }

    long long s = 0;
    for (int i = 0; i < k; i++){
      s += powl(N, i);
    }

    cout << s << " ";
    s = 0;
    for (long long i = 0; i <= k; i++){
      s += powl(N + 1, i) * powl(N, k - i);
    }
    cout << s << endl;
  }
}

