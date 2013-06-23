#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<cassert>
using namespace std;

const int MAXN = 128*1280;
vector<int> links[MAXN];

int idNum = 0;
map<pair<string, string>, int> idFromCtiyTime;
pair<string, string> cityTimeFromId[MAXN];
pair<string, string> cct[MAXN];
bool connected[MAXN];
int idFromStr2(pair<string, string> p){
  map<pair<string, string>, int>::iterator it = idFromCtiyTime.find(p);
  if (it != idFromCtiyTime.end()) return it->second;
  cityTimeFromId[idNum] = p;
  idFromCtiyTime.insert(make_pair(p, idNum));
  idNum++;
  assert(idNum < MAXN);
  return idNum - 1;
}

pair<string, string> str2FromId(int id){
  return cityTimeFromId[id];
}

vector<string> citys;
string startTime, fromCity, toCity;

void add_edge(pair<string, string> s, pair<string, string> d){
  int ids = idFromStr2(s);
  int idd = idFromStr2(d);
  links[ids].push_back(idd);
 // graph[ids][idd] = 1;
}
int C, T;
string departure_latest, arrival_earliest;
void input(){
  for (int i = 0; i < MAXN; i++){
    links[i].clear();
  }

  cin >> C;
  citys.resize(C);
  for (int i = 0; i < C; i++){
    cin >> citys[i];
  }

  cin >> T;
  for (int i = 0; i < T; i++){
    int ti;
    cin >> ti;
    vector<pair<string, string> > train(ti);
    for (int j = 0; j < ti; j++){
      cin >> train[j].first >> train[j].second;
    }

    for (int j = 1; j < ti; j++){
      add_edge(train[j], train[j - 1]);
    }
  }
  cin >> startTime >> fromCity >> toCity;
}

void solve(){
  
  for (int i = 0; i < idNum; i++){
    cct[i].first = cityTimeFromId[i].second;
    cct[i].second = cityTimeFromId[i].first;
  }

  sort(cct, cct + idNum);
//  for (int i = 0; i < idNum; i++){
 //   cout << cct[i].first << " " << cct[i].second << endl;
 // }
  //cout << endl;
  for (int l = 0, r = 0; l < idNum; l = r){
    r = l + 1;
    while (r < idNum && cct[l].first == cct[r].first){
      pair<string, string> l1 = cct[r - 1];
      swap(l1.first, l1.second);
      pair<string, string> l2 = cct[r];
      swap(l2.first, l2.second);
      add_edge(l2, l1);
      r++;
    }
  }
 
  vector<pair<string, string> > froms;
  vector<pair<string, string> > tos; 
  for (int i = 0; i < idNum; i++){
    //cout << i << ": " << cityTimeFromId[i].first << " " << cityTimeFromId[i].second << endl;
    pair<string, string> &p = cityTimeFromId[i];
    if (p.second == toCity){
      froms.push_back(p);
    }
    if (p.second == fromCity && p.first >= startTime){
      tos.push_back(p);
   //   cout << i << endl;
    }
  }
  sort(froms.begin(), froms.end());
  sort(tos.begin(), tos.end());

  memset(connected, false, sizeof(connected));
  for (size_t i = 0; i < froms.size(); i++){
    pair<string, string> &from = froms[i];
    int sid = idFromStr2(from);
    queue<int> Q;
    connected[sid] = true;
    Q.push(sid);
    while (!Q.empty()){
      int s = Q.front();
      Q.pop();
      vector<int> &li = links[s];
      for (size_t j = 0; j < li.size(); j++){
        int t = li[j];
        if (connected[t]){
          continue;
        }else{
          connected[t] = true;
          Q.push(t);
        }
      }
    }
   // for (int j = 0; j < idNum; j++){
    //  cout << connected[j];
   // }
    //cout << endl;
    bool finded = false;
    for (size_t j = 0; j < tos.size(); j++){
      pair<string, string> &to = tos[j];
      int tid = idFromStr2(to);
      if (connected[tid]){
        finded = true;
        departure_latest = to.first;
        arrival_earliest = from.first;
      }
    }
  
    if (finded){
      cout << "Departure " << departure_latest << " " << fromCity << endl;
      cout << "Arrival   " << arrival_earliest << " " << toCity   << endl;
      return;
    }
  }
  cout << "No connection" << endl;
}

int main(){
  int TestNum;
  cin >> TestNum;
  for (int ti = 1; ti <= TestNum; ti++){
    idNum = 0;
    idFromCtiyTime.clear();
    cout << "Scenario " << ti << endl;
    input();
    solve();
    cout << endl;
  }
}

