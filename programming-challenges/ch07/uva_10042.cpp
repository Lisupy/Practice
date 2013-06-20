#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;


const int MAXN = 100*1024;
bool is_prime[MAXN];
vector<int> primes;

void init(){
  fill(is_prime, is_prime + MAXN, true);
  for (int n = 2; n < MAXN; n++){
    if (is_prime[n]) primes.push_back(n);
    for (size_t i = 0; i < primes.size(); i++){
      int p = primes[i];
      if (p * n >= MAXN) break;
      is_prime[n * p] = false;
      if (n % p == 0) break;
    }
  }
}

int sum_digit(int n){
  int s = 0;
  while (n){
    s += n % 10;
    n /= 10;
  }
  return s;
}

int sum_prime_factor(int n){
  int s = 0;
  for (size_t i = 0; i < primes.size(); i++){
    if (n == 1) break;
    int p = primes[i];
    if (n < p) break;
    while (n % p == 0){
      s += sum_digit(p);
      n /= p;
    }
  }
  if (n != 1) s += sum_digit(n);
  return s;
}

bool is_prime_f(int n){
  for (size_t i = 0; i < primes.size() && primes[i] < n; i++){
    if (n % primes[i] == 0) return false;
  }
  return true;
}

bool is_smith_number(int n){
  return !is_prime_f(n) && sum_digit(n) == sum_prime_factor(n);
}

int main(){
  init();
  int T;
  cin >> T;
  while(T--){
    int n;
    cin >> n;
    n++;
    while (!is_smith_number(n)) n++;
    cout << n << endl;
  }
}

