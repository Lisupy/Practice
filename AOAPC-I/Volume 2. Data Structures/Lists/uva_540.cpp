#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<deque>
#include<queue>
#include<cstdio>
#include<map>
#include<cstdlib>
using namespace std;

int t;
map<int, int> teamId;
void solve(){
  teamId.clear();
  for (int ti = 1; ti <= t; ti++){
    int n;
    cin >> n;
    while (n--){
      int a;
      cin >> a;
      teamId[a] = ti;
    }
  }
  list<queue<int> > Q;
  string cmd;
  //cout << "ff" << endl;
  while (cin >> cmd && cmd != "STOP"){
    if (cmd == "ENQUEUE"){
      int n;
      cin >> n;
      list<queue<int> >::iterator it = Q.begin();
      while (it != Q.end() && teamId[n] != teamId[it->front()]){
        it++;
      }
      if (it == Q.end()){
        queue<int> q;
        q.push(n);
        Q.push_back(q);
      }else{
        it->push(n);
      }
    }else{
      cout << Q.front().front() << endl;
      Q.front().pop();
      if (Q.front().empty()){
        Q.pop_front();
      }
    }
  }
}

  

int main(){
  int TestNum = 0;
  while (scanf("%d", &t) && t){
    printf("Scenario #%d\n", ++TestNum);
    solve();
    printf("\n");
  }
}
