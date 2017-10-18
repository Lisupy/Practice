#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  double a, b, c; cin >> a >> b >> c;
  printf("%.06lf\n", (a+b+c)/6);
}