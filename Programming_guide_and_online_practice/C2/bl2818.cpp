#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


const int MAXN = 256;

vector<vector<int> > cycles;

vector<int> key;


void get_cycle(int from, vector<int>& cycle, const vector<int> &key){
  cycle = vector<int>();
  int to = from;
  do{
    cycle.push_back(to);
    to = key[to];
  }while(from != to);
}

void init(int N){
  cycles = vector<vector<int> >(N);
  key = vector<int>(N);
}

string trans(int k, const string &from){
  string to(from);
  for (size_t i = 0; i < from.size(); i++){
    const vector<int> &cycle = cycles[i];
    int pos = cycle[k%cycle.size()];
    to[pos] = from[i];
  }
  return to;
}

int main(){
  int n;
  while(cin>>n&&n){
    init(n);
    for (int i = 0; i < n; i++){
      cin>>key[i];
      key[i]--;
    }
    for (int i = 0; i < n; i++){
      get_cycle(i, cycles[i], key);
    }
    int k;
    while(cin>>k&&k){
      string from(' ', n);
      string tmp;
      getline(cin, tmp);

      for (size_t i = 1; i < tmp.size(); i++){
        from[i-1] = tmp[i];
      }
      string to = trans(k, from);
      cout<<to<<endl;
    }
    cout<<endl;
  }
}


