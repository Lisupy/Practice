#include<algorithm>
#include<iostream>
#include<numeric>
#include<vector>
#include<cstdio>
using namespace std;


// k = gcd(a, b)
// a = k * ma
// b = k * mb
// * if a < b:
// a % b = a     ==> gcd(a, b) = gcd(b, a) = gcd(b, a = a%b)
// * if b > a:
// a % b = c
// a % b = (k * ma) % (k * mb) = k * (ma % mb)
// gcd(a, b) = gcd(a, c) = gcd(b, c) = gcd(b, a%b)
int gcd(int a, int b){
  if (b == 0) return a;
  if (a == 0) return b;
  return gcd(b, a % b);
}

int gcd3(int a, int b, int c){
  int ab = gcd(a, b);
  int abc = gcd(ab, c);
  return abc;
}

int lcm3(int a, int b, int c){
  int div = gcd3(a, b, c);
  return a*b*c/div/div;
}

int main(){
 
  int case_cnt = 0;

  int p, e, i, d;

  while (true){
    scanf("%d %d %d %d", &p, &e, &i, &d);
    if (p == -1 && e == -1 && i == -1 && d == -1){
      break;
    }

    int next_day = d;
    while (1){
      next_day++;
      if (next_day % 23 == p % 23 && next_day % 28 == e % 28 && next_day % 33 == i % 33){
        break;
      }
    }
    printf("Case %d: the next triple peak occurs in %d days.\n", 
      ++case_cnt, next_day - d);
  }
}
