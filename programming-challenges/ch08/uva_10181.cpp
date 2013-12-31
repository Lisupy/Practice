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
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
char act[] = {'L', 'R', 'D', 'U'};
int dx[] = { 0 ,  0 ,  1 , -1 };
int dy[] = {-1 ,  1 ,  0 ,  0 };
struct Pos{
  int x, y;
  Pos(int _x = 0, int _y = 0): x(_x), y(_y){}
  bool isValid(){
    return 0 <= x && x < 4 && 0 <= y && y < 4;
  }
};
struct State{
  int a[4][4];
  int cost;
  int get_cost(){
    cost = 0;
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
        int x = a[i][j] / 4;
        int y = a[i][j] % 4;
        cost += abs(x - i) + abs(y - j);
      }
    }
    return cost;
  }
  Pos find(int n){
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
        if (a[i][j] == n){
          return Pos(i, j);
        }
      }
    }
    assert(0);
    return Pos();
  }
  void display(){
    cout << "Cost: " << cost << endl;
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
        cout << a[i][j] << " ";
      }
      cout << endl;
    }
  }
  bool solvable(){
    int *p = (int*)a;
    int s = 3 - find(15).x;
    for (int i = 0; i < 16; i++){
      for (int j = i + 1; j < 16; j++){
        if (p[i] != 15 && p[j] != 15 && p[i] > p[j]) s++;
      }
    }
    return s % 2 == 0;
  }
};
bool operator<(const State &a, const State &b){
  if (a.cost != b.cost) return a.cost > b.cost;
  int *pa = (int*)a.a;
  int *pb = (int*)b.a;
  return lexicographical_compare(pa, pa + 16, pb, pb + 16);
}
//bool operator==(const State &a, const State &b){

//}
void solve(State from){
  if (!from.solvable()){
    cout << "This puzzle is not solvable." << endl;
    return;
  } 
  priority_queue<State> Q;
  map<State, string> M;
  from.get_cost();
  Q.push(from);
  M[from] = "";
  while (!Q.empty()){
    //getchar();
    State s = Q.top(); Q.pop();
    s.get_cost();
    //s.display();
    //cout << M[s] << endl;
    if (s.cost + M[s].size() > 50) continue;
    if (s.cost == 0){
      cout << M[s] << endl;
      return;
    }
    Pos p = s.find(15);
    //cout << p.x << ", " << p.y << endl;
    for (int i = 0; i < 4; i++){
      Pos p1(p.x + dx[i], p.y + dy[i]);
      if (!p1.isValid()) continue;
      State t = s;
      swap(t.a[p.x][p.y], t.a[p1.x][p1.y]);
      t.get_cost();
      if (t.cost + M[s].size() > 50) continue;
      if (!M.count(t)){
        M[t] = M[s] + act[i];
        t.cost = M[t].size() + 1;
        Q.push(t);
      }
    }
  }
  cout << "This puzzle is not solvable." << endl;
}

int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  scanf("%d", &TestNum);
  while (TestNum--){
    State s;
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 4; j++){
        scanf("%d", &s.a[i][j]);
        if (s.a[i][j] == 0) s.a[i][j] = 15;
        else s.a[i][j]--;
      }
    }
    solve(s);
  }
}

