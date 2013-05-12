#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;


struct Dir{
  int x,y,z;
  int n;
};

Dir adjust[3][3][3];
Dir* face;

void init(){
  for (int x = 0; x < 3; x++){
    for (int y = 0; y < 3; y++){
      for (int z = 0; z < 3; z++){
        int n = 0;
        if (x-1 == 1) n = 0;
        if (x-1 == -1) n = 3;
        if (y-1 == 1) n = 1;
        if (y-1 == -1) n = 4;
        if (z-1 == 1) n = 2;
        if (z-1 == -1) n = 5;
        adjust[x][y][z] = {x-1,y-1,z-1, n};
        if (x-1 == 1 && y - 1 == 0 && z - 1 == 0){
          face = &adjust[x][y][z];
        }
      }
    }
  }
}

void turn_left(){
  for (int z = 0; z < 3; z++){
    Dir tmp[3][3] = {{adjust[0][2][z],adjust[1][2][z],adjust[2][2][z]},
                     {adjust[0][1][z],adjust[1][1][z],adjust[2][1][z]},
                     {adjust[0][0][z],adjust[1][0][z],adjust[2][0][z]}};
    for (int x = 0; x < 3; x++){
      for (int y = 0; y < 3; y++){
        adjust[x][y][z] = tmp[x][y];
      }
    }
  }
}

void turn_right(){
  turn_left();
  turn_left();
  turn_left();
}

void turn_up(){
  for (int y = 0; y < 3; y++){
    Dir tmp[3][3] = {{adjust[2][y][0],adjust[1][y][0],adjust[0][y][0]},
                     {adjust[2][y][1],adjust[1][y][1],adjust[0][y][1]},
                     {adjust[2][y][2],adjust[1][y][2],adjust[0][y][2]}};
    for (int x = 0; x < 3; x++){
      for (int z = 0; z < 3; z++){
        adjust[x][y][z] = tmp[x][z];
      }
    }
  }
}

void turn_back(){
  turn_left();
  turn_left();
}

void turn_down(){ 
  turn_up();
  turn_up();
  turn_up();
}

int main(){
  int m;
  scanf("%d", &m);
  while (m--){
    int n;
    scanf("%d", &n);
    init();
    int x,y,z;
    x = y = z = 0;

    while(n--){
      char turn[24];
      int k;
      scanf("%s %d", turn, &k);
      switch(turn[0]){
      case 'l'://left
        turn_left();
        break;
      case 'r'://right
        turn_right();
        break;
      case 'u'://up
        turn_up();
        break;
      case 'd'://down
        turn_down();
        break;
      case 'f'://forward
        break;
      case 'b'://back
        turn_back();
        break;
      }
      x += face->x * k;
      y += face->y * k;
      z += face->z * k;
    }
    printf("%d %d %d %d\n", x, y, z, face->n);
  }
}

