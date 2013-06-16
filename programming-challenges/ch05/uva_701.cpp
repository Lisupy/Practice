/*
 * Algorithm: math
 */


#include<cmath>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;

int main(){
  int N;
  while (cin >> N){
    //int E = 1;
    int K = max(2.0, log(N)/log(10) + 2);
    while (true){
      int left = log(N)/log(2) + log(10)/log(2)*K; 
      int right = log(N + 1)/log(2) + log(10)/log(2)*K; 
      if (left < right){
        cout << left + 1<< endl;
        break;
      }
      K++;
    }
  }
}
