#include<cstdio>
#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;



int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int accumulate_days[13];

int date_to_nthday(int month, int day){
  return accumulate_days[month-1]+day;
}

int diff_day(int m1, int d1, int m2, int d2){
  int nd1 = date_to_nthday(m1, d1);
  int nd2 = date_to_nthday(m2, d2);
  return nd2 - nd1;
}
int main(){
  partial_sum(days, days+13, accumulate_days);
  
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++){
    int m1, d1, start, m2, d2;
    scanf("%d%d%d%d%d", &m1, &d1, &start, &m2, &d2);
    int diffday = diff_day(m1, d1, m2, d2);
    int end = start * (1 << diffday);
    printf("%d\n", end);
  }
}


