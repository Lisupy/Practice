#include<cstdio>
#include<string>
#include<cstdio>
#include<numeric>
#include<algorithm>
using namespace std;
const int TOTAL_DAY_SECONDS= 60 * 60 * 24;
const int MAX_YEAR = 50010;
int is_leapyear(int year){
  if (year % 4 != 0)
    return false;
  if (year % 100 == 0 && year % 400 != 0)
    return false;
  return true;
}

int is_leapyears[MAX_YEAR];
int leapyears_cnt[MAX_YEAR];

int leapyear_days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leapyear_days_sum[13];
int nonleapyear_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int nonleapyear_days_sum[13];

void init(){
  for(int i = 0; i < MAX_YEAR; i++)
    if (is_leapyear(i))
      is_leapyears[i] = 1;
  partial_sum(is_leapyears, is_leapyears+MAX_YEAR, leapyears_cnt);
  partial_sum(leapyear_days, leapyear_days+13, leapyear_days_sum);
  partial_sum(nonleapyear_days, nonleapyear_days+13, nonleapyear_days_sum);
}

int main(){
  init();
  int N;
  scanf("%d", &N);
  while(N--){
    int hour, minute, second; 
    int day, month, year;
    scanf("%d:%d:%d %d.%d.%d", &hour, &minute, &second, &day, &month, &year);

    long long int total_days = 0;
    total_days += leapyears_cnt[year-1]-leapyears_cnt[1999]+(year-2000)*365;
 //   printf("%lld\n", total_days);
    if (is_leapyear(year))
      total_days += leapyear_days_sum[month-1]+day-1;
    else
      total_days += nonleapyear_days_sum[month-1]+day-1;

    long long int total_seconds = 0;
    total_seconds += total_days * TOTAL_DAY_SECONDS;
    total_seconds += hour*3600+minute*60+second;
    
    total_seconds = total_seconds * 1000/864;
//    printf("total_days:%lld, total_seconds:%lld\n", total_days, total_seconds);
    int downs[6] = {100, 100, 10, 100, 10, 100000000};
    int trans[6] = {0, 0, 0, 1, 1, 0};
    const char* format[] = {":", ":", " ", ".", ".", "\n"};
    int ans[6];
    for (int i = 0; i < 6; i++){
      ans[i] = total_seconds%downs[i]+trans[i];
      total_seconds /= downs[i];
    }
    swap(ans[0], ans[2]);
    for (int i = 0; i < 6; i++){
      printf("%d%s", ans[i],format[i]);
    }
  }
}





