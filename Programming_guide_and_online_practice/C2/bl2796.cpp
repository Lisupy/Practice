#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;


int a;
int sum;
int main(){
  scanf("%d", &a);
  for (int i = 0; i < 5; i++){
    int num;
    scanf("%d", &num);
    if (num < a){
      sum += num;
    }
  }
  printf("%d\n", sum);
}
