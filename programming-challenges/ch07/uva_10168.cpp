#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;


const int MAXN = 10 * 1024 * 1024;
bool is_prime_tbl[MAXN];

vector<int> primes;


void init(){
  fill(is_prime_tbl, is_prime_tbl + MAXN, true);
  for (int n = 2; n < MAXN; n++){
    if (is_prime_tbl[n]){
      primes.push_back(n);
    }
    for (size_t j = 0; j < primes.size(); j++){
      int p = primes[j];
      if (n * p >= MAXN) break;
      is_prime_tbl[n * p] = false;
      if (n % p == 0) break;
    }
  }
}


int main(){
  init();
//  cout << primes.size() << endl;
  int n;
  while (cin >> n){
    int a, b, c, d;
    if ( n % 2 == 0){
      a = 2, b = 2;
    }else{
      a = 2, b = 3;
    }
    for (size_t k = 0; k < primes.size(); k++){
      c = primes[k];
      if (a + b + c >= n) break;
      d = n - a - b - c;
      if (d < c) break;
      if (binary_search(primes.begin() + k, primes.end(), d)){
        cout << a << " " << b << " " << c << " " << d << endl;
        goto out;
      }
    }
    cout << "Impossible." << endl;
out:;
  }
}


