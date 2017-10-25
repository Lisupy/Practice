#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<cassert>
typedef long long ll;
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int W, H; cin >> W >> H;
  string tmp; getline(cin, tmp);
  map<char, pair<int, int>> M;
  for (int i = 0; i < H; i++) {
    string s; getline(cin, s);
    for (int j = 0; j < W; j++) M[s[j]] = make_pair(i, j);
  }
  int minDist = 0x3f3f3f3f;
  string minName = "";
  string templateName;
  while (getline(cin, templateName) && templateName != "") {
    string s; 
    int tot = 0;
    int x = -1, y = -1;
    getline(cin, s);
    assert(s == "%TEMPLATE-START%");
    while (getline(cin, s) && s != "%TEMPLATE-END%") {
      for (auto c: s) {
        auto it = M.find(c);
        if (it == M.end()) {
          continue;
        }
        if (x != -x && y != -1) {
          tot += max(abs(x - it->second.first) , abs(y - it->second.second));
        }
        x = it->second.first, y = it->second.second;
      }
    }
    if (minDist > tot) {
      minName = templateName;
      minDist = tot;
    }
  }
  cout << minName << endl;
  cout << minDist << endl;
} 