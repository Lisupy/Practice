//Algorithm:  simulation
//Complexity: O(N)
//IndexBased: 0
//Trick:      
//LayOut:
//  vector
//  accumulate

#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

const int MAXN = 1024 * 4;

int T;

int N;

int P;
int main(){
  cin >> T;

  while (T--){
    cin >> N;
    cin >> P;
    vector<int> hs(P, 0);
    for (int i = 0; i < P; i++){
      cin >> hs[i];
    }

    int lose_days = 0;
    for (int day = 1; day <= N; day++){
      int week_day = (day - 1) % 7;
      if (week_day == 5 || week_day == 6){
        continue;
      }

      for (int j = 0; j < P; j++){
        if (day % hs[j] == 0){
          lose_days++;
          break;
        }
      }
    }

    cout << lose_days << endl;
  }
}
