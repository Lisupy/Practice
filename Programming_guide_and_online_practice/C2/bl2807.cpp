#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> a;

int read(){
  int t;
  
  a = vector<int>();

  scanf("%d", &t);
  if (t == -1)
    return -1;

  do{
    a.push_back(t);
  }while(scanf("%d", &t)&&t);

  return 0;
}

int main(){
  while(read() != -1){
    int count = 0;
    for (int i = 0; i < a.size(); i++){
      for (int j = 0; j < a.size(); j++){
        if (a[i] == a[j]*2){
          count++;
        }
      }
    }
    printf("%d\n", count);
  }
}


