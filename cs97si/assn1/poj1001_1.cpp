//怎么写都不好看，最好重新写一次
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXD = 5;
const int MOD = 100000;
const int MAXN = 32;
const int off_mod[] = {1, 10, 100, 1000, 10000, 100000};


struct BigNum{
  int d[MAXN];
  int d_len;
  int off;
  void clear(){
    memset(d, 0, sizeof(d));
    d_len = 0;
    off = 0;
  }
  void set(const char *buf, int len){
    clear();
    d_len = 1;
    int s = 0;
    for (int i = 0; i < len; i++){
      if (isdigit(buf[i]))
        s = s*10+buf[i]-'0';
      else
        off = len - i - 1;
    }
    d[0] = s;
  };
  void print(){
    d_len = max(d_len, off/MAXD+1);
    char buf[4096];
    int buf_len = 0;
    for (int i = d_len - 1; i >= 0; i--){
      int dd = d[i];
      if(MAXD*i <= off && off < MAXD*(i+1)){
        int roff = off - MAXD*i;
        int omod = off_mod[roff];
        buf_len += sprintf(buf+buf_len,"%d.",dd/omod);
        if (roff != 0){
          char fmt[16];
          sprintf(fmt, "%%0%dd", roff);
       //   printf("fmt:[%s]", fmt);
          buf_len += sprintf(buf+buf_len, fmt,dd%omod);
        }
      }
      else{
        if (i == d_len -1)
          buf_len += sprintf(buf+buf_len, "%d", dd);
        else
          buf_len += sprintf(buf+buf_len, "%05d", dd);
      }
    }
    while(buf[buf_len-1]=='0'){
      buf[buf_len-1] = 0;
      buf_len--;
    }
    if (buf[buf_len-1] == '.'){
      buf[buf_len-1] = '\0';
      buf_len--;
    }
    for (int i = 0; i < buf_len; i++){
      if (buf[i] != '0'){
        printf("%s", buf+i);
        return;
      }
    }
    printf("0");
    // printf(" ");
  };
  void mul(int dr, int roff){
    off+=roff;
    int carry  = 0;
    for (int i = 0; i < d_len; i++){
      long long di = d[i];
      di= di * dr + carry;
      carry=di/MOD;
      d[i]=di%MOD;
    }
    while(carry > 0){
      d[d_len]=carry%MOD;
      carry=carry/MOD;
      d_len++;
    }
  };
  void debug(){
    printf("off:%d, d_len:%d, ", off, d_len);
    for (int i = d_len - 1; i >= 0; i--){
      printf("%05d", d[i]);
    }
    printf("\n");
  }
};



int main(){
  BigNum R;
  BigNum ans;
  int n;
  char R_buf[32];
  while(scanf("%s %d", R_buf, &n)!=EOF){
    R.set(R_buf, 6);
    ans.clear();
    ans = R;
    for (int i = 1; i < n; i++){
      ans.mul(R.d[0], R.off);
    }
    ans.print();
    printf("\n");
  }
}
