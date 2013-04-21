#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

char buf[1024];
int len;
int n;
int cnt[256];

int main(){
  scanf("%d", &n);
  while(n--){
    memset(cnt, 0, sizeof(cnt));
    scanf("%s", buf);
    for (int i = 0; buf[i]; i++){
      cnt[int(buf[i])]++;
    }
    int *maxp = max_element(cnt, cnt+256);
    printf("%c %d\n", char(maxp - cnt), *maxp); 
  }
}
