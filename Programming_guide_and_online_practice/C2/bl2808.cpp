#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

const int MAXM = 128;

int L,M;
vector<pair<int,int> > cuts;

int main(){
  cin>>L>>M;
  for(int i = 0; i < M; i++){
    int s, t;
    cin>>s>>t;
    cuts.push_back(make_pair(s,t+1));
  }
  sort(cuts.begin(), cuts.end());

  int sum = 0;
  int from = 0, to = 0;
  for (int i = 0; i < cuts.size(); i++){
    int s = cuts[i].first;
    int t = cuts[i].second;

    if (s > to){
      sum += s - to;
      from = s;
      to = t;
    }
    else {
      if (to < t){
        to = t;
      }
    }
  }
  sum += L + 1 - to;
  cout<<sum<<endl;
}
