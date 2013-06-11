/*
 * Algorithm: simulation
 * Complexity:
 * IndexBased: 1
 * Trick:     struct, sort, 
 *            which is the valid submission
 * Layout:
 *  reset();
 *
 *  struct Constant{
 *    display();
 *  }
 *  bool operator<
 */


#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

struct Constant{
  int id;
  int trys[10];
  bool solved[10];
  int num_solved;
  int total_time;
  int submit_nums; 


  void display(){
    cout << id << " " << num_solved << " " << total_time << endl;
  }

  
  void set(int prob_id, int submit_time, char L){
    submit_nums++;
    if (solved[prob_id]){
      return;
    }
    if (L == 'C'){
      solved[prob_id] = true;
      num_solved++;
      total_time += submit_time + trys[prob_id] * 20;
    }
    if (L == 'I'){
      trys[prob_id]++;
    }
  }
};

bool operator<(const Constant& a, const Constant& b){
  if (a.num_solved != b.num_solved) return a.num_solved > b.num_solved;
  if (a.total_time != b.total_time) return a.total_time < b.total_time;
  return a.id < b.id;
}

Constant constants[101];

void reset(){
  memset(constants, 0, sizeof(constants));
  for (int i = 1; i <= 100; i++){
    constants[i].id = i;
  }
}

void input(){
  while (true){
    string line;
    getline(cin, line);
  //  cout << "[" << line << "]" << endl;
    if (line == "" || line == "\n"){
      break;
    }

    istringstream iss(line);
    int team, prob, submit_time;
    string status;
    iss >> team >> prob >> submit_time >> status;
    constants[team].set(prob, submit_time, status[0]);
  }
}

void output(){
  sort(constants + 1, constants + 101);
  for (int i = 1; i <= 100; i++){
    Constant &constant = constants[i];
    if (constant.submit_nums != 0){
      constant.display();
    }
  }
}

int main(){
  int num_test_cases;
  cin >> num_test_cases;
  cin.ignore();
  cin.ignore();
  while (num_test_cases--){
    reset();
    input();
    output();
    if (num_test_cases != 0){
      printf("\n");
    }
  }
}
