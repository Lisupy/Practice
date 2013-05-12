#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#include<numeric>
using namespace std;



const int MAXN = 64;
const int MAXM = 64;
const int MAXK = 1024;
const int MAXP = 512;


struct Point{
  int x,y;
  int value;
};

int dist(Point &p1, Point& p2){
  int dis1 = abs(p1.x-p2.x) + abs(p1.y-p2.y);
//  int dis2 = p1.y + p2.y;
 // return min(dis1,dis2);
  return dis1;
}

bool operator<(const Point &p1, const Point &p2){
  return p1.value>p2.value;
}

int T;
int M, N, K;
int P[MAXM][MAXN];

int main(){
  scanf("%d", &T);
  while(T--){
    vector<Point> points;
    scanf("%d%d%d", &M, &N, &K);
    for (int i = 1; i <= M; i++){
      for (int j = 1; j <= N; j++){
        scanf("%d", &P[i][j]);
        Point p = {j, i, P[i][j]};
        points.push_back(p);
      }
    }

    sort(points.begin(), points.end());

    int S = 0;
    Point current = {points[0].x, 0, 0};
    size_t pos = 0;
    while(pos < points.size()){
      Point test = points[pos]; 
      int cost = dist(current, test) + 1;
      int total_cost = cost + test.y;
      if (total_cost > K){
        break;
      }
      S += test.value;
      K -= cost;
      current = test;
      pos++;
    }

    printf("%d\n", S);
  }
}

