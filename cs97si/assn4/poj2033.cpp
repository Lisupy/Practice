#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[10000];
char s[10000];
int main(){
  while(scanf("%s", s+1)&&s[1] != '0'){
    int l = strlen(s+1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= l; i++){
      dp[i] = 0; 
      if (s[i] != '0'){
        dp[i] += dp[i-1];
      }
      if (s[i-1]!='0'&&(s[i-1]-'0')*10+(s[i]-'0')<=26){
        dp[i] += dp[i-2];
      }
    }
    printf("%d\n", dp[l]);
  }
}
  
