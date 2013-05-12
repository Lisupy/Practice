#include<cstdio>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;




vector<int> add(vector<int> a, vector<int> b){
  vector<int> c=a;
  int carry = 0;
  for (size_t i = 0; i < a.size(); i++){
    c[i] = a[i]+b[i]+carry;
    if (c[i] >= 10){
      carry = 1;
      c[i] -= 10;
    }else{
      carry = 0;
    }
  }
  if (carry > 0)
    c.push_back(carry);
  return c;
}

set<vector<int> > S;

void gen_set(vector<int> a){
  S.clear();
  S.insert(a);
  for (size_t i = 0; i < a.size(); i++){
    rotate(a.begin(), a.begin()+1, a.end());
    S.insert(a);
  }
}

bool is_cyclic(vector<int> a){
  vector<int> b = a;
  gen_set(a);
  for (size_t i = 2; i <= a.size(); i++){
    b = add(a, b);
    if (S.find(b) == S.end())
      return false;
  }
  return true;
}

int main(){
  string str;
  while(cin>>str){
    vector<int> a;

    for (size_t i = 0; i < str.size(); i++)
      a.push_back(str[i]-'0');
    reverse(a.begin(), a.end());

    if (is_cyclic(a))
      cout << str << " is cyclic" << endl;
    else
      cout << str << " is not cyclic" << endl;
  }
}

