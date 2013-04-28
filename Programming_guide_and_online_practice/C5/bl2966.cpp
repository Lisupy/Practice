#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<numeric>
#include<algorithm>
#include<cctype>
#include<cassert>
using namespace std;


typedef struct{
  const char* name;
  double adjust;
}timezone_t;

timezone_t timezones[] = {
  {"UTC", +0 },
  {"GMT", +0 },
  {"BST", +1 },
  {"IST", +1 },
  {"WET", +0 },
  {"WEST",+1 },
  {"CET", +1 },
  {"CEST",+2 },
  {"EET", +2 },
  {"EEST",+3 },
  {"MSK", +3 },
  {"MSD", +4 },
  {"AST", -4 },
  {"ADT", -3 },
  {"NST", -3.5},
  {"NDT", -2.5},
  {"EST", -5 },
  {"EDT", -4 },
  {"CST", -6 },
  {"CDT", -5 },
  {"MST", -7 },
  {"MDT", -6 },
  {"PST", -8},
  {"PDT", -7},
  {"HST", -10},
  {"AKST",-9 },
  {"AKDT",-8 },
  {"AEST",+10},
  {"AEDT",+11},
  {"ACST",+9.5},
  {"ACDT",+10.5},
  {"AWST",+8 },
  {NULL, 0},
};


int get_zone(char* s){
//  printf("s:%s\n", s);
  for (int i = 0 ; timezones[i].name; i++){
    if (!strcmp(s, timezones[i].name))
      return i;
  }
  assert(0);
  return -1;
}

int main(){
  int N;
  scanf("%d", &N);
  while(N--){
    char time_buf[64];
    char zone_from[64];
    char zone_to[65];
    int th,tm;
    scanf("%s", time_buf);
    if (!strcmp(time_buf, "noon")){
      th = 12;
      tm = 0;
    }else if (!strcmp(time_buf, "midnight")){
      th = 0;
      tm = 0;
    }else{
      sscanf(time_buf, "%d:%d", &th, &tm);
      scanf("%s", time_buf);
      if (th == 12)
        th = 0;
      if (!strcmp(time_buf, "p.m."))
        th+=12;
   //   printf("%d\n", th);
    }
    scanf("%s%s", zone_from, zone_to);
    int from = get_zone(zone_from);
    int to = get_zone(zone_to);
    tm = th*60+tm;

    int utctm = tm - timezones[from].adjust * 60+60*24;
    int totm = utctm + timezones[to].adjust * 60+60*24;
//    printf("%d\n", utctm);
 //   printf("%d\n", totm);
    totm %= 60*24;
  //  printf("%d\n", totm);
    if (totm == 60*12){
      printf("noon\n");
    }else if (totm == 60*24 || totm == 0){
      printf("midnight\n");
    }else{
      th = (totm/60)%12;
      if (th == 0)
        th = 12;
      printf("%d:%02d ", th, totm%60);
      if (totm < 60*12)
        printf("a.m.\n");
      else
        printf("p.m.\n");
    }
  }
}
