#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<cassert>
using namespace std;


const char* Haab_days[] = {
"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"
};

const char* Tzo_days[] = {
"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau",
};

int Haab_to_int(int year, int month, int day){
  return year*365+month*20+day+1;
}

void int_to_Tzo(int days, int &year, int &part1, int &part2){
  year = (days-1)/260;
  days -= year*260;

  part1 = (days-1) % 13+1;
  part2 = (days-1) % 20;
}

int haab_month_get(char *s){
  for (int i = 0; i <= 19; i++){
    if (strcmp(s, Haab_days[i]) == 0){
      return i;
    }
  }
//  assert(0);
  printf("Error!");
  return 0;
}

int main(){
  int n;
  scanf("%d", &n);
  printf("%d\n", n);
  while (n--){
    int haab_day, haab_month, haab_year;
    char haab_month_str[20];
    scanf("%d. %s %d", &haab_day, haab_month_str, &haab_year);
    haab_month = haab_month_get(haab_month_str);
    
    int days_int = Haab_to_int(haab_year, haab_month, haab_day);
    int tzo_year, tzo_part1, tzo_part2;
    int_to_Tzo(days_int, tzo_year, tzo_part1, tzo_part2);
    
    printf("%d %s %d\n", tzo_part1, Tzo_days[tzo_part2], tzo_year);
  }
}



