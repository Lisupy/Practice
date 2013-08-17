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

const int MAXN = 20* 1024;
int n, Q;

int father[MAXN];
int val[MAXN];
void init(){
  for (int i = 0; i < MAXN; i++) father[i] = i;
  memset(val, 0, sizeof(val));
}

int find(int u){
  assert(val[n] == 0);
  if (father[u] != u){
    int pu = father[u];
    father[u] = find(pu);
    val[u] ^= val[pu];
  }
  return father[u];
}

bool unionSet(int u, int v, int V){
  assert(val[n] == 0);
  int pu = find(u);
  int pv = find(v);
  assert(val[pu] == val[pv]);
  assert(val[pu] == 0);
  if (pu == pv) return V == (val[u] ^ val[v]);
  if (pu == n) swap(pv, pu);
  father[pu] = pv;
  val[pu] = val[u] ^ V ^ val[v];
  return true;
}
int getValue(int *a, int len){
  assert(val[n] == 0);
  map<int, int> M;
  int res = 0;
  for (int i = 0; i < len; i++){
    //cout << a[i] << " : " << find(a[i]) << ", " << val[a[i]] << endl;
    M[find(a[i])]++;
    res ^= val[a[i]];
  }
  for (map<int, int>::iterator it = M.begin(); it != M.end(); it++){
    if (it->first != n && it->second % 2 != 0){
      return -1;
    }
  }
  return res;
}

int TestNum;
int main(){
  //while (true){
    //string line1;
    //getline(cin, line1);
    //istringstream iss1(line1);
    //iss1 >> n >> Q;
    //if (n == 0 && Q == 0) break;
  while(scanf("%d%d" , &n , &Q) && n+Q){  
    printf("Case %d:\n", ++TestNum);
    init();
    int fact_count = 0;
    bool valid = true;
    while (Q--){
      //string line;
      //getline(cin, line);
      //cout << "[" << line << "]" << endl;
      char buf[300];
      scanf("%s" , buf);    
      //if (!valid) continue;
      //istringstream iss(line.substr(2));

      if (buf[0] == 'Q'){
        int k; //iss >> k;
        scanf("%d", &k);
        int a[320];
        //for (int i = 0; i < k; i++) iss >> a[i];
        assert(k < 320);
        for (int i = 0; i < k; i++) scanf("%d", a + i);

        if (!valid) continue;

        int ans = getValue(a, k);
        if (ans == -1) printf("I don't know.\n");
        else printf("%d\n", ans);
      }else{
        //assert(line[0] == 'I');
        fact_count++;
        int p, q, v;
        //int tn = sscanf(line.substr(2).c_str(), "%d %d %d", &p, &q, &v); 
        fgets(buf, 300, stdin);

        if (!valid) continue;

        int cnt = sscanf(buf , "%d%d%d" , &p , &q , &v);  
        if(cnt == 2){  
          v = q;  
          q = n;  
        }  
        //if (tn == 2){v = q; q = n;}
        if (!unionSet(p, q, v)){
          valid = false;
          printf("The first %d facts are conflicting.\n", fact_count );
        }
      }
    }
    printf("\n");
  }
}

