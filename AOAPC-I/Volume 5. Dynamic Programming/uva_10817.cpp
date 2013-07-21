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

const int MAXS = 8;
const int INF = 0x1f1f1f1f;
int best[1 << (MAXS * 2)];
int S;
int M;
int teacherCost[32];
vector<int> teachers[32];

int N;
int applicantCost[128];
vector<int> applicants[128];



void p_vector(string s, vector<int> a){
  cout << s << ": ";
  for (size_t i = 0; i < a.size(); i++) cout << a[i] << " "; cout << endl;
}
vector<int> vectorFromMask(int mask){
  vector<int> a(S);
  for (int i = 0; i < S; i++){
    a[i] = mask % 4;
    mask /= 4;
  }
  return a;
}

int maskFromVector(vector<int> a){
  int mask = 0;
  for (int i = S - 1; i >= 0; i--){
    mask = mask * 4 + a[i];
  }
  return mask;
}
int mask_update(int mask, vector<int> a){
  vector<int> b = vectorFromMask(mask);
  //p_vector("update", b);
  for (size_t i = 0; i < a.size(); i++){
    b[a[i] - 1]++;
    if (b[a[i] - 1] > 2) b[a[i] - 1] = 2;
  }
  //p_vector("update", b);
  return maskFromVector(b);
}
void p_mask(string s, int mask){
  p_vector(s, vectorFromMask(mask));
}
int main(){
  while (cin >> S >> M >> N && S){
    cin.ignore();
    for (int i = 0; i < M; i++){
      string line; getline(cin, line);
      istringstream iss(line);
      teachers[i].clear();
      iss >> teacherCost[i];
      int t;
      while (iss >> t) teachers[i].push_back(t);
    }
    for (int i = 0; i < N; i++){
      string line; getline(cin, line);
      istringstream iss(line);
      applicants[i].clear();
      iss >> applicantCost[i];
      int t;
      while (iss >> t) applicants[i].push_back(t);
    }
    memset(best, 0x1f, sizeof(best));
    int source = 0;
    for (int i = 0; i < M; i++){
      source = mask_update(source, teachers[i]);
      //p_mask("source", source);
    }
    best[source] = accumulate(teacherCost, teacherCost + M, 0);
    for (int i = 0; i < N; i++){
      for (int s = (1 << (2 * S)) - 1; s >= 0; s--){
        if (best[s] != INF){
          //printf("%d: %d %d\n", i, s, best[s]);
          //p_mask("s", s);
          int ns = mask_update(s, applicants[i]);
          //p_mask("ns", ns);
          best[ns] = min(best[ns], best[s] + applicantCost[i]);
        }
      }
    }
    vector<int> target(S, 2);
    int targetMask = maskFromVector(target);
    printf("%d\n", best[targetMask]);
  }
}


