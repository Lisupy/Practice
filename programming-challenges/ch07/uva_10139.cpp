#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN = 64 * 1024;
bool is_prime_tbl[MAXN];
vector<int> primes;


void is_prime_tbl_init(){
  is_prime_tbl[2] = true;
  for (int n = 3; n < MAXN; n++){
    is_prime_tbl[n] = true;
    for (int i = 2; i * i <= n; i++){
      if (n % i == 0){
        is_prime_tbl[n] = false;
        break;
      }
    }
  }
  for (int n = 2; n < MAXN; n++){
    if (is_prime_tbl[n]){
      primes.push_back(n);
    }
  }
}

bool is_prime(int n){
  if (n == 1){
    return false;
  }
  for (size_t i = 0; i < primes.size() && primes[i] < n; i++){
    if (n % primes[i] == 0) return false;
  }
  return true;
}

int main(){
  is_prime_tbl_init();
  int a, b;
  while (cin >> a >> b){
    bool divided = true;
    if (a == 0) divided = b == 1;
    if (b == 0) divided = false;
    int bak_b = b;
    if (is_prime(b) && a < b){
      divided = false;
    }
    //cout << divided << endl;
    for (size_t i = 0; i < primes.size() && b != 1 && divided; i++){
      int p = primes[i];
      int b_cnt = 0;
      while (b % p == 0){
        b_cnt++;
        b /= p;
    //    cout << p << " " << b << endl;
      }
      int k = a;
      while (b_cnt > 0 && k){
        b_cnt -= k / p;
        k /= p;
      }
      if (b_cnt > 0){
        divided = false;
      }
    }
   // cout << divided << endl;
  //  cout << a << " " << b << endl;
  //  cout << is_prime(b) << endl;
    if (b != 1 && a < b){
      divided = false;
    }
    cout << bak_b << (divided ? " divides " : " does not divide ") << a << "!" << endl;
  }
}



  
