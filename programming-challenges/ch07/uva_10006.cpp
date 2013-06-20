#include<cmath>
#include<iostream>
#include<vector>
using namespace std;


const int MAXN = 64 * 1024;

bool is_prime[MAXN];


void is_prime_init(){
  fill(is_prime, is_prime + MAXN, true);

  is_prime[0] = is_prime[1] = false;
  for (int n = 3; n < MAXN; n++){
    for (int i = 2; i * i <= n; i++){
      if (n % i == 0){
        is_prime[n] = false;
        break;
      }
    }
  }
}

bool is_carmichael[MAXN];

unsigned pow_mod(unsigned p, unsigned n, unsigned mod){
  unsigned s = 1;
  while (n){
    if (n % 2) s = (s * p) % mod;
    p = (p * p) % mod;
    n = n / 2;
  }
  return s;
}

void is_carmichael_init(){
  fill(is_carmichael, is_carmichael + MAXN, true);
  for (int n = 3; n < MAXN; n++){
    if (is_prime[n]){
      is_carmichael[n] = false;
      continue;
    }
    for (int i = 2; i < n; i++){
      if ((int)pow_mod(i, n, n) != i){
        is_carmichael[n] = false;
        break;
      }
    }
  }
}


int main(){
  is_prime_init();
  is_carmichael_init();
  int n;
  while (cin >> n && n){
    if (is_carmichael[n]){
      cout << "The number " << n << " is a Carmichael number." << endl;
    }else{
      cout << n << " is normal." << endl;
    }
  }
}
