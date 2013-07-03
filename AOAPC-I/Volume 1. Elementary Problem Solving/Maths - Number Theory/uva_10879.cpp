#include<iostream>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;

int N, K, A, B, C, D;



const int MAXN = 10*1024*1024;
vector<int> primes;


void init(){
  vector<bool> isPrime(MAXN, true);
  for (int i = 2; i < MAXN; i++){
    if (isPrime[i]){
      primes.push_back(i);
    }
    for (size_t j = 0; j < primes.size(); j++){
      int p = primes[j];
      int s = p * i;
      if (s >= MAXN)break;
      isPrime[s] = false;
      if (i % p == 0){
        break;
      }
    }
  }
}
void update(int p){
  if (A == -1){
    A = p, B = K / A;
  }else{
    C = p, D = K / C;
  }
}
void solve(){
  A = B = C = D = -1;
  for (size_t i = 0; i < primes.size(); i++){
    int p = primes[i];
    if (K % p == 0){
      update(p);
    }
    if (D != -1){
      break;
    }
    if (K % (p * p) == 0){
      update(p * p);
    }
    if (D != -1){
      break;
    }
  }
}
int main(){
  init();
  cin >> N;
  for (int ni = 1; ni <= N; ni++){
    cin >> K;
    solve();
    printf("Case #%d: %d = %d * %d = %d * %d\n", 
      ni, K, A, B, C, D);
  }
}

