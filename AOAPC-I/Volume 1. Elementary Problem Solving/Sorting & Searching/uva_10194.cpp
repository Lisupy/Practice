#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<map>
using namespace std;


struct Team{
  int points;
  int wins;
  int ties;
  int losses;
  int goal_scored;
  int goal_against;
  int goal_diff;
  int game_cnt;
  string name;
  Team():points(0), wins(0), ties(0), losses(0), goal_scored(0), goal_against(0), goal_diff(0), game_cnt(0), name(""){};
  void add_match(int goal1, int goal2){
    game_cnt++;
    goal_scored += goal1;
    goal_against += goal2;
    goal_diff += goal1 - goal2;
    if (goal1 == goal2){
      points++;
      ties++;
    }
    if (goal1 > goal2){
      points += 3;
      wins++;
    }
    if (goal1 < goal2){
      losses++;
    }
  }
  void display(){
    printf("%s %dp, %dg (%d-%d-%d), %dgd (%d-%d)",
      name.c_str(), points, game_cnt, wins, ties, losses, goal_diff, goal_scored, goal_against);
  }
};

#define LESS_RETURN(m) if (a.m != b.m) return a.m < b.m;
#define GRATER_RETURN(m) if (a.m != b.m) return a.m > b.m;

string strTolower(string s){
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}

bool operator<(const Team &a, const Team &b){
  GRATER_RETURN(points);
  GRATER_RETURN(wins);
  GRATER_RETURN(goal_diff);
  GRATER_RETURN(goal_scored);
  LESS_RETURN(game_cnt);
  return strTolower(a.name) < strTolower(b.name);
}

int intFromStr(string s){
  return atoi(s.data());
}
int N;
map<string, Team> teams;
void process(){
  teams.clear();
  string tournament ;
  getline(cin, tournament);
  cout << tournament << endl;
  int T;
  cin >> T;
  cin.ignore();
  for (int i = 0; i < T; i++){
    string s;
    getline(cin, s);
    teams[s].name = s;
  }
  int G;
  cin >> G;
  cin.ignore();
  for (int i = 0; i < G; i++){
    string s;
    getline(cin, s);
    string t1 = s.substr(0, s.find('#'));
    string t2 = s.substr(s.rfind('#') + 1);
    int g1 = intFromStr(s.substr(s.find('#') + 1, s.find('@') - s.find('#') - 1));
    int g2 = intFromStr(s.substr(s.rfind('@') + 1, s.rfind('#') - s.rfind('@') - 1));
    teams[t1].add_match(g1, g2);
    teams[t2].add_match(g2, g1);
  }
  vector<Team> ts;
  for (map<string, Team>::iterator it = teams.begin(); it != teams.end(); it++){
    ts.push_back(it->second);
  }
  sort(ts.begin(), ts.end());
  for (size_t i = 0; i < ts.size(); i++){
    Team &t = ts[i];
    printf("%lu) ", i + 1);
    t.display();
    printf("\n");
  }
}
  

int main(){
  cin >> N;
  cin.ignore();
  while (N--){
    process();
    if (N){
      cout << endl;
    }
  }
}


  
