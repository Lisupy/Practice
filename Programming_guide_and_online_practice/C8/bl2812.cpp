#include<cstdio>
#include<map>
#include<set>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


const int MAXN = 5000;

set< pair<int, int> > S;
vector< pair<int, int> > a;
bool M[MAXN+1][MAXN+1];
int R, C;
int N;

int gcd(int c, int b){
  if (b == 0) return c;
  return gcd(b, c%b);
}

int main(){
  scanf("%d %d", &R, &C);
  scanf("%d", &N);
  for (int i = 0; i < N; i++){
    int x, y;
    scanf("%d%d", &x, &y);
    M[x][y] = true;
    pair<int,int> t(x, y);
    a.push_back(t);
  }
  sort(a.begin(), a.end());

  int max_count = 0;
  for (int i = 0; i < N; i++){
    for (int j = i + 1; j < N; j++){
      int x1 = a[i].first;
      int y1 = a[i].second;
      int x2 = a[j].first;
      int y2 = a[j].second;

      int dx = x2 - x1;
      int dy = y2 - y1;
      bool valid = true;
      int count = 1;
      int tx = x1 + dx;
      int ty = y1 + dy;
      if (x1 - dx >= 1 && 1 <= y1 - dy && y1 - dy <= C){
        valid = false;
      }
      while (valid && 1 <= tx && tx <= R && 1 <= ty && ty <= C){
        if (M[tx][ty]){
          count++;
        }else{
          valid = false;
        }
        tx += dx;
        ty += dy;
      }
      if (valid && max_count < count){
        max_count = count;
      }
    }
  }
  if (max_count <= 2)
    max_count = 0;
  printf("%d\n", max_count);
}

