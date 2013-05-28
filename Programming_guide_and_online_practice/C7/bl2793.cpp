#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 16;

long long a[MAXN];
long long b[MAXN];

int n;
long long s = 1;

long long gcd(long long A, long long B){
  if (B == 0)
    return A;
  return gcd(B, A%B);
}

long long lcm(long long A, long long B){
  return A*B/gcd(A, B);
}

long long extend_gcd(long long A, long long B, long long &x, long long &y){
  if (B == 0){
    x = 1;
    y = 0; 
    return A;
  }else{
    long long tx, ty;
    long long res = extend_gcd(B, A%B, tx, ty);
    y = tx - A/B*ty;
    x = ty;
    return res;
  }
}

bool gao(){
/*
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++){
      if (a[i] == 0 || a[j] == 0) 
        continue;
      if (gcd(a[i], a[j]) != 1){
        return false;
      }
    }
  }
*/
  for (int i = 1; i<= n; i++) {
    if (a[i] == 0){
      b[i] = 0;
      continue;
    }
    long long t = s/a[i];
    long long x, y;
    //  printf("==%lld %lld\n", t, a[i]);
    extend_gcd(t, a[i],  x, y);
    //   printf("%lld %lld\n", x, y);
    while (x <= 0){
      x += a[i];
    }
    b[i] = (x*t%s + s)%s;
  }
  return true;
}

int main(){
  while (scanf("%d", &n) && n){
    for (int i = 1; i <= n; i++){
      scanf("%lld", &a[i]);
    }
/*
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        if (i != j && a[i] >= a[j] && a[j] && a[i] % a[j] == 0){
          a[j] = 0;
        }
      }
    }
    */
    
    long long LCM = a[1];
    for (int i = 1; i <= n; i++){
      LCM = lcm(LCM, a[i]);
    }

    for (int i = 1; i <= n; i++){
      if (a[i] != 0)
        s *= a[i];
    }
    s = LCM;

    if (gao()){
      for (int i = 1; i <= n; i++){
        printf("%lld ", b[i] );
      }
      printf("\n");
    }else{
      printf("NO\n");
    }
  }
}

