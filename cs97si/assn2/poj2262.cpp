#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

const int MAXN = 1000000+100;

bool is_prime[MAXN];
int primes[MAXN];
int primes_n;

void init_prime()
{
  for (int i = 0; i <= MAXN; i++)
    is_prime[i] = true;
  
  is_prime[1] = false;

  for (int check_num = 2; check_num <= MAXN; check_num++){
    if (is_prime[check_num])
      primes[primes_n++] = check_num;
    for (int i = 0; i < primes_n; i++){
      int pr = primes[i];
      int not_prime = pr*check_num;
      if (not_prime > MAXN)
        break;
      is_prime[not_prime] = false;
      if (check_num % pr == 0)
        break;
    }
  }
}

void verify_Goldbachs_Conjecture(int n)
{
  for (int i = 0 ;i < primes_n; i++){
    int pr1 = primes[i];
    int pr2 = n - pr1;
    if (is_prime[pr2]){
      printf("%d = %d + %d\n", n, pr1, pr2);
      break;
    }
  }
}

int main()
{
  init_prime();
  int n;
  while (scanf("%d", &n)&&n){
    verify_Goldbachs_Conjecture(n);
  }
  return 0;
}
