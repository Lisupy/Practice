#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<utility>
using namespace std;
bool dbg = false;
const int MAX_N = 200;
const int MAX_M = 100;

int main(){
  int n;
  while(scanf("%d", &n)&&n){
    vector<int> m[MAX_N];
    int s = 1;
    for (int i = 0; i < MAX_M; i++){
      if (i != 0)s*=10;
      s%=n;
      vector< pair<int, int> > news;
      for (int j = 0; j < n; j++){
        if (m[j].size() != 0){
          news.push_back(make_pair((j+s)%n, j));
        }
      }
      for (int j = 0; j < news.size(); j++){
        if (m[news[j].first].size() == 0){
          m[news[j].first] = m[news[j].second];
          m[news[j].first].push_back(1);
        }
      }
      for (int j = 0; j < n; j++){
        if(m[j].size() != 0 && m[j].size() != i+1){
          m[j].push_back(0);
        }
      }
      for (int j = 0; j < i; j++){
        m[s].push_back(0);
      }
      m[s].push_back(1);

      if (m[0].size() != 0){
        break;
      }

      if (dbg){
        cout<<"===="<<i<<endl;
        for (int j = 0; j < n; j++){
          cout << j << ":"; 
          for (int k = 0; k < m[j].size(); k++)
            cout << m[j][k];
          cout<<endl;
        }
        cout<<endl;
      }
    }
    for (int i = m[0].size()-1; i >=0; i--)
      cout<<m[0][i];
    cout<<endl;
  }
}
