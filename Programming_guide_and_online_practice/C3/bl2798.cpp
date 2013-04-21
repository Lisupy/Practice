#include<cstdio>
#include<cstring>




int n;
char a[10000+20];

int fourbits_string_to_int(char *s, int len){
  int t = 0;
  for (int i = 0; i < len; i++){
    t *= 2;
    t += (s[i] - '0');
  }
  return t;
}



int main(){
  scanf("%d", &n);
  while(n--){
    scanf("%s", a);
    char *pos = a;
    int len = strlen(a);
    while(len>0){
      int l = len%4?len%4:4;
      printf("%X", fourbits_string_to_int(pos, l));
      pos += l;
      len -= l;
    }
    printf("\n");
  }
  return 0;
}
