#include<iostream>
#include<queue>
#include<cstdio>
#include<stack>
#include<string>
#include<numeric>
#include<map>
#include<functional>
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; scanf("%d", &N);
  priority_queue<int, vector<int>, greater<int>> Q;
  int h = 0;
  while (N--) {
    int a; scanf("%d", &a);
    if (a > 0) {
      Q.push(1);
    } else {
      if (Q.size() == 0) Q.push(1);
      else {
        int x = Q.top(); Q.pop();
        Q.push(x + 1);
      }
    }
  }
  map<int, int> M;
  while (Q.size()) M[Q.top()]++, Q.pop();
  cout << M.size() << endl;
  for (auto it: M) {
    cout << it.first << " " << it.second << endl;
  }
}