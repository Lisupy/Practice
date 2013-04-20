#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student{
  char name[32];
  int  score;
  int  pop;
  char is_west;
  char is_leader;
  int  paper;
  int  money;
};

Student stu[128];
int N;

void calc_money(Student& s){
  if(s.score > 80 && s.paper >= 1)
    s.money += 8000;
  if(s.score > 85 && s.pop > 80)
    s.money += 4000;
  if(s.score > 90)
    s.money += 2000;
  if(s.score > 85 && s.is_west == 'Y')
    s.money += 1000;
  if(s.pop > 80 && s.is_leader == 'Y')
    s.money += 850;
}

int main(){
  scanf("%d", &N);
  for (int i = 0; i < N; i++){
    scanf("%s %d %d %c %c %d", stu[i].name, &stu[i].score, &stu[i].pop, &stu[i].is_leader, &stu[i].is_west, &stu[i].paper);
    calc_money(stu[i]);
  }
  int maxi = 0;
  for (int i = 0; i < N; i++){
    if (stu[maxi].money < stu[i].money){
      maxi = i;
    }
  }

  int sum_money = 0;
  for (int i = 0; i < N; i++)
    sum_money += stu[i].money;

  printf("%s\n", stu[maxi].name);
  printf("%d\n", stu[maxi].money);
  printf("%d\n", sum_money);
}

