#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

struct Pos{
  int x, y;
};

struct Posp{
  double x, y;
};
Pos posFromInt(int n){
  int t  = 1;
  int c = 1;
  while (n > c){
    n -= c;
    t++;
    c += 2;
  }
  Pos p = {t, n};
  return p;
}
Posp pospFromPos(Pos p){
  Posp a;
  if (p.x % 2 == 0){
    a.x = (p.x - 1) * sqrt(3) / 2.0;
    a.y = 0.5 * (p.y - p.x);
  return a;
}

double dist(Posp a, Posp b){
  double s = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
  return sqrt(s);
}

double posFromInt(int from, int to){
  if (from > to){
    swap(from, to);
  }
  Pos p1 = posFromInt(from);
  Pos p2 = posFromInt(to);
  cout << from << ": " << p1.x << ", " << p1.y << endl;
  cout << to << ": " << p2.x << ", " << p2.y << endl;
  Posp a1 = pospFromPos(p1);
  Posp a2 = pospFromPos(p2);
  cout << from << ": " << a1.x << ", " << a1.y << endl;
  cout << to << ": " << a2.x << ", " << a2.y << endl;
  return dist(a1, a2);;
}


int main(){
  int m, n;
  while (cin >> m >> n){
    cout << posFromInt(m + 1, n + 1) << endl;
  }
}

