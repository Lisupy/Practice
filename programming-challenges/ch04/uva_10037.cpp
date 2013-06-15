/*
 * Algorithm:   sort, construction, implementation
 * Complexity： N^2
 * IndexBased:  0
 * Trick:       n
 * LayOut:
 *    reset();
 *    input();
 *    sol();
 *      while(){
 *      }
 */


#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

void cals(vector<int> &a, vector<vector<int> > &results){
//  cout << "#" << a.size() << endl;
  if (a.size() == 0){
    return;
  }
  if (a.size() == 1 || a.size() == 2){
    results.push_back(a);
    return;
  }
  if (a.size() == 3){
    vector<int> step1;
    step1.push_back(a[0]);
    step1.push_back(a[1]);
    results.push_back(step1);
    vector<int> step2;
    step2.push_back(a[0]);
    results.push_back(step2);
    vector<int> step3;
    step3.push_back(a[0]);
    step3.push_back(a[2]);
    results.push_back(step3);
    return;
  }
  int A = a[0];
  int B = a[1];
  int C = a[a.size() - 2];
  int D = a[a.size() - 1]; 
  if (C + A + D + A + B < B + A + D + B + B){
    vector<int> step1;
    step1.push_back(A);
    step1.push_back(C);
    results.push_back(step1);

    vector<int> step2;
    step2.push_back(A);
    results.push_back(step2);

    vector<int> step3;
    step3.push_back(A);
    step3.push_back(D);
    results.push_back(step3);

    vector<int> step4;
    step4.push_back(A);
    results.push_back(step4);
  }else{
    vector<int> step1;
    step1.push_back(A);
    step1.push_back(B);
    results.push_back(step1);

    vector<int> step2;
    step2.push_back(A);
    results.push_back(step2);

    vector<int> step3;
    step3.push_back(C);
    step3.push_back(D);
    results.push_back(step3);

    vector<int> step4;
    step4.push_back(B);
    results.push_back(step4);
  }
  a.erase(a.end() - 1);
  a.erase(a.end() - 1);
  cals(a, results);
}
void sol(vector<int> a){
  vector<vector<int> > results;
  cals(a, results);
  int s = 0;
  for (size_t i = 0; i < results.size(); i++){
    s += results[i].back();
  }
  cout << s << endl;
  for (size_t i = 0; i < results.size(); i++){
    vector<int> &step = results[i];
    for (size_t j = 0; j < step.size(); j++){
      cout << step[j];
      if (j == step.size() - 1){
        cout << endl;
      }else{
        cout << " ";
      }
    }
  }
}
vector<int> a;
int input(){
  int n;
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  return n;
}

void reset(){

}

int main(){
  int cases;
  cin >> cases;
  while (cases--){
    reset();
    input();
    sol(a);
    if (cases){
      cout << endl;
    }
  }
}
    

