#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  vector<int> T(128*1024);
  cin >> T[0] >> T[1] >> T[2];
  int N; cin >> N;
  for (int i = 3; i <= N; i++) T[i] = T[i - 1] + T[i - 2] - T[i - 3];
  cout << T[N] << endl;
}