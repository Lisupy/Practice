#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int key[256];

void init(){
  for (int i = 0; i < 256; i++){
    key[i] = i;
  }

  rotate(key+'A', key+'Z'-5+1, key+'Z'+1);
}

char buf[256];

int read(){
  char start[256];
  gets(start);
  if (strcmp(start, "START"))
    return -1;
  gets(buf);
  gets(start);
  return 0;
}

int main(){
  init();

  while(read() != -1){
    for (int i = 0; buf[i]; i++){
      printf("%c", key[buf[i]]);
    }
    printf("\n");
  }
}

