#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;


struct Pos{
  int x, y;
  string s;
  Pos():x(0), y(0), s(""){};
};


int doubleArea(Pos &a, Pos &b, Pos &c){
  return abs((c.y - a.y) * (b.x - a.x) - (b.y - a.y) * (c.x - a.x));
}

Pos ps[128];
int n;

string solve(){
  int maxArea = 0;
  string res = "";
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      for (int k = j + 1; k < n; k++){
        Pos &a = ps[i];
        Pos &b = ps[j];
        Pos &c = ps[k];
        double area = doubleArea(a, b, c);
        bool valid = true;
        for (int check = 0; check < n; check++){
          if (check == i || check == j || check == k){
            continue;
          }
          Pos &d = ps[check];
          if (doubleArea(a, b, d) + doubleArea(a, c, d) + doubleArea(b, c, d) <= area){
            valid = false;
          }
        }
        if (valid && area > maxArea){
          maxArea = area;
          res = a.s + b.s + c.s;
        }
      }
    }
  }
  return res;
}

int main(){
  while (cin >> n && n){
    for (int i = 0; i < n; i++){
      cin >> ps[i].s >> ps[i].x >> ps[i].y;
    }
    cout << solve() << endl;
  }
}


