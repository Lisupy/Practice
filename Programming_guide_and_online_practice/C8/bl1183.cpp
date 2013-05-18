#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>



bool check(int a, int b, int c){
  return atan(1.0/a) == atan(1.0/b) + arctan(1.0/c);
}
