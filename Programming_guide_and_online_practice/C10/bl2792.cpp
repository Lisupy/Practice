//Algorithm:  sort, for, upper_bound , lower_bound
//Complexity: N*lgN
//Trick:      upper_bound - lower_bound;
//First_pos:  0


#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 10*1024;

int n;
int s;
int a;
int A[MAXN];
int b;
int B[MAXN];


int main(){
  scanf("%d", &n);
  while (n--){
    scanf("%d", &s);
    scanf("%d", &a);
    for (int i = 0; i < a; i++){
      scanf("%d", &A[i]);
    }
    scanf("%d", &b);
    for (int i = 0; i < b; i++){
      scanf("%d", &B[i]);
    }
    sort(A, A+a);
    sort(B, B+b);
    int total = 0;
    for (int i = 0; i < a; i++){
      int need = s - A[i];
      total += upper_bound(B, B+b, need) - lower_bound(B, B+b, need);
    }
    printf("%d\n", total);
  }
}
