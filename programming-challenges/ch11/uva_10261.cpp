#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cassert>
using namespace std;

int T;
int L;
vector<int> as;
vector<int> ss;

void input(){
  scanf("%d", &L);
  L *= 100;
  as.clear();
  ss.clear();
  int t;
  int s = 0;
  while (scanf("%d", &t) && t){
    as.push_back(t);
    s += t;
    ss.push_back(s);
  }
}

void solve(){
  int N = as.size();
  bool valid[2][L + 1]; 
  int pre[L + 1];
  fill(&valid[0][0], &valid[1][L] + 1, false);
  fill(pre, pre + L + 1, -1);
  valid[1][0] = true;
  int s = 0;
  int max_load = N;
  int max_pos = 0;
  for (int i = 0; i < N; i++){
//    printf("# %d : %d\n", i, as[i]);  
    int a= as[i];
    bool finded = false;
    fill(&valid[i%2][0], valid[i%2] + L + 1, false);
    for (int j = 0; j <= L; j++){
      if (valid[(i+1)%2][j]){
 //       printf("valid %d ==> %d\n", j, s - j);
        if (j + a <= L){
  //        printf(" set %d pre : %d\n", j + a, i);
          finded = true;
          valid[i%2][j + a] = true;
          if (pre[j + a] == -1){
            pre[j + a] = i;
          }
          max_pos = j + a;
        }
        if (s - j + a <= L){
   //       printf(" set %d \n", j);
          finded = true;
          valid[i%2][j] = true;
          max_pos = j;
        }
      }
    }
    if (!finded){
      max_load = i;
      break;
    }
    s += a;
  }
  cout << max_load << endl;
  vector<string> res;
//  cout << max_pos << endl;
  for (int i = max_load - 1; i >= 0; i--){
    //printf("i : %d, max_pos : %d, pre[%d] : %d\n", i, max_pos, max_pos, pre[max_pos]);
    if (pre[max_pos] == i){
      res.push_back("port");
      max_pos -= as[i];
    }else{
      res.push_back("starboard");
    }
  }
  reverse(res.begin(), res.end());
  int l = 0;
  int r = 0;
  for (size_t i = 0; i < res.size(); i++){
    cout << res[i] << endl;
    if (res[i] == "port"){
      l += as[i];
    }else{
      r += as[i];
    }
  }
 // cout << L << endl;
//  cout << l << ", " << r << endl;
  assert(l <= L && r <= L);
}

int main(){
  cin >> T;
 // T = 1;
  while (T--){
    input();
    solve();
    if (T){
      cout << endl;
    }
  }
}
