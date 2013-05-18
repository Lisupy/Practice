#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

const int MAXC = 6;
const int MAXR = 5;
struct Game{
  bool lighten[MAXR][MAXC];
  bool switched[MAXR][MAXC];

  void init(){
    memset(switched, 0, sizeof(switched));
  }

  void __change(int i, int j){
    if (0 <= i && i < MAXR && 0 <= j && j < MAXC){
      lighten[i][j] = !lighten[i][j];
    }
  }

  void change(int i, int j){
    switched[i][j] = true;
    __change(i - 1, j);
    __change(i + 1, j);
    __change(i,     j - 1);
    __change(i,     j + 1);
    __change(i,     j);
  }

  bool alldown(){
    for(int i = 0; i < MAXR; i++){
      for(int j = 0; j < MAXC; j++){
        if (lighten[i][j])
          return false;
      }
    }
    return true;
  }

  void input(){
    for (int i = 0; i < MAXR; i++){
      for (int j = 0; j < MAXC; j++){
        cin >> lighten[i][j];
      }
    }
  };
  void dbg(){
    cout << endl;
    for (int i = 0; i < MAXR; i++){
      for (int j = 0; j < MAXC; j++){
        cout << lighten[i][j] << " ";
      }
      cout << endl;
    }
  };

  void output(){
    for (int i = 0; i < MAXR; i++){
      for (int j = 0; j < MAXC; j++){
        cout << switched[i][j] << " ";
      }
      cout << endl;
    }
  };
};

int main(){
  int N;
  cin >> N;

  for (int Ni = 1; Ni <= N; Ni++){
    Game game;
    game.input();

    for (int first_row = 0; first_row < 1<<MAXC; first_row++){
      Game g = game;
      g.init();
      for (int i = 0; i < MAXC; i++){
        if (first_row & (1<<i) ){
          g.change(0, i);
        }
      }

      for (int i = 1; i < MAXR; i++){
        for (int j = 0; j < MAXC; j++){
          if(g.lighten[i-1][j]){
            g.change(i, j);
          }
        }
      }

      if (g.alldown()){
       // g.dbg();
        game = g;
        break;
      }
    }

    cout << "PUZZLE #" << Ni <<endl;
    game.output();
  }
}
