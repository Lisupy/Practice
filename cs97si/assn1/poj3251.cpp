#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
using namespace std;


const int MAXN = 128;

int N;
char field[MAXN][MAXN];


int largest_square = 0;

inline bool is_point_valid(int x, int y){
  return 0<=x && x < N && 0 <= y && y < N;
}
inline bool is_valid(int x1, int y1,
             int x2, int y2,
             int x3, int y3,
             int x4, int y4){
  if ( !is_point_valid(x1, y1) 
    || !is_point_valid(x2, y2)
    || !is_point_valid(x3, y3)
    || !is_point_valid(x4, y4))
    return false;

  if (field[x1][y1] == 'B'
    || field[x2][y2] == 'B'
    || field[x3][y3] == 'B'
    || field[x4][y4] == 'B')
    return false;
  int s = 0;
  if (field[x1][y1] == 'J')s++;
  if (field[x2][y2] == 'J')s++;
  if (field[x3][y3] == 'J')s++;
  if (field[x4][y4] == 'J')s++;
  if (s < 3)
    return false;
  return true;
}

inline int dis_square(int x1, int y1,int x2, int y2){
  return (y2-y1)*(y2-y1)+(x2-x1)*(x2-x1);
}
inline bool is_square(int x1, int y1,
             int x2, int y2,
             int x3, int y3,
             int x4, int y4){
  int s1 = dis_square(x1,y1,x3,y3);
  int s2 = dis_square(x3,y3,x2,y2);
  int s3 = dis_square(x2,y2,x4,y4);
  int s4 = dis_square(x4,y4,x1,y1);
//  printf("(%d,%d,%d,%d)\n", s1, s2, s3, s4);
  return s1 == s2 && s1 == s3 && s1 == s4;
}

inline bool can_pruning(int x1, int y1, int x2, int y2){ 
  if (field[x1][y1] == 'B' || field[x2][y2] == 'B')
    return true;
  if (field[x1][y1] != 'J' && field[x2][y2] != 'J')
    return true;
  if ((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)<=largest_square*2)
    return true;
  return false;
}

inline int check(int x1, int y1, int x2, int y2){
  if(can_pruning(x1, y1, x2, y2))
    return -1;

  double x0 = (x1+x2)/2.;
  double y0 = (y1+y2)/2.;
  double tx = (x2-x1)/2.;
  double ty = (y2-y1)/2.;

  int x3 = x0+ty;
  int y3 = y0-tx;
  int x4 = x0-ty;
  int y4 = y0+tx;

  if (!is_valid(x1,y1,x2,y2,x3,y3,x4,y4))
    return -1;
//  printf("(%d,%d) (%d,%d)(%d,%d)(%d,%d)\n",x1,y1,x2,y2,x3,y3,x4,y4);
//  printf("(%lf,%lf) (%lf,%lf)\n", x0, y0, tx, ty);
  if (!is_square(x1,y1,x2,y2,x3,y3,x4,y4))
    return -1;
//  printf("(is_square)\n");
  return dis_square(x1,y1,x3,y3);
}
int main(){
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    scanf("%s", field[i]);


  for (int x1 = 0; x1 < N; x1++){
    for (int y1 = 0; y1 < N; y1++){
      for (int x2 = x1; x2 < N; x2++){
        for (int y2 = 0; y2 <N; y2++){
          largest_square = max(largest_square, check(x1, y1, x2, y2));
        }
      }
    }
  }
  printf("%d\n", largest_square);
}
