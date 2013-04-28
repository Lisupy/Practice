#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<iostream>
#include<numeric>
#include<algorithm>
using namespace std;


bool is_leapyear(int year){
  if (year % 4 != 0)
    return false;
  if (year % 100 == 0 && year % 400 != 0)
    return false;
  return true;
}

int leapyear_days[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int partial_sum_leapyear_days[13];
int nonleapyear_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int partial_sum_nonleapyear_days[13];

const char* DayOfWeek[13] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void days_to_date(int days, int &year, int &month, int &day){
  year = 2000;
  while(1){
    int year_days = is_leapyear(year)?366:365;
    if (days > year_days){
      days -= year_days;
      year++;
    }else{
      break;
    }
  }

  int* year_days = is_leapyear(year)?partial_sum_leapyear_days:partial_sum_nonleapyear_days;
  month = 0;
  while(year_days[month] < days){
    month++;
  }
  days -= year_days[month-1];

  day = days;
}




int main(){
  int n;
  partial_sum(leapyear_days, leapyear_days+13, partial_sum_leapyear_days);
  partial_sum(nonleapyear_days, nonleapyear_days+13, partial_sum_nonleapyear_days);
  while(scanf("%d", &n) && n != -1){
    int year, month, day;
    days_to_date(n+1, year, month, day);
    printf("%d-%02d-%02d ", year, month, day);
    printf("%s\n", DayOfWeek[(n+6)%7]);
  }
}
