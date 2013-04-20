#include<cstdio>
#include<algorithm>
using namespace std;

int a[1024][1024];

int n;

int main(){
  scanf("%d", &n);

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      scanf("%d", &a[i][j]);
    }
  }
  
  int count = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (a[i][j] != 0){
        if ((i > 0 && a[i-1][j] == 0) &&
            (j > 0 && a[i][j-1] == 0)){
          count++;
          a[i][j] = 0;
        }
      }
    }
  }

  printf("%d\n", count);
}
