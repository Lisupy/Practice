#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
using namespace std;

int cnt[128];

int main(){
  char c;
  while(scanf("%c", &c) != EOF){
    if (isupper(c))
    cnt[c]++;
  }
  
  //for (int i = 0; i < 4; i++){
  //  char buf[128];
  //  gets(buf);
  //  for (int j = 0; j < strlen(buf); j++){
  //    char c = buf[j];
  //    if (isupper(c))
  //      cnt[c]++;
  //  }
  //}

  char max_cnt_char = max_element(cnt, cnt+128) - cnt;
  int  max_cnt = cnt[max_cnt_char];

  for (int line = max_cnt; line >= 1; line--){
    char end_char = 'Z';
    while(cnt[end_char] < line)
      end_char--;
    for (char c = 'A'; c <= end_char; c++){
      if (c != 'A') printf(" ");
      printf("%s", cnt[c]<line?" ":"*");
    }
    printf("\n");
  }
  for (char c = 'A'; c <= 'Z'; c++){
    if (c != 'A') printf(" ");
    printf("%c",c);
  }
  printf("\n");
}
