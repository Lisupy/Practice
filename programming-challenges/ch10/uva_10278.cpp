/*
 * Algorithm:   Shortest Path
 * Complexity:  N^3
 * IndexBased:  1 
 * Trick:    
 */

#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<sstream>
using namespace std;

const int MAXN = 512;

int f;
vector<int> fs;
int I;
int d[MAXN][MAXN];

int main(){
  int T;
  cin >> T;
 // T = 1;
  while (T--){
    fs.clear();
    fill(&d[0][0], &d[MAXN-1][MAXN-1] + 1, 0x777777);
    for (int i = 0; i < MAXN; i++){
      d[i][i] = 0;
    }
    cin >> f >> I;
    fs.resize(f);
    for (int i = 0; i < f; i++){
      cin >> fs[i];
    }
    string line;
    cin.ignore();
    while (getline(cin, line) && line.size()){
    //  cout << "[" << line << "]" << endl;
      istringstream iss(line);
      int s, t, w;
      iss >> s >> t >> w;
      d[s][t] = d[t][s] = w;
    }
    
    for (int v = 1; v <= I; v++){
      for (int s = 1; s <= I; s++){
        for (int t = 1; t <= I; t++){
          d[s][t] = min(d[s][t], d[s][v] + d[v][t]);
        }
      }
    }

    int min_the_maxs = 0xfffffff;
    int min_pos = 0;
    for (int sel = 1; sel <= I; sel++){
      vector<int> longest(I + 1);
      for (int i = 1; i <= I; i++){
        longest[i] = d[i][sel];
        for (size_t j = 0; j < fs.size(); j++){
          longest[i] = min(longest[i], d[i][fs[j]]);
        }
      }
      size_t pos = max_element(longest.begin() + 1, longest.end()) - longest.begin();
      if (longest[pos] < min_the_maxs){
        min_the_maxs = longest[pos];
        min_pos = sel;
      }
    }
    cout << min_pos << endl;
    if (T){
      cout << endl;
    }
  }
}
