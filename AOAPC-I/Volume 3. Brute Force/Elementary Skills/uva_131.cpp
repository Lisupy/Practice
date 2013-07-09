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
 * sizeof
 */
const string valueStr = "A23456789TJQKA";
const string suitStr = "CDHS"; 
struct Hand{
  int value[5];
  int suit[5];
  int rank;
  int straight_flush(){
    if (suit[0] != suit[4]){
      return -1;
    }
    return straight();
  }
  int four_of_a_kind(){
    if (value[0] == value[3] || value[1] == value[4]){
      return value[2];
    }
    return -1;
  }
  int full_house(){
    if ((value[0] == value[2] && value[3] == value[4]) ||
        (value[0] == value[1] && value[2] == value[4])){
        return value[2];
    }
    return -1;
  }
  int flush(){
    if (suit[0] == suit[4]){
      return value[5];
    }
    return -1;
  }
  int straight(){
    if (value[0] != 0){
      for (int i = 1; i < 5; i++){
        if (value[i] != value[i - 1] + 1){
          return -1;
        }
      }
      return value[4];
    }else{
      for (int i = 2; i < 5; i++){
        if (value[i] != value[i - 1] + 1){
          return -1;
        }
      }
      if (value[4] == 12 || value[1] == 1){
        return value[4];
      }
      return -1;
    }
    
  }
  int three_of_a_kind(){
    if (value[0] == value[2] || value[1] == value[3] || value[2] == value[4]){
      return value[2];
    }
    return -1;
  }
  int two_pairs(){
    if (value[0] == value[1] && value[2] == value[3]){
      return value[3] * 100 + value[1];
    }
    if (value[0] == value[1] && value[3] == value[4]){
      return value[3] * 100 + value[1];
    }
    if (value[1] == value[2] && value[3] == value[4]){
      return value[3] * 100 + value[1];
    }
    return -1;
  }
  int one_pair(){
    for (int i = 1; i < 5; i++){
      if (value[i] == value[i - 1]){
        return value[i];
      }
    }
    return -1;
  }
  int highest_card(){
    int s = 0;
    for (int i = 4; i >= 0; i--){
      s = s * 20 + value[i];
    }
    return s;
  }
  int get_rank(){
    int ret = 0;
    ret = straight_flush();
    if (ret != -1) return 10000000 * 9 + ret; 
    ret = four_of_a_kind();
    if (ret != -1) return 10000000 * 8 + ret; 
    ret = full_house();
    if (ret != -1) return 10000000 * 7 + ret; 
    ret = flush();
    if (ret != -1) return 10000000 * 6 + ret; 
    ret = straight();
    if (ret != -1) return 10000000 * 5 + ret; 
    ret = three_of_a_kind();
    if (ret != -1) return 10000000 * 4 + ret; 
    ret = two_pairs();
    if (ret != -1) return 10000000 * 3 + ret; 
    ret = one_pair();
    if (ret != -1) return 10000000 * 2 + ret; 
    ret = highest_card();
    return 10000000 * 1 + ret; 
  }
  Hand(vector<string> cards): rank(0){
    for (int i = 0; i <= 4; i++){
      value[i] = valueStr.find(cards[i][0]);
      suit[i] = suitStr.find(cards[i][1]);
    }
    sort(value, value + 5);
    sort(suit,  suit  + 5);
    rank = get_rank();
  }
};
string cards[10];

int input(){
  if (cin >> cards[0]){
    for (int i = 1; i < 10; i++){
      cin >> cards[i];
    }
    return 1;
  }
  return 0;
}

vector<string> get_cards(int mask){
  vector<string> a;
  for (int i = 0; i < 5; i++){
    if ((1 << i) & mask){
      a.push_back(cards[i]);
    }
  }
  for (int i = 0; i < 5 - __builtin_popcount(mask); i++){
    a.push_back(cards[5 + i]);
  }
  return a;
}

int solve(){
  int best = 0;
  for (int mask = 0; mask < (1 << 5); mask++){
    vector<string> tmp = get_cards(mask);
    Hand h(tmp);
    if (h.rank > best){
      best = h.rank;
    }
  }
  return best;
}
const string handtype[] = {
  "",
  "highest-card",
  "one-pair",
  "two-pairs",
  "three-of-a-kind",
  "straight",
  "flush",
  "full-house",
  "four-of-a-kind",
  "straight-flush",
};



int main(){
  while (input()){
    cout << "Hand:";
    for (int i = 0; i < 5; i++){
      cout << " " << cards[i];
    }
    cout << " Deck:";
    for (int i = 5; i < 10; i++){
      cout << " " << cards[i];
    }
    cout << " Best hand: ";
    int ans = solve();
    //cout << ans ;
    cout << handtype[ans/10000000] << endl; 
  }
}
  
