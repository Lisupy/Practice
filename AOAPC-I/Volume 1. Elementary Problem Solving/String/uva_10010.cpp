#include<iostream>
#include<string>
#include<cctype>
#include<cstdio>
#include<vector>
#include<cassert>
#include<algorithm>
using namespace std;

const int MAXN = 64;
int m, n;
int testNum;

char grid[MAXN][MAXN];



void read_grid(){
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; i++){
    scanf("%s", grid[i] + 1);
  }
  for (int i = 1; i <= m; i++){
    for (int j = 1; j <= n; j++){
      grid[i][j] = tolower(grid[i][j]);
    }
  }
}


string grid_get_string(int x, int y, int dx, int dy, int len){
  string s;
  for (int i = 0; i < len; i++){
    if (1 <= x && x <= m && 1 <= y && y <= n){
      s += grid[x][y];
      x += dx;
      y += dy;
    }
  }
  return s;
}


void grid_get_pos(string s, int &x, int &y){
  for (int i = 1; i <= m; i++){
    for (int j = 1; j <= n; j++){
      for (int dx = -1; dx <= 1; dx++){
        for (int dy = -1; dy <= 1; dy++){
          if (dx == 0 && dy == 0){
            continue;
          }
          string t = grid_get_string(i, j, dx, dy, s.size());
          if (t == s){
            x = i, y = j;
            return;
          }
        }
      }
    }
  }
  assert(0);
}


int main(){
  scanf("%d", &testNum);
  while (testNum--){
    read_grid();
    int k;
    cin >> k;
    while (k--){
      string s;
      cin >> s;
      transform(s.begin(), s.end(), s.begin(), ::tolower);
      int x, y;
      grid_get_pos(s, x, y);
      cout << x << " " << y << endl;
    }
    if (testNum){
      cout << endl;
    }
  }
}
