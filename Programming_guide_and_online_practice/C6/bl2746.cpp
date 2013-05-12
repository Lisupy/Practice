#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;



int Jos(int m, int n){
  vector<int> a;
  for (int i = 1; i <= n; i++){
    a.push_back(i);
  }
  
  int now = n-1;
  for (int i = 1; i <= n-1; i++){
    int sel = (now+m)%a.size();
    a.erase(a.begin() + sel);
    now = (sel -1 + a.size())%a.size();
  }

  return a[0];
}

int main(){
  int n, m;
  while (cin>>n>>m && n && m){
    int s = Jos(m, n);
    cout << s << endl;
  }
}



