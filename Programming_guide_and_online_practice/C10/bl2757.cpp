#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;

const int MAXN = 1024;

int N;
vector<int> b;


int LCI(const vector<int>& a){
  vector<int> lci;

  for (size_t i = 0; i < a.size(); i++){
    int t = a[i];
    vector<int>::iterator it = lower_bound(lci.begin(), lci.end(), t);
    if (it == lci.end()){
      lci.push_back(t);
    }else{
      *it = t;
    }
  }
  return lci.size();
}


int main(){
  cin >> N;
  b.resize(N);
  for (int i = 0; i < N; i++){
    cin >> b[i];
  }
  cout << LCI(b) << endl;
}
