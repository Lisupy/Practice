/*
 * Algorithm: simulation
 * Complexity:
 * IndexBased: 
 * Trick:
 * Layout:
 *    struct Voting;
 *    input();
 *    __process();// return 0 or 1-n
 *    process(); 
 */


#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<cstring>
#include<numeric>
#include<sstream>
using namespace std;


struct Voting{
  vector<string> candiates;
  vector<vector<int> > ballots;

  vector<bool> is_valid;

  void reset(){
    candiates.clear();
    ballots.clear();
    is_valid.clear();
  }

  int input(){
    int n;
    cin >> n;
    candiates.resize(n + 1);

    cin.ignore();
    for (int i = 1; i <= n; i++){
      getline(cin, candiates[i]);
    }
    
    is_valid = vector<bool>(n + 1, true);

    string line;
    while (getline(cin, line) && line.length() > 0){
      istringstream iss(line);
      vector<int> ballot(n);
      for (int i = 0; i < n; i++){
        iss >> ballot[i];
      }
      ballots.push_back(ballot);
    }
    return 0;
  }

  int process(){
    while(true){
      vector<int> counts(candiates.size() + 1, 0);
      int total = 0;
      for (size_t i = 0; i < ballots.size(); i++){
        vector<int> &ballot = ballots[i];
        for (size_t j = 0; j < ballot.size(); j++){
          int vote = ballot[j];
          if (is_valid[vote]){
            counts[vote]++;
            total++;
            break;
          }
        }
      }
      int max_count = *max_element(counts.begin(), counts.end());
      if (max_count == 0){
        return 0;
      }
      int min_count = max_count;
      for (size_t i = 0; i < counts.size(); i++){
        if (counts[i] > 0){
          min_count = min(min_count, counts[i]);
        }
      }

      if (max_count * 2 > total || min_count == max_count){
        for (size_t i = 0; i < counts.size(); i++){
          if (counts[i] == max_count){
            cout << candiates[i] << endl;
          }
        }
        return max_count;
      }

      for (size_t i = 0; i < counts.size(); i++){
        if (counts[i] == min_count){
          is_valid[i] = false;
        }
      }
    }
    return 0;
  }
};

Voting voting;

int main(){
  int T;
  cin >> T;
  while (T--){
    voting.reset();
    voting.input();
    int n = voting.process();
    T && n && printf("\n");
  }
}
