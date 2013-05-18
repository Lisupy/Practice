#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
#include<cstdlib>
using namespace std;

const int MAXN = 32768;
/*
bool is_prime[MAXN];
vector<int> primes;

void gen_primes(){
  fill(is_prime, is_prime+MAXN, true);
  
  for (int i = 2; i < MAXN; i++){
    if (is_prime[i]){
      primes.push_back(i);
    }
    for (size_t j = 0; j < primes.size(); j++){
      int p = primes[j];
      if (i * p >= MAXN)
        break;
      is_prime[i * p] = false;
      if (i % p == 0)
        break;
    }
  }
}
*/

int cnt = 0;
void dfs(int last, int s){
  if(s == 1){
    cnt++;
  }
  for (int i = last; i <= s; i++){
    if (s % i == 0){
      dfs(i, s/i);
    }
  }
}


int main(){
  int n;
  scanf("%d", &n);
  while (n--){
    int a;
    scanf("%d", &a);
    cnt = 0;
    dfs(2, a);
    printf("%d\n", cnt);
    
  }
}

