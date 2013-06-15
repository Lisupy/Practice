/*
 * Algorithm:  OO
 * Complexity:
 * Trick:      struct, cmp
 * IndexBased: 0
 * LayOut:
 */

#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
#include<iostream>
#include<vector>
#include<cctype>
#include<map>
#include<sstream>
using namespace std;


struct Team{
  int points;
  int goals_differences;
  int goals_scored;
  int goals_against;
  int games;
  int wins;
  int losses;
  int ties;
  string name;
  void add_game(int get, int lost){
    goals_differences += get - lost;
    games++;
    goals_scored += get;
    goals_against += lost;
    if (get < lost){
      losses++;
    }
    if (get == lost){
      ties++;
      points += 1;
    }
    if (get > lost){
      points += 3;
      wins++;
    }
  }
};

string str_tolower(string s){
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}

bool cmp(const Team &a, const Team &b){
  if (a.points != b.points)return a.points > b.points;
  if (a.wins != b.wins) return a.wins > b.wins;
  if (a.goals_differences != b.goals_differences) return a.goals_differences > b.goals_differences;
  if (a.goals_scored != b.goals_scored) return a.goals_scored > b.goals_scored;
  if (a.games != b.games) return a.games < b.games;
  return str_tolower(a.name) < str_tolower(b.name);
}

bool operator<(const Team &a, const Team &b){
  return a.name < b.name;
};

map<string, Team> teams;

void process_game(string s){
  //team_name_1#goals1@goals2#team_name_2
  //         pos1    pos2  pos3
  size_t pos1 = s.find('#');
  size_t pos2 = s.find('@');
  size_t pos3 = s.rfind('#');
  string team1 = s.substr(0, pos1);
  int goals1 = atoi(s.substr(pos1 + 1).data());
  int goals2 = atoi(s.substr(pos2 + 1).data());
  string team2 = s.substr(pos3 + 1);

  //cout << "[" << team1 << "," << team2 << "]" << endl;
  //cout << "[" << goals1 << "," << goals2 << "]" << endl;
  teams[team1].add_game(goals1, goals2);
  teams[team2].add_game(goals2, goals1);
}

void input(){
  string tournament; 
  getline(cin, tournament);
  cout << tournament << endl;
  int T;
  cin >> T;
  cin.ignore();
  for (int i = 0; i < T; i++){
    string name;
    getline(cin, name);
    teams[name].name = name;
  }

  int G;
  cin >> G;
  cin.ignore();
  for (int i = 0; i < G; i++){
    string game;
    getline(cin, game);
    process_game(game);
  }
}

void output(){
  vector<Team> ts;
  for (map<string, Team>::iterator it = teams.begin(); it != teams.end(); it++){
    ts.push_back(it->second);
  }

  sort(ts.begin(), ts.end(), cmp);
  for (size_t i = 0; i < ts.size(); i++){
    Team &t = ts[i];
    printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
      (int)i + 1,
      t.name.c_str(),
      t.points,
      t.games,
      t.wins, t.ties , t.losses,
      t.goals_differences,
      t.goals_scored, t.goals_against);
  }
}

void reset(){
  teams.clear();
}

int main(){
  int N;
  cin >> N;
  cin.ignore();
  while (N--){
    reset();
    input();
    output();
    if (N){
      cout << endl;
    }
  }
}

