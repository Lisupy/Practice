/*
 * Algorithm:   sort, count the differences
 * Complexity:  sort, O(N)
 * IndexBased:  0
 * Trick:       time_to_int
 * LayOut:
 *    reset();
 *    input();
 *      time_str_to_int();
 *      struct {time1, time2};
 *    sol();
 */


#include<vector>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<vector>
#include<numeric>
#include<cassert>
using namespace std;


struct Sched{
  int time1;
  int time2;
};

bool operator<(const Sched &a, const Sched &b){
  return a.time1 != b.time1? a.time1 < b.time1 : a.time2 < b.time2;
}

int time_str_to_int(string s){
  return ((s[0] - '0')*10+(s[1] - '0')) * 60 + (s[3] - '0')*10 + (s[4] - '0');
}

string time_int_to_str(int t){
  char buf[24];
  sprintf(buf, "%02d:%02d", t/60, t%60);
  return buf;
}

vector<Sched> scheds;

void reset(){
  
}

int input(){
  int n;
  if (cin >> n){
    assert(n != 0);
    scheds.resize(n);
    for (int i = 0; i < n; i++){
      string s1, s2, s3;
      cin >> s1 >> s2;
      getline(cin, s3);
      scheds[i].time1 = time_str_to_int(s1);
      scheds[i].time2 = time_str_to_int(s2);
    }
    return 1;
  }else{
    return 0;
  }
}

void sol(){
  sort (scheds.begin(), scheds.end());
  int start = time_str_to_int("10:00");
  int end   = time_str_to_int("18:00");
  int max_nap = scheds[0].time1 - start;
  int max_start = start;
  for (size_t i = 0; i <= scheds.size(); i++){
    int time1 = i < scheds.size() ? scheds[i].time1 : end;
    int time2 = (int)i - 1 >= 0 ? scheds[i - 1].time2 : start;
    int nap = time1 - time2;
    assert(nap >= 0);
    if (max_nap < nap){
      max_nap = nap;
      max_start = scheds[i - 1].time2;
    }
  }
  cout << "the longest nap starts at " << time_int_to_str(max_start) <<  " and will last for ";
  if (max_nap >= 60){
    cout << max_nap / 60 << " hours and ";
  }
  cout << max_nap % 60 << " minutes." << endl;
}

int main(){
  int case_cnt = 0;
  while (input()){
    cout << "Day #" << ++case_cnt << ": ";
    sol();
  }
}
