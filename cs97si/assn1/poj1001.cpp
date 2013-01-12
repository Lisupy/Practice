#include<cstdio>
#include<cstring>
#include<iostream>
#include<cctype>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int MAXD = 32;
const int MOD = 100*1000;
struct BigNum{
  long long d[MAXD];
  int len;
  int off;
  void set(const char* buf, int buf_len){
    memset(d, 0, sizeof(d));
    int s = 0;
    for (int i = 0; i < buf_len; i++){
      if (buf[i] == '.')
        off = 5 - i;
      else
        s = s*10+buf[i]-'0';
    }
    d[0] = s;
    len = 1;
  }
  void print(){
    len = max(len, off/5+1);
    char buf[4096];
    int buf_len = 0;
    for (int i = len-1; i>=0; i--){
      buf_len += sprintf(buf+buf_len, "%05lld", d[i]);
    }
    
    int dot_pos = buf_len - off;
    memmove(buf+dot_pos+1, buf+dot_pos, off+1); 
    buf[dot_pos] = '.';
    buf_len++;
    int start_idx = 0;
    while(buf[start_idx] == '0')
      start_idx++;

    while(buf[buf_len-1] == '0'){
      buf[buf_len-1] = 0;
      buf_len--;
    }
    if (buf[buf_len-1] == '.'){
      buf[buf_len-1] = 0;
      buf_len--;
    }

    printf("%s\n", buf+start_idx);
  }
  void mul(int r, int roff){
    off += roff;
    int carry = 0;
    for (int i = 0; i < len; i++){
      d[i] = d[i] * r + carry;
      carry = d[i] / MOD;
      d[i] = d[i] %MOD;
    }
    if (carry > 0){
      d[len++] = carry;
    }
  }
};


int main()
{
  char buf[32];
  int n;
  while(scanf("%s%d", buf, &n) != EOF){
    BigNum R, ans;
    R.set(buf, strlen(buf));
    ans.set("1.0000", strlen("1.0000"));
    for (int i = 1; i <= n; i++){
      ans.mul(R.d[0], R.off);
    }
    ans.print();
  }
}




