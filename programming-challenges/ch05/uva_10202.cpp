/*
 * Algorithm:  math, enumeration
 * Complexity: O(N*N ...)
 * IndexBased: 0
 * Trick:      delteing..
 * LayOut:
 *    try(){
 *      for (int i = 3; i < N; i++){
 *        a[i] = min(a) - a[0];
 *        for (int j = 0; j <= i; j++){
 *          if(not_find(a[i]+a[j]))
 *            fail;
 *          delete(a[i] + a[j]);
 *        }
 *      }
 *     }
 */



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
bool __try_solve(vector<int> &a, vector<int> s){
  for (int i = 1; i < N; i++){
    a[i] = s[0] - a[0];
    for (int j = 0; j < i; j++){
      int t = a[i] + a[j];
      vector<int>::iterator it = find(s.begin(), s.end(), t);
      if (it == s.end()){
        return false;
      }else{
        s.erase(it);
      }
    }
  }
  return true;
}

void output_vector(vector<int> a){
  for (size_t i = 0; i < a.size(); i++){
    cout << a[i];
    if (i != a.size() - 1){
      cout << " ";
    }else{
      cout << endl;
    }
  }
}

void solve(vector<int> s){
  vector<int> a(N);
  for (size_t i = 2; i < s.size(); i++){
    int double_s1 = s[0] + s[1] - s[i]; 

    if (double_s1 % 2 == 0){
      a[0] = double_s1/2;
      if (__try_solve(a, s)){
        output_vector(a); 
        return;
      }
    }
  }
  cout << "Impossible" << endl;
}


int main(){
  while (cin >> N){
    vector<int> s(N * (N - 1) / 2);
    for (int i = 0; i < (N * (N - 1) / 2); i++){
      cin >> s[i];
    }
    sort(s.begin(), s.end());
    solve(s);
  //  cout << "Done!" << endl;
  }
}
    
