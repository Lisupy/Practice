#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
vector<int> primes;
void initPrimes() {
  vector<bool> isPrime(1000, true);
  for (int i = 2; i < 1000; i++) {
    if (isPrime[i]) primes.push_back(i);
    for (auto p: primes) {
      int s = p * i;
      if (s >= 1000) break;
      isPrime[s] = false;
    }
  }
}
pair<int, int> ans;
void dfs(int cur, int K, int cnt, int idx, int atMost) {
  int p = primes[idx];
  for (int i = 1; i <= atMost; i++) {
    cur *= p;
    if (cur > K) return;
    int newCnt = cnt * (i + 1);
    ans = max(ans, make_pair(newCnt, K - cur + 1));
    dfs(cur, K, newCnt, idx + 1, i);
  }
}
int numOfDivisors(int n) {
  int tot = 1;
  for (auto p: primes) {
    int cnt = 0;
    while (n % p == 0) cnt++, n /= p; 
    tot *= (cnt + 1);
  }
  if (n > 1) tot *= 2;
  return tot;
}
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  initPrimes();
  int K; cin >> K;
  dfs(1, K, 1, 0, 1000);
  cout << ans.second << endl;
}