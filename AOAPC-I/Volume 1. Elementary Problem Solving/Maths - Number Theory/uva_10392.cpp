#include<iostream>
#include<vector>
using namespace std;



const int MAXN = 1000000;

vector<int> primes;

void primes_init(){
  vector<bool> isPrime(MAXN, true);
  for (int n = 2; n < MAXN; n++){
    if (isPrime[n]){
      primes.push_back(n);
    }
    for (size_t i = 0; i < primes.size(); i++){
      int p = primes[i];
      int s = p * n;
      if (s >= MAXN) break;
      isPrime[s] = false;
      if (n % p == 0) break;
    }
  }
}


void factoring(long long n){
  for (size_t i = 0;i < primes.size(); i++){
    int p = primes[i];
    while (n % p == 0){
      cout << "    " << p << endl;
      n /= p;
    }
  }
  if (n != 1){
    cout << "    " << n << endl;
  }
}

int TestNum;
int main(){
  primes_init();
  long long n;
  while (cin >> n && n != -1){
    factoring(n);
    cout << endl;
  }
}
