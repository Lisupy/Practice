#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int n;
vector<string> nums;
vector<size_t> dot_poss;
size_t max_dot_pos;


int main(){
  cin>>n;

  nums.resize(n);
  dot_poss.resize(n);

  for (int i = 0; i < n; i++){
    cin>>nums[i];
  }

  for (int i = 0; i < n; i++){
    dot_poss[i] = nums[i].find_first_of(".");
  }

  max_dot_pos = *max_element(dot_poss.begin(), dot_poss.end());

  for (int i = 0; i < n; i++){
    nums[i] = string(max_dot_pos - dot_poss[i], ' ') + nums[i];
  }

  for (int i = 0; i < n; i++){
    cout<<nums[i]<<endl;
  }
}
