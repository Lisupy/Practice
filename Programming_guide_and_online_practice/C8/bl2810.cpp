#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<cmath>
using namespace std;

struct Sol{
  int a, b, c, d;
};

bool operator<(const Sol &a, const Sol &b){
  if (a.a != b.a) return a.a < b.a;
  if (a.b != b.b) return a.b < b.b;
  if (a.c != b.c) return a.c < b.c;
  if (a.d != b.d) return a.d < b.d;
  return true;
}


int main(){
  int N;
  cin >> N;

  vector<Sol> sols;


  for (int a = 1; a <= N; a++){
    for (int b = 2; b*b*b < a*a*a; b++){
      for (int c = b; b*b*b+c*c*c < a*a*a; c++){

        int d = exp(log(a*a*a - b*b*b - c*c*c)/3)+0.1;
        if (b*b*b + c*c*c + d*d*d == a*a*a && d >= c){
          Sol s = {a, b, c, d};
          sols.push_back(s);

        }
      }
    }
  }

  sort(sols.begin(), sols.end());

  for (size_t i = 0; i < sols.size(); i++){
    Sol& s = sols[i];
    printf("Cube = %d, Triple = (%d, %d, %d)\n", 
      s.a, s.b, s.c, s.d);
  }
  return 0;
}

