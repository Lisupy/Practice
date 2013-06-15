/*
 * Algorithm:  accumulate, lower_bound, upper_bound, partical_sum
 * Complexity: O(N);
 * IndexBased: 0
 * Trick:
 * LayOut:
 */


#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
using namespace std;

double tolls[24];


struct Record{
  string vehicle;
  string time;
  string event;
  int location;
  void display(){
    cout << vehicle << " " << time << " " << event << " " << location << endl;
  }
};

bool operator<(const Record &a, const Record &b){
  //return a.vehicle < b.vehicle;
  if (a.vehicle != b.vehicle) return a.vehicle < b.vehicle;
  if (a.time != b.time) return a.time < b.time;
  return a.event < b.event;
}

vector<Record> records;

struct Fare{
  double distance;
  double cost;
};

map<string, Fare> fares;

void reset(){
  records.clear();
  fares.clear();
};

char toLower(char c){
  return tolower(c);
}
void input(){
  for (int i = 0; i < 24; i++){
    cin >> tolls[i];
    tolls[i] /= 100;
  }
  cin.ignore();
  string line;
  while (getline(cin, line) && line.size()){
    istringstream iss(line);
    Record r;
    iss >> r.vehicle >> r.time >>  r.event  >> r.location;
    transform(r.event.begin(), r.event.end(), r.event.begin(), toLower);
  //  transform(r.vehicle.begin(), r.vehicle.end(), r.event.begin(), toLower());
    records.push_back(r);
  }
}

int first_two_to_int(string s, int i){
  return atoi(s.substr(i).data());
}

int str_to_time(string s){
  //mm:dd:hh:mm
  //0123456789a
  int acc = 0;
  acc += first_two_to_int(s, 3);
  acc += first_two_to_int(s, 6);
  acc += first_two_to_int(s, 9);
  return acc;
}


void sol(){
  stable_sort(records.begin(), records.end());
  for (size_t l = 0, r = 0; l < records.size(); l++){
    Record &record = records[l];
    if (record.event != "enter"){
      r++;
      continue;
    }
    string name = record.vehicle;
    Fare &f = fares[name];
    r = l + 1;
    if (r < records.size() && records[r].vehicle == name && records[r].event == "exit"){
      Record& start = records[l];
      Record& end = records[r];
      int time1 = atoi(start.time.substr(6).data());
      f.cost += tolls[time1]  * fabs(end.location - start.location);
//      if (end.location != start.location){
        f.cost += 1;
//      }
      f.distance += end.location - start.location;
    }
  }
 // cout << "FK" << endl;
}

void output(){
  for (map<string, Fare>::iterator it = fares.begin(); it != fares.end(); it++){
    double cost = it->second.cost;
    if (cost == 0){
      continue;
    }
    cost += 2;
    cout.precision(2);
    cout.setf(ios::fixed | ios::showpoint);
    cout << it->first << " $" << cost << endl;
  }
}

int main(){
  int cases;
  cin >> cases;
  while (cases--){
    reset();
    input();
    sol();
    output();
    if (cases != 0){
      cout << endl;
    }
  }
}
