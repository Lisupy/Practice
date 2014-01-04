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
const double PI = acos(-1);
const double pi = 3.141592653589793;
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */

const int MAXN = 128;
const int INF = 0x3f3f3f3f;
const double R = 6378;
struct Pos{
  double x, y, z;
};

Pos getPos(double lt, double ln){
  Pos res;
  res.z = sin(lt);
  res.y = cos(lt) * cos(ln);
  res.x = cos(lt) * sin(ln);
  return res;
}
int getDis(Pos a, Pos b){
  double L = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
  //cout << L << endl;
  return round(asin(L / 2) * 2 * R);
}

map<string, int> cityID;
vector<string> cityName;
vector<Pos> cityPos;
void addCity(string name, double lt, double ln){
  cityID[name] = cityPos.size();
  cityName.push_back(name);
  cityPos.push_back(getPos(lt, ln));
}
int getCityDist(string a, string b){
  return getDis(cityPos[cityID[a]], cityPos[cityID[b]]);
}
int dis[MAXN][MAXN];
void reset(){
  cityID.clear();
  cityName.clear();
  cityPos.clear();
  memset(dis, 0x3f, sizeof(dis));
  for (int i = 0; i < MAXN; i++) dis[i][i] = 0;
}
int N, M, Q;
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  while (cin >> N >> M >> Q && N){
    reset();
    if (TestNum) cout << endl;
    cout << "Case #" << ++TestNum << endl;
    for (int i = 0; i < N; i++){
      string s;
      double lt, ln;
      cin >> s >> lt >> ln;
      lt = lt / 180 * pi;
      ln = ln / 180 * pi;
      addCity(s, lt, ln);
    }
    while (M--){
      string s1, s2; cin >> s1 >> s2;
      dis[cityID[s1]][cityID[s2]] = getCityDist(s1, s2); 
      //cout << dis[cityID[s1]][cityID[s2]] << endl;
    }
    for (int i = 0; i < N; i++){
      for (int s = 0; s < N; s++){
        for (int v = 0; v < N; v++){
          dis[s][v] = min(dis[s][v], dis[s][i] + dis[i][v]);
        }
      }
    }
    while (Q--){
      string s1, s2; cin >> s1 >> s2;
      int dist = dis[cityID[s1]][cityID[s2]];
      if (dist == INF) cout << "no route exists" << endl;
      else cout << dist << " km" << endl;
    }
  }
}

