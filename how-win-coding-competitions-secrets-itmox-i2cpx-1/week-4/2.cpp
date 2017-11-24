#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
double next(double a, double b) {
  return 2 * a + 2 - b;
}
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N;
  cin >> N;
  double A;
  cin >> A;
  double lo = 0, hi = A;
  double best = 0;
  for (int j = 0; j < 10000; j++) {
    double mid = (lo + hi) / 2;
    vector<double> s = {A, mid};
    for (int i = 2; i < N; i++) {
      s.push_back(next(s[i - 1], s[i - 2]));
    }
    bool isValid = true;
    for (auto c : s) if (c < 0) isValid = false;
    if (!isValid) lo = mid;
    else {
      hi = mid;
      best = s.back();
    }
  }
  printf("%.8lf\n", best);
}