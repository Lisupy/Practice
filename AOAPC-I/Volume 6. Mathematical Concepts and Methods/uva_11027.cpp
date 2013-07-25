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
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 */
map<vector<int>, long long> cache;
long long factor[20];
long long permute_num(vector<int> a, int count){
  while (true){
    vector<int>::iterator it = find(a.begin(), a.end(), 0);
    if (it != a.end()){
      a.erase(it);
    }else{
      break;
    }
  }

  if (a.size() <= 1){
    return 1;
  }
  if (count == (int)a.size()){
    //return factor[count];
  }
  if (cache.count(a)){
    return cache[a];
  }  
  long long total = 0;
  for (size_t i = 0; i < a.size(); i++) {
    //cout << a[i] << endl;
    a[i]--;
    total += permute_num(a, count - 1);
    a[i]++;
  }
  cache[a] = total;
  return total;
}

vector<int> getCnt(string s){
  vector<int> a;
  for (size_t i = 0; i < s.size(); i++){
    if (i == 0 || s[i] != s[i - 1]) a.push_back(0);
    a.back()++;
  }

  return a;
}

string permute(string s, int nth){
  string res;
  vector<int> a = getCnt(s);
  size_t len = s.size();
  s.erase(unique(s.begin(), s.end()), s.end());
  //cout << s << endl;
  if (nth > permute_num(a, len)) return "XXX";
  while (nth && len > res.size()){
    //cout << "nth: " << nth << endl;
    //cout << res << endl;
    //for (size_t j = 0; j < a.size(); j++) cout << a[j]; cout << endl;
    for (size_t i = 0; i < a.size(); i++){
      if (a[i] > 0){
        a[i]--;
        long long pn = permute_num(a, len - res.size());
        //cout << pn << endl;
        //getchar();
        if (pn >= nth){
          res += s[i];
          //cout << s[i];
          break;
        }else{
          a[i]++;
          nth -= pn; 
        }
      }
    }
  }
  return res;
}


int main(){
  factor[0] = 1;
  for (int i = 1; i < 20; i++) factor[i] = factor[i - 1] * i;
  int TestNum; cin >> TestNum;
  for (int ti = 1; ti <= TestNum; ti++){
    //cache.clear();
    string s; int nth; cin >> s >> nth;
    sort(s.begin(), s.end());
    printf("Case %d: ", ti);
    if (s.size() == 1){
      if (nth == 1){
        cout << s << endl;
      }else{
        cout << "XXX" << endl;
      }
      continue;
    }
    vector<int> cnt(128);
    for (size_t i = 0; i < s.size(); i++) cnt[s[i]]++;
    string t;
    int odd_cnt = 0;
    char odd_ch;
    for (size_t i = 0; i < 128; i++){
      if (cnt[i] % 2 ) odd_cnt++, odd_ch = i;
      t += string(cnt[i] / 2, i);
    }
    string odd_str;
    if (odd_cnt == 1){
      odd_str = odd_ch;
    }

    if (odd_cnt >= 2){
      cout << "XXX" << endl;
    }else{
      string res = permute(t, nth);
      if (res == "XXX"){
        cout << res << endl;
      }else{
        string rres(res.rbegin(), res.rend());
        string ans = res + odd_str + rres;
        cout << ans << endl;
      }
    }
  }
}
