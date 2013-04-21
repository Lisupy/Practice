#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;



int n;
int key[256];
vector<int> pos[256];

void pre_process(int s){
  vector<int> &v = pos[s];
  v.clear();
  int t = s;
  do{
    v.push_back(t);
    t = key[t];
  }while (s != t);
}


int main(){
  while (cin >> n && n){
    for (int i = 0; i < n; i++){
      cin>>key[i];
      key[i]--;
    }
    for (int i = 0; i < n; i++){
      pre_process(i);
    }
    int k;
    while (cin >> k && k){
      string s,t;
      getline(cin, s);

      s = s.substr(1);
      while (s.size() < size_t(n)){
        s.push_back(' ');
      }

      t = s;
      for (size_t i = 0; i < s.size(); i++){
        const vector<int> &v = pos[i];
        int to_idx = k%v.size();
        int to = v[to_idx];
        t[to] = s[i];
      }
      cout<<t<<endl;
    }
    cout<<endl;
  }
}

