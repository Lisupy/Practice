#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;




int Z, I, M, L;


int getNext(){
  return (Z * L + I) % M;
}


int solve(){
  int first = L;
  set<int> S;
  int cnt = 0;
  while (true){
    //cout << L << endl;
    cnt++;
    S.insert(L);
    L = getNext();
    //cout << L << endl;
    if (S.count(L)){
      break;
    }
  }
  return L == first ? S.size() : S.size() - 1;
}

int TestNum;
int main(){
  while (scanf("%d %d %d %d", &Z, &I, &M, &L)){
    if (Z == 0 && I == 0 && M == 0 && L == 0){
      break;
    }
    printf("Case %d: %d\n", ++TestNum, solve());
  }
}

