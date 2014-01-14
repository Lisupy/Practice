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

int main(){
  while (scanf("%d", &n) && n){
    for (int i = 0; i < n; i++){
      scanf("%lld", &a[i]);
    }
    for (int p = 2; p < 50; p++){
      int best = 0, best_i = -1;
      for (int i = 0; i < n; i++){
        int cnt = 0;
        int k = a[i];
        while(k % p == 0) cnt++, k /= p;
        if (best < cnt) best = cnt, best_i = i;
      }
      for (int i = 0; i < n; i++) if (i != best_i){
        while (a[i] % p == 0) a[i] /= p;
      }
    }
    long long mulAll = 1;
    for (int i = 0; i < n; i++) mulAll *= a[i];
    for (int i = 0; i < n; i++){
      if (i != 0) printf(" ");
      long long x, y;
      long long d = mulAll / a[i];
      extend_gcd(d, a[i], x, y);
      //printf("(%lld)", x);
      long long ans = (a[i] + x%a[i])%a[i] * d;
      if (ans == 0) ans = mulAll;
      printf("%lld", ans);
    }
    printf("\n");
  }

}

