/*
 * Algorithm:   Brute-Force
 * Complexity:  50*50*20*4
 * IndexBased:  1
 * Trick:       get_the_word, and then match the prefix
 * LayOut:
 *  reset();
 *  input_grids();
 *  input_word();
 *  find();
 */

#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<sstream>
#include<cassert>
#include<utility>
using namespace std;


const int MAXN = 64;
int m,n;
char grid[MAXN][MAXN];

void reset(){
  memset(grid, 0, sizeof(grid));
}

void input_grid(){
  scanf("%d %d", &m, &n);
  for (int i = 1; i <= m; i++){
    scanf("%s", grid[i] + 1);
  }
}

int dxs[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dys[] = {-1,  0,  1, -1, 1, -1, 0, 1};

bool is_matched(int x, int y, int dx, int dy, char* word){
  int len = strlen(word);
  for (int i = 0; i < len; i++){
    int x1 = x + i * dx;
    int y1 = y + i * dy;
//    printf ("%d %d: %d %d, %c %c\n", x, y, x1, y1, grid[x1][y1], word[i]);
    if (1 <= x1 && x1 <= m && 1 <= y1 && y1 <= n && tolower(grid[x1][y1]) == tolower(word[i])){
      //pass
    }else{
      return false;
    }
  }
  return true;
}

pair<int, int> grid_find(char *word){
  for (int x = 1; x <= m; x++){
    for (int y = 1; y <= n; y++){
      for (int i = 0; i < 8; i++){
        int dx = dxs[i], dy = dys[i];
        if (is_matched(x, y, dx, dy, word)){
          return make_pair(x, y);
        }
      }
    }
  }
  assert(0);
}

int main(){
  int CASES;
  scanf("%d", &CASES);
  while (CASES--){
    reset();
    input_grid();
    int k;
    scanf("%d", &k);
    char word[256];
    while (k--){
      scanf("%s", word);
 //     printf("[%s]\n", word);
      pair<int, int> ans = grid_find(word);
      printf("%d %d\n", ans.first, ans.second);
    }
    if (CASES != 0){
      printf("\n");
    }
  }
}
