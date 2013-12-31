#include<algorithm>
#include<iostream>
#include<cmath>
#include<cassert>
using namespace std;

struct Pos{
  long long x, y;
  Pos(): x(0), y(0){};
  Pos(long long _x, long long _y) : x(_x), y(_y) {}
};

long long area2(Pos a, Pos b, Pos c){
  return (b.y - a.y) * (c.x - a.x) - (b.x - a.x) * (c.y - a.y);
}

bool is_same_sign(long long a, long long b, long long c){
  if (a < 0) return b < 0 && c < 0;
  if (a > 0) return b > 0 && c > 0;
  if (a == 0) return false;
 // assert(0);
  return false;
}

Pos p[10240];
Pos p0(0, 0);
int main(){
  long long N;
  while (cin >> N && N){
    for (long long i = 0; i < N; i++){
      long long s1, s2, s3;
      cin >> s1 >> s2 >> s3;
      p[i].x = s2 - s1;
      p[i].y = s3 - s1;
    }

    for (long long i = 0; i < N; i++){
      if (p[i].x == 0 && p[i].y == 0){
        goto sucess;
      }
    }

    for (long long i = 0; i < N; i++){
      for (long long j = i + 1; j < N; j++){
        if (p[i].x * p[j].y == p[i].y * p[j].x && (p[i].x * p[j].x < 0 || p[i].y * p[j].y < 0) ){
          goto sucess;
        }
      }
    }

    for (long long i = 0; i < N; i++){
      for (long long j = i + 1; j < N; j++){
        for (long long k = j + 1; k < N; k++){
          long long s1 = area2(p0, p[i], p[j]);
          long long s2 = area2(p0, p[j], p[k]);
          long long s3 = area2(p0, p[k], p[i]);
          if (llabs(s1) + llabs(s2) + llabs(s3) == llabs(s1 + s2 + s3)){
            goto sucess;
          }
          //if (is_same_sign(s1, s2, s3)){
            //goto sucess;
          //}
        }
      }
    }
    cout << "No" << endl;
    continue;
sucess:
    cout << "Yes" << endl;
    continue;
  }
}




