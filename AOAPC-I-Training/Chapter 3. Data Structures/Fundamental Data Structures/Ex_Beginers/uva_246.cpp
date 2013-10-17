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
struct Game{

  queue<int> desk;
  vector<vector<int> > piles;

  Game() : desk(), piles(7) {};
  void init(int a[]){
    for (int i = 0; i < 52; i++) desk.push(a[i]);
  }

  Game& operator=(const Game &other){
    desk = other.desk;
    piles = other.piles;
    return *this;
  }
  Game (const Game &other): desk(other.desk), piles(other.piles) {}

  bool operator<(const Game &other) const {
    if (this->desk != other.desk) return this->desk < other.desk;
    return piles < other.piles;
  }
  bool operator==(const Game &other) const {
    return desk == other.desk && piles == other.piles;
  }
  void play(){
    for (int i = 0; i < 7; i++){
      int c = desk.front(); desk.pop();
      piles[i].push_back(c);
    }
    int qsz = desk.size();
    int turnCnt = 7;

    set<Game> S;
    S.insert(*this);
    
    for (int i = 0; ; i = (i + 1) == 7? 0 : i + 1){
      vector<int> &pile = piles[i];
      if (pile.size() == 0) continue;

      ++turnCnt;

      int c = desk.front(); desk.pop(); qsz--;
      pile.push_back(c); 
      //printf("trun %d, pile %d, %d %d: \n", turnCnt, i, sz, qsz);
      //for (auto k : pile) cout << k << " "; cout << endl;
      while (pile.size() >= 3){
        int sz = pile.size();
        if ((pile[0] + pile[1] + pile[sz - 1]) % 10 == 0){
          desk.push(pile[0]); qsz++;
          desk.push(pile[1]);qsz++;
          desk.push(pile[sz - 1]);qsz++;
          pile.erase(pile.begin(), pile.begin() + 2);
          pile.erase(pile.end() - 1);
        }else if ((pile[0] + pile[sz - 2] + pile[sz - 1]) % 10 == 0){
          desk.push(pile[0]);qsz++;
          desk.push(pile[sz - 2]);qsz++;
          desk.push(pile[sz - 1]);qsz++;
          pile.erase(pile.begin());
          pile.erase(pile.end() - 2, pile.end());
        }else if ((pile[sz - 1] + pile[sz - 2] + pile[sz - 3]) % 10 == 0){
          desk.push(pile[sz - 3]);qsz++;
          desk.push(pile[sz - 2]);qsz++;
          desk.push(pile[sz - 1]);qsz++;
          pile.erase(pile.end() - 3, pile.end());
        }else{
          break;
        }
      }
      if (pile.size() == 0){
        S.clear();
      }
      if (qsz == 52) {
        cout << "Win : " << turnCnt << endl;
        break;
      }
      if (qsz == 0){
        cout << "Loss: " << turnCnt << endl;
        break;
      }
      if (S.count(*this)){
        cout << "Draw: " << turnCnt << endl;
        break;
      }
      S.insert(*this);
    }
    //cout << "Done!" << endl;
  }
};
int TestNum;
int main(){
  int a[52];
  while (scanf("%d", &a[0]) && a[0]){
    for (int i = 1; i < 52; i++) scanf("%d", a + i);
    Game g;
    g.init(a);
    g.play();
  }
}

