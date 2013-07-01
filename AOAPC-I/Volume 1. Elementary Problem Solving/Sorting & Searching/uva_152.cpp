#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;


const double INF = numeric_limits<double>::max();

struct Pos{
  double x, y, z;
  double min_dis;
};

double posDist(Pos &a, Pos &b){
  double s = 0;
  s += (a.x - b.x) * (a.x - b.x);
  s += (a.y - b.y) * (a.y - b.y);
  s += (a.z - b.z) * (a.z - b.z);
  return sqrt(s);
}

vector<Pos> ps;
int counts[10];
int main(){
  double x, y, z;
  while (cin >> x >> y >> z){
    if (x == 0 && y == 0 && z == 0){
      break;
    }
    ps.push_back({x, y, z, INF});
  }
  for (size_t i = 0; i < ps.size(); i++){
    for (size_t j = 0; j < ps.size(); j++){
      if (i == j)continue;
      ps[i].min_dis = min(ps[i].min_dis, posDist(ps[i], ps[j]));
    }
  }

  for (size_t i = 0; i < ps.size(); i++){
    int pos = int(ps[i].min_dis);
    if (pos < 10){
      counts[pos]++;
    }
  }

  for (int i = 0; i < 10; i++){
    printf("%4d", counts[i]);
  }
  printf("\n");
}
