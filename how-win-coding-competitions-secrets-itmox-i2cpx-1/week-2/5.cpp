#include<iostream>
#include<queue>
#include<cstdio>
#include<stack>
#include<string>
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; cin >> N;
  stack<int> S;
  while (N--) {
    string s; cin >> s;;
    if (s == "+" || s == "-" || s == "*" || s == "/") {
      int r = S.top(); S.pop();
      int l = S.top(); S.pop();
      if (s == "+") S.push(l + r);
      if (s == "-") S.push(l - r);
      if (s == "*") S.push(l * r);
      if (s == "/") S.push(l / r);
    } else {
      S.push(stoi(s));
    }
  }
  cout << S.top() << endl;
}