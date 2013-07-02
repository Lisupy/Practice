#include<iostream>
#include<cmath>
#include<cassert>
using namespace std;


int solve(int n){
  if (n == 0){
    return 0;
  }
  int best = 0xffffff;

  for (int k = 1; k <= n; k++){
    int s = (1 + k) * k;
    if (s > n){
      break;
    }
    int can = ceil((n - s) * 1.0/(k + 1)) + 2 * k;
    best = min(best, can);
  }
  return best;
}


int main(){
  int n;
  cin >> n;
  while (n--){
    int x, y;
    cin >> x >> y;
    assert(x <= y);
    cout << solve(y - x) << endl;
  }
}
    
