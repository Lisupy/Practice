#include<cstdio>
#include<string>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;




int t;
int n;
vector<string> vs;

bool check(string x, string rx){
  for (size_t i = 0; i < vs.size(); i++){
    if (vs[i].find(x) == string::npos && vs[i].find(rx) == string::npos){
      return false;
    }
  }
  return true;
}

size_t solve(){
  for (size_t try_len = vs[0].size(); try_len > 0; try_len--){
    for(size_t start_pos = 0; start_pos + try_len <= vs[0].size(); start_pos++){
      string x = vs[0].substr(start_pos, try_len);
      string rx = x;
      reverse(rx.begin(), rx.end());
      if (check(x, rx)){
        return try_len;
      }
    }
  }
  return 0;
}


int main(){
  cin>>t;
  while(t--){
    cin>>n;
    vs.resize(n);
    for (int i = 0; i < n; i++){
      cin>>vs[i];
    }
    cout<<solve()<<endl;
  }
}

