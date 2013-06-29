#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;



int main(){
  int TestNum = 0;
  long long A, L, numTerms;
  while (cin >> A >> L && A != -1){
    numTerms = 1;

    long long T = A;

    while (T != 1){
      if (T % 2 == 0){
        T = T / 2;
        numTerms++;
      }else{
        T = 3 * T + 1;
        if (T > L){
          break;
        }
        numTerms++;
      }
    }

    printf("Case %d: A = %lld, limit = %lld, number of terms = %lld\n",
      ++TestNum, A, L, numTerms);
  }
}

