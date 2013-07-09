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



struct State{
  bool isNight;
  vector<int> type;
  vector<bool> isLaying;
  State():isNight(false), type(5), isLaying(5){};
  void display(){
    printf("isNight: %d, type: ", isNight);
    for (size_t i = 0; i< type.size();i ++){
      printf(" %d", type[i]);
    }
    printf("  isLaying: ");
    for (size_t i = 0; i < isLaying.size(); i++){
      printf(" %d", (int)isLaying[i]);
    }
    printf("\n");
  }
};


struct Statement{
  int speaker;
  bool neg;
  bool isNight;
  int who;
  int whotype;
};

bool __isTrue(Statement &stat, State &st){
  if (stat.who == -1){
    return stat.isNight == st.isNight;
  }else{
    if (stat.whotype == 4){
      return st.isLaying[stat.who];
    }
    return st.type[stat.who] == stat.whotype;
  }
}
bool isTrue(Statement &stat, State &st){
  bool b = __isTrue(stat, st);
  if (stat.neg){
    b = !b;
  }
  return b;
}

bool allStateValid(vector<Statement> &ss, State &st){
  for (size_t i = 0; i < ss.size(); i++){
    if (st.isLaying[ss[i].speaker] == isTrue(ss[i], st)){
      return false;
    }
  }
  return true;
}

vector<Statement> stats;
const string personStr[] = {
  "",
  "divine",
  "human",
  "evil",
  "lying",
};
int TestNum;
int main(){
  int n;
  while (cin >> n && n){
    printf("Conversation #%d\n", ++TestNum);
    cin.ignore();
    stats.resize(n);
    for (int i = 0; i < n; i++){
      string line;
      getline(cin, line);
      Statement s;
      s.speaker = line[0] - 'A';
      if (line.find("not") != string::npos){
        s.neg = true;
      }else{
        s.neg = false;
      }
      if (line.find("am") != string::npos){
        s.who = s.speaker;
      }else{
        s.who = line[3] - 'A';
      }
      if (line.find("It") != string::npos){
        s.who = -1;
        s.whotype = 0;
        s.isNight = line.find("night") != string::npos;
      }
      if (line.find("lying") != string::npos){
        s.whotype = 4;
      }
      if (line.find("divine") != string::npos){
        s.whotype = 1;
      }
      if (line.find("human") != string::npos){
        s.whotype = 2;
      }
      if (line.find("evil") != string::npos){
        s.whotype = 3;
      }
      stats[i] = s;
    }
    vector<State> valids;
    State s;
    for (int ii = 0; ii < 2; ii++){
      s.isNight = ii == 0;
      for (s.type[0] = 1; s.type[0] <= 3; s.type[0]++){
        for (s.type[1] = 1; s.type[1] <= 3; s.type[1]++){
          for (s.type[2] = 1; s.type[2] <= 3; s.type[2]++){
            for (s.type[3] = 1; s.type[3] <= 3; s.type[3]++){
              for (s.type[4] = 1; s.type[4] <= 3; s.type[4]++){
                if (s.isNight){
                  for (int i = 0; i <= 4; i++){
                    s.isLaying[i] = s.type[i] == 2 || s.type[i] == 3;
                  }
                }else{
                  for (int i = 0; i <= 4; i++){
                    s.isLaying[i] = s.type[i] == 3;
                  }
                }
                if (allStateValid(stats, s)){
                  valids.push_back(s);
                  //s.display();
                }
              }
            }
          }
        }
      }
    }
    if (valids.size() == 0){
      printf("This is impossible.\n\n");
      continue;
    }
    int valid_cnt = 0;
    for (int i = 0; i <= 4; i++){
      bool valid = true;
      for (size_t j = 1; j < valids.size() && valid; j++){
        if (valids[j].type[i] != valids[j - 1].type[i]){
          valid = false;
        }
      }
      if (valid){
        printf("%c is %s.\n", i + 'A', personStr[valids[0].type[i]].c_str());
        valid_cnt++;
      }
    }
    bool valid = true;
    for (size_t j = 1; j < valids.size() && valid; j++){
      if (valids[j].isNight != valids[j - 1].isNight){
        valid = false;
      }
    }
    if (valid){
      valid_cnt++;
      if (valids[0].isNight){
        printf("It is night.\n");
      }else{
        printf("It is day.\n");
      }
    }
    if (valid_cnt == 0){
      printf("No facts are deducible.\n");
    }
    printf("\n");
  }
}




