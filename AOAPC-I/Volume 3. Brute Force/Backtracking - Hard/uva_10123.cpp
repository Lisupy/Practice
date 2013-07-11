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


int TestNum;
int n;
const int MAXN = 1 << 20;
bool cache[MAXN];
int path[32];
double pos[32];
double weight[32];
double leftTorques[32];
double rightTorques[32];
double boardLeftTorque;
double boardRightTorque;
double boardWeight;
double boardLength;
void output(){
  for (int i = 0; i < n; i++){
    printf("%.0lf %.0lf\n", pos[path[i]], weight[path[i]]);
  }
}
bool dfs(int cur, int mask, double lefttorque, double righttorque){
  //printf("%d %d: %lf %lf\n", cur, mask, lefttorque, righttorque);
  if (cur == n){
    output();
    return true;
  }else{
    bool &s = cache[mask];
    if (s == false){
      return false;
    }
    for (int i = 0; i < n; i++){
      //printf("   === %d %d\n", cur, i);
      if (mask & (1 << i)){
        double new_lt = lefttorque - leftTorques[i];
        double new_rt = righttorque - rightTorques[i];
        //printf("  ###%d : %d =>%lf %lf\n", cur, i, new_lt, new_rt);
        if (new_lt >= 0 && new_rt <= 0){
          path[cur] = i;
          if (dfs(cur + 1, mask ^ (1 << i), new_lt, new_rt)){
            return s = true;
          }
        }
      }
    }
    return s = false;
  }
}


void dfs_init(){
  fill (cache, cache + MAXN, true);
  for (int i = 0; i < n; i++){
    leftTorques[i] = (pos[i] - (-1.5)) * weight[i];
    rightTorques[i] = (pos[i] - 1.5) * weight[i];
  }
  double leftLength = boardLength / 2.0 - 1.5;
  double rightLength = boardLength / 2.0 + 1.5;
  double leftWeight = boardWeight * leftLength / boardLength;
  double rightWeight = boardWeight * rightLength / boardLength;
  boardLeftTorque =  -1.0 * leftLength * leftWeight / 2.0 + rightLength * rightWeight / 2.0;
  boardRightTorque =  -boardLeftTorque; 
}

int input(){
  cin >> boardLength >> boardWeight >> n;
  for (int i = 0; i < n; i++){
    cin >> pos[i] >> weight[i];
  }
  return n;
}
int main(){
  while (input()){
    printf("Case %d:\n", ++TestNum);
    dfs_init();
    //cout << boardLeftTorque << ", " << boardRightTorque << endl;
    double totalLeftTorque = accumulate(leftTorques, leftTorques + n, 0.0) + boardLeftTorque;
    double totalRightTorque = accumulate(rightTorques, rightTorques + n, 0.0) + boardRightTorque;
    if (!(totalLeftTorque >= 0 && totalRightTorque <= 0 && dfs(0, (1<<n) - 1, totalLeftTorque, totalRightTorque))){
      cout << "Impossible" << endl;
    }
  }
}
