#include<cmath>
#include<iostream>
using namespace std;



long long gcd(long long p, long long q, long long &x, long long &y){
  long long x1, y1;
  long long g;
  
  if (p < q) return gcd(q, p, y, x);

  if (q == 0){
    x = 1, y = 0;
    return p;
  }

  g = gcd(q, p % q, x1, y1);
  x = y1;
  y = x1 - floor(p / q * y1);
  return g;
}


int main(){
  long long c1, c2, n1, n2, n;
  while (cin >> n && n){
    cin >> c1 >> n1;
    cin >> c2 >> n2;
    long long x1, x2, g;
    g = gcd(n1, n2, x1, x2);
    if (n % g != 0){
      cout << "failed" << endl;
      continue;
    }
    n1 /= g, n2 /=g , n /= g;
    //long long m = n1 * n2;
    long long low = ceil(-(n * x1) / (double)n2);
    long long high = floor(x2 * n / (double)n1);
    if (low > high){
      cout << "failed" << endl;
      continue;
    }

    long long k = (c1 * n2 > c2 * n1) ? low : high;
    long long m1 = n * x1 + k * n2;
    long long m2 = n * x2 - k * n1;
    cout << m1 << " " << m2 << endl;
  }
}


