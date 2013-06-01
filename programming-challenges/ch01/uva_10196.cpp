/*
 * Algorithm:  simulation
 * Complexity:
 * IndexBased: 0
 * Trick:      
 * Layout:
 *  struct Chess;
 *  is_white, is_black, side, is_same_side
 *  is_king
 *  Pawn_try;
 *  kinght_try;
 *  Bishop_try;
 *  Rook_try;
 *  Queen_try;
 *  King_try;
 *  check;// return "black", "white", "no"
 */


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;



const int MAXN = 16;

struct Chess{
  char board[MAXN][MAXN];

  bool is_white(int x, int y){
    return isupper(board[x][y]);
  }

  bool is_black(int x, int y){
    return islower(board[x][y]);
  }

  bool is_valid(int x, int y){
    return 0 <= x && x <= 8 && 0 <= y && y <= 8;
  }

  bool is_same_side(int x1, int y1, int x2, int y2){
    return side(x1, y1) == side(x2, y2);
  }

  string side(int x, int y){
    if (is_white(x, y)) return "white";
    if (is_black(x, y)) return "black";
    return "no";
  }

  string opposite_side(string _side){
    if (_side == "black") return "white";
    if (_side == "white") return "black";
    return "no";
  }

  bool is_king(int x, int y){
    return tolower(board[x][y]) == 'k';
  }

  bool __check(int xs[], int ys[], int n, char king){
    for (int i = 0; i < n; i++){
      int x = xs[i], y = ys[i];
      if (is_valid(x, y) && king == board[x][y]){
        return true;
      }
    }
    return false;
  }

  bool Pawn_try(int x, int y){
    char k = opposite_king(x, y);

    if (is_black(x, y)){
      int xs[] = {x + 1, x + 1};
      int ys[] = {y + 1, y - 1};
      return __check(xs, ys, 2, k);
    }else{
      int xs[] = {x - 1, x - 1};
      int ys[] = {y + 1, y - 1};
      return __check(xs, ys, 2, k);
    }
  }

  char opposite_king(int x, int y){
    return is_white(x, y)? 'k' : 'K'; 
  }

  bool Knight_try(int x, int y){
  //  int xs[] = {x + 2, x + 2, x - 2, x - 2, x + 1, x + 1, x - 1, x - 1};
   // int ys[] = {y + 1, y - 1, y + 1, y - 1, y + 2, y - 2, y + 2, y - 2};
    int xs[20], ys[20], n = 0;
    int d[] = {2, -2, 1, -1};
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
        int dx = d[i], dy = d[j];
        if (abs(dx) != abs(dy)){
          xs[n] = x + dx, ys[n] = y + dy;
          n++;
        }
      }
    }
  //  printf("%d\n", n);
    char k = opposite_king(x, y);
    return __check(xs, ys, n, k);
  }

  bool __line_try(int x, int y, int dx, int dy, char king){
    for (int i = 1; i <= 8; i++){
      int tx = x + dx * i;
      int ty = y + dy * i;
      if (is_valid(tx, ty)){
        if (board[tx][ty] == king)
          return true;
        else if (board[tx][ty] != '.')
          return false;
      }else{
        return false;
      }
    }
    return false;
  }
  
  bool __line_trys(int x, int y, int dxs[], int dys[], int n, char king){
    for (int i = 0; i < n; i++){
      int dx = dxs[i];
      int dy = dys[i];
      if (__line_try(x, y, dx, dy, king))
        return true;
    }
    return false;
  }

  bool Bishop_try(int x, int y){
    char k = opposite_king(x, y);
    int dxs[] = {1, -1, 1, -1};
    int dys[] = {1, -1,-1,  1};
    return __line_trys(x, y, dxs, dys, 4, k);
  }

  bool Rook_try(int x, int y){
    char k = opposite_king(x, y);
    int dxs[] = { 1,-1, 0, 0};
    int dys[] = { 0, 0,-1, 1};
    return __line_trys(x, y, dxs, dys, 4, k);
  }

  bool Queen_try(int x, int y){
    return Rook_try(x, y) || Bishop_try(x, y);
  }

  bool check_dispatch(int x, int y, char c){
    switch(tolower(c)){
    case 'p':return Pawn_try(x, y);
    case 'n':return Knight_try(x, y);
    case 'b':return Bishop_try(x, y);
    case 'r':return Rook_try(x, y);
    case 'q':return Queen_try(x, y);
    }
    return false;
  }


  string check(){
    for (int i = 0; i < 8; i++){
      for (int j = 0; j < 8; j++){
        char ch = board[i][j];
        if (check_dispatch(i, j, ch)){
          return opposite_side(side(i, j));
        }
      }
    }
    return "no";
  }

  int input(){
    for (int i = 0; i < 8; i++){
      scanf("%s", board[i]);
    }
    for (int i = 0; i < 8; i++){
      for (int j = 0; j < 8; j++){
        if (board[i][j] != '.'){
          return 64;
        }
      }
    }
    return EOF;
  }
};

Chess chess;
int CAS = 0;

int main(){
  while (chess.input() != EOF){
    printf("Game #%d: ", ++CAS);
    printf("%s king is in check.\n", chess.check().c_str());
  }
}



