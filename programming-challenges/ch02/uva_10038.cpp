//Algorithm:  for-one-pass
//Complexity: O(N)
//IndexBased: 0
//Trick:
//LayOut:        
//  vector
//  is_jolly_jumpers



#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
#include<numeric>
#include<iostream>
#include<istream>
#include<iterator>
using namespace std;


const int MAXN = 30000;



bool is_jolly_jumpers(vector<int> ns){
  vector<int> diffs;
  adjacent_difference(ns.begin(), ns.end(), back_inserter(diffs));
  diffs[0] = 0;
  for (size_t i = 0; i < diffs.size(); i++){
    diffs[i] = abs(diffs[i]);
  }
  sort(diffs.begin(), diffs.end());

  for (size_t i = 0; i < diffs.size(); i++){
    if (diffs[i] != int(i)){
      return false;
    }
  }

  return true;
}


int main(){
  int n;
  while (cin >> n){
    vector<int> ns(n);
    for (size_t i = 0; i < ns.size(); i++){
      cin >> ns[i];
    }

    if (is_jolly_jumpers(ns)){
      cout << "Jolly" << endl;
    }else{
      cout << "Not jolly" << endl;
    }
  }
}
    
