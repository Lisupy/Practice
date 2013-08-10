//Clibrary:
#include<cassert>
#include<cctype>
#include<cerrno>
//#include<cfenv>
#include<cfloat>
//#include<cinttypes>
#include<ciso646>
#include<climits>
#include<clocale>
#include<cmath>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
//#include<cstdbool>
#include<cstddef>
//#include<cstdint>
#include<cstdio>
#include<cstdlib>
#include<cstring>
//#include<ctgmath>
#include<ctime>
//#include<cuchar>
#include<cwchar>
#include<cwctype>
//Containers:
//#include<array>
#include<bitset>
#include<deque>
//#include<forward_list>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
//#include<unordered_map>
//#include<unordered_set>
#include<vector>
//Input/Output:
#include<fstream>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<ostream>
#include<sstream>
#include<streambuf>
//Other:
#include<algorithm>
//#include<chrono>
//#include<codecvt>
#include<complex>
#include<exception>
#include<functional>
//#include<initializer_list>
#include<iterator>
#include<limits>
#include<locale>
#include<memory>
#include<new>
#include<numeric>
//#include<random>
//#include<ratio>
//#include<regex>
#include<stdexcept>
#include<string>
//#include<system_error>
//#include<tuple>
//#include<typeindex>
#include<typeinfo>
//#include<type_traits>
#include<utility>
#include<valarray>
using namespace std;

typedef long long i64;
typedef unsigned long long u64;

/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 */
const i64 INF = 1ll << 60;
//i64 cache1[1<<26];
map<pair<int, vector<int> > , i64> cache;
int get_id(const vector<int> cards){
  int total = 0;
  for (size_t i = 0; i < cards.size(); i++) {
    total = total * 5 + cards[i]; 
  }
  return total; 
}
i64 __getCount(int forbiden, vector<int> cards, int n){
  cards[0] = 0;
  pair<int, vector<int> > pr = make_pair(forbiden, cards);
  if (cache.count(pr)){
    return cache[pr];
  }
  if (n == 0) return 1;
  i64 total = 0;
  //cout << n << ": " ;
  //for (auto i : cards) cout << i << ", " ; cout << total << endl;
  for (int i = 1; i <= 4; i++) {
    int cnt = (cards[i] - (i == forbiden)) * i;
    if (cnt > 0){
      cards[i]--;
      cards[i - 1]++;
      i64 s = __getCount(i - 1, cards, n - 1);
      cards[i - 1]--;
      cards[i]++;
      if (s == INF || s >= (INF - total) / cnt){
        total = INF;
        break;
      }
      total += s * cnt;
      if (total == INF){
        total = INF; 
        break;
      }
    }
    assert(total >= 0);
  }
  //for (auto i : cards) cout << i << ", " ; cout << total << endl;
  return cache[pr] = total;
}

i64 getCount(int forbiden, vector<string> cards){
  vector<int> a(5);
  int tf = 0;
  //cout << forbiden << ": " ;
  //for (auto s : cards) cout << s << " " ; cout << endl;
  for (size_t l = 0, r = 0; l < cards.size(); l = r) {
    while (r < cards.size() && cards[r][0] == cards[l][0]){
      r++;
    }
    if ((int)l <= forbiden && forbiden < (int)r){
      tf = r - l;
    }
    a[r - l]++;
  }
  a[tf]--;
  tf--;
  a[tf]++;
  i64 s = __getCount(tf, a, cards.size() - 1);
  //cout << s << endl;
  return s;
}

void solve(char forbiden, vector<string> cards, i64 kth){
  //for (auto i : cards) cout << i << ", " << endl;
  if (cards.size() == 1){
    if (kth == 0){
      cout << " " << cards[0] ;
    }else{
      cout << " Not found";
    }
    return;
  }
  for (size_t i = 0; i < cards.size(); i++) {
    if (cards[i][0] != forbiden){
      i64 s = getCount(i, cards);
      //cout << i << ": " << kth << ", " << s << endl;
      //getchar();
      if (s > kth ){
        cout << " " << cards[i];
        char f = cards[i][0];
        cards.erase(cards.begin() + i);
        solve(f, cards, kth); 
        return;
      }else{
        kth -= s;
      }
    }
  }
  cout << " Not found";
}

int TestNum;
int main(){
  i64 n, k;
  while (cin >> n >> k && n) {
    vector<string> cards(n);
    for (int i = 0; i < n; i++) {
      cin >> cards[i];
    }
    sort(cards.begin(), cards.end());
    cout << "Case " << ++TestNum << ":";
    //cache.clear();
    solve(' ', cards, k - 1);
    cout << endl;
  }
}

