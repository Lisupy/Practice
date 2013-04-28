#include<cstdio>
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;


int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int sum_days[13];

void init(){
  partial_sum(days, days+13, sum_days);
}

int get_day_int(int m, int d){
  return sum_days[m-1]+d;
}

int main(){
  init();
  int w;
  scanf("%d", &w);
  
  for (int m = 1; m <= 12; m++){
    int day_int = get_day_int(m, 13);
    int day_w = (day_int - 1 + w)%7;
    if (day_w == 5)
      printf("%d\n", m);
  }
}
