#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isValid(string s) {
  stack<char> S;
  for (auto c: s) {
    if (c == '(' || c == '[') S.push(c);
    else {
      if (S.empty()) return false;
      if (c == ']' && S.top() != '[') return false;
      if (c == ')' && S.top() != '(') return false;
      S.pop();
    }
  }
  return S.empty();
}
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N; scanf("%d", &N);
  while (N--) {
    string s; cin >> s;
    cout << (isValid(s)?"YES":"NO") << endl;
  }
}