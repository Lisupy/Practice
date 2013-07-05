#include<iostream>
#include<vector>
#include<deque>
#include<list>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
vector<string> turtles;
vector<string> original;
typedef vector<int>::iterator VIIT;

void input(){
  turtles.clear();
  original.clear();
  cin >> n;
  cin.ignore();
  turtles.resize(n);
  original.resize(n);
  for (int i = 0; i < n; i++){
    getline(cin, turtles[i]);
  }
  for (int i = 0; i < n; i++){
    getline(cin, original[i]);
  }
}

void solve(){
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    a[i] = find(original.begin(), original.end(), turtles[i]) - original.begin();
  }

  for (int last = n - 1; last >= 0; last--){
    //for (int i = 0; i < n; i++){
      //cout << a[i] << ", ";
    //}
    //cout << endl;
    VIIT last_pos = find(a.begin(), a.end(), last);
    bool needed = false;
    for (VIIT it = a.begin(); it != last_pos && !needed; it++){
      if (*it > last){
        needed = true;
      }
    }
    if (needed){
      while ( last_pos != a.begin()){
        *last_pos = *(last_pos - 1);
        last_pos--;
      }
      a[0] = last;
      cout << original[last] << endl;
    }
  }
}


int main(){
  int TestNum;
  cin >> TestNum;
  while (TestNum--){
    input();
    solve();
    cout << endl;
  }
}




