#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int MAX_N = 64;
const int MAX_M = 128;

int n,m;

struct DNA{
  int num_of_inversion;
  int len;
  char seq[MAX_N];
  void set(const char* buf, int len){
    num_of_inversion = 0;
    memcpy(seq, buf, len);
    for (int i = 0; i < len; i++){
      for (int j = i+1; j< len; j++){
        if (seq[i] > seq[j])
          num_of_inversion++;
      }
    }
  }

};

bool operator<(const DNA &l, const DNA &r){
  return l.num_of_inversion < r.num_of_inversion;
}


DNA dnas[MAX_M];

int main(){
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++){
    char buf[MAX_N];
    scanf("%s", buf);
    dnas[i].set(buf, n);
  }
  sort(dnas, dnas+m);
  for (int i = 0; i < m; i++){
    printf("%s\n", dnas[i].seq);
  }
}
