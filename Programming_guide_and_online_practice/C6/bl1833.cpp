#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int m;
int n, k;
vector<int> a;


int main(){
  cin >> m;
  while (m--){
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++){
      cin >> a[i];
    }
    for (int i = 0; i < k; i++){
      next_permutation(a.begin(), a.end());
    }
    for (int i = 0; i < n; i++){
      cout << a[i];
      if (i == n-1)
        cout<<endl;
      else
        cout<<" ";
    }
  }
}
