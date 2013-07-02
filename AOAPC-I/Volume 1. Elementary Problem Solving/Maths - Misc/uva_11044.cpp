#include<iostream>
#include<cmath>
using namespace std;


int main(){
  int t, n, m;
  cin >> t;
  while (t--){
    cin >> n >> m;

    int x = ceil((n - 2) / 3.0);
    int y = ceil((m - 2) / 3.0);
    cout << x * y << endl;
  }
}
