/*
 * Algorithm:   simulation
 * Complexity:  N^2
 * IndexBased:  0
 * Trick:       
 * LayOut:
 *  reset();
 *  input();
 *  sol();
 *    for i = (1..n):
 *      pos = find(n);
 *      reverse(get(pos));
 */


#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int a[128];
int n;

int reset(){
  n = 0;
  return 1;
}

int input(){
  string line;
  getline(cin, line);
  if (line.size() == 0){
    return 0;
  }
  istringstream iss(line);
  int t;
  while ( iss >> t){
    a[n++] = t;
  }
  return n;
}

void sol(){
  for (int i = 0; i < n; i++){
    cout << a[i];
    if (i == n - 1){
      cout << endl;
    }else{
      cout << " ";
    }
  }
  
  vector<int> results;
  int m = n;
  for (int i = 0; i < n; i++, m--){
    int pos = max_element(a, a + m) - a;
  //  cout << "#" << pos << ", " << m << endl;
    if (pos == m - 1){
      continue;
    }else if (pos == 0){
      reverse(a, a + m);
    //  cout << n - m + 1 << endl;
      results.push_back(n - m + 1);
    }else{
      reverse(a, a + pos + 1);
    //  cout << n - pos << endl;
      results.push_back(n - pos);

      reverse(a, a + m);
   //   cout << n - m + 1<< endl;
      results.push_back(n - m + 1);
    }
   // for (int j = 0; j < n; j++){
    //  cout << a[j] << " ";
    //}
   // cout << endl;
  }
  results.push_back(0);
//  cout << "0" << endl;
  for (size_t i = 0; i < results.size(); i++){
    if (i != 0){
      cout << " ";
    }
    cout << results[i];
  }
  cout << endl;
}


int main(){
  while (reset() && input()){
    sol();
  }
} 
