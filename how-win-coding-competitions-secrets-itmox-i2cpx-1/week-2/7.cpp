#include<iostream>
#include<queue>
#include<cstdio>
#include<stack>
#include<string>
#include<numeric>
#include<map>
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; scanf("%d", &N);
  map<int, int> M;
  int h = 0;
  while (N--) {
    int a; scanf("%d", &a);
    if (a > 0) {
      if (h != 0) {
        M[h]++; 
      }
      h = 1;
    } else {
      h++;
    }
  }
  if (h != 0) M[h]++;
  cout << M.size() << endl;
  for (auto it: M) {
    cout << it.first << " " << it.second << endl;
  }
}