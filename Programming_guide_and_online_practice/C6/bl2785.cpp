#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
#include<numeric>
#include<utility>
using namespace std;
using namespace std::rel_ops;

struct Person{
  char type;
  int line, row;
  int magic, power, heath;
  int dx, dy;
};

bool operator<(const Person &a, const Person &b){
  if (a.line != b.line)
    return a.line < b.line;
  return a.row < b.row;
}

bool operator==(const Person &a, const Person &b){
  return a.line==b.line && a.row == b.row;
}

int calc_attac(Person &p1){
  switch(p1.type){
  case 'S': return (0.5*p1.magic + 0.5*p1.power) * (p1.heath + 10) / 100.0;
  case 'W': return (0.8*p1.magic + 0.2*p1.power) * (p1.heath + 10) / 100.0;
  case 'E': return (0.2*p1.magic + 0.8*p1.power) * (p1.heath + 10) / 100.0;
  }
  return -1;
}
void fight(Person &p1, Person &p2){
  //printf("Fight:");
  if (p1.type == p2.type)
    return;
  //printf("p1: %c %d %d %d(%d,%d)\n", p1.type, p1.magic, p1.power, p1.heath, p1.line, p1.row);
  //printf("p2: %c %d %d %d(%d,%d)\n", p2.type, p2.magic, p2.power, p2.heath, p2.line, p2.row);

  int p1attack = calc_attac(p1);
  int p2attack = calc_attac(p2);
  p1.heath -= p2attack;
  p2.heath -= p1attack;
}


void play(vector<Person> &persons){
  sort(persons.begin(), persons.end());
  size_t l = 0, r;
  while (l < persons.size()){
    for (r = l; r < persons.size(); r++){
      if (persons[l] != persons[r]){
        break;
      }
    }
    if (r == l + 2){
      fight(persons[l], persons[l+1]);
    }
    l = r;
  }

  for (vector<Person>::iterator it = persons.begin(); it != persons.end();){
    if (it->heath <= 0){
      it = persons.erase(it);
    }else{
      it++;
    }
  }

  for (size_t i = 0; i < persons.size(); i++){
    Person& p = persons[i];
    int x = p.line + p.dx;
    int y = p.row + p.dy;
    if (1 <= x && x <= 12 && 1 <= y && y <= 12){
      p.line = x;
      p.row = y;
    }else{
      p.dx = -p.dx;
      p.dy = -p.dy;
      p.line += p.dx;
      p.row += p.dy;
    }
  }
}
void print_ans(vector<Person> &persons, char type){
  int total_type = 0;
  int total_heath = 0;
  for (size_t i = 0; i < persons.size(); i++){
    if (persons[i].type == type){
      total_type++;
      total_heath += persons[i].heath;
    }
  }
  printf("%d %d\n", total_type, total_heath);
}
int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    int N;
    scanf("%d", &N);

    vector<Person> persons;
    char buf[24];
    while(scanf("%s", buf)&&buf[0]!='0'){
      Person p;
      p.type = buf[0];

      scanf("%d%d%d%d%d", &p.line, &p.row, &p.magic, &p.power, &p.heath);
      if (p.type=='S'){
        p.dx = 1, p.dy = 0;
      }else if (p.type == 'W'){
        p.dx = 0, p.dy = 1;
      }else{
        if ((p.line == 1 && p.row == 12)
          ||(p.line == 12 && p.row == 1)){
          p.dx = 0, p.dy = 0;
        }else{
          p.dx = 1, p.dy = 1;
        }
      }
      persons.push_back(p);
    }

    for (int i = 0; i < N; i++){
    //  printf("==Turn %d\n", i);
    //  for (size_t j = 0; j < persons.size(); j++){
    //    printf("%c(%d,%d): %d %d %d=>%d,%d\n", 
    //      persons[j].type, persons[j].line, 
    //      persons[j].row, persons[j].magic, 
    //      persons[j].power, persons[j].heath,
    //      persons[j].dx, persons[j].dy);
      play(persons);
    }

    print_ans(persons, 'S');
    print_ans(persons, 'W');
    print_ans(persons, 'E');
    printf("***\n");
  }
}
    

