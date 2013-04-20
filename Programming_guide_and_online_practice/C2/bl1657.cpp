#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;


int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    char buf1[20];
    char buf2[20];
    scanf("%s%s", buf1, buf2);
    int x1=buf1[0]-'a';
    int x2=buf2[0]-'a';
    int y1=buf1[1]-'0';
    int y2=buf2[1]-'0';

    if (x1==x2 && y1==y2){
      printf("0 0 0 0\n");
      continue;
    }
    int ans[4];
    ans[0] = max(abs(x1-x2), abs(y1-y2));

    if (x1 == x2 || y1 == y2 || abs(x1-x2)==abs(y1-y2))
      ans[1] = 1;
    else
      ans[1] = 2;
    
    if (x1 == x2 || y1 == y2)
      ans[2] = 1;
    else
      ans[2] = 2;
    
    if (abs(x1-x2)%2 != abs(y1-y2)%2)
      ans[3] = -1;
    else if (abs(x1-x2) == abs(y1-y2))
      ans[3] = 1;
    else
      ans[3] = 2;
    
    printf("%d %d %d ", ans[0], ans[1], ans[2]);
    if (ans[3] == -1)
      printf("Inf\n");
    else
      printf("%d\n", ans[3]);
  }
}
