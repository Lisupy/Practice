/*
 * Algorithm:   prim
 * Complexity:  N*log(N)
 * IndexBased:  0
 * Trick:
 * LayOut:
 *    int cityNum;
 *    map<string, int> idFromCity;
 *    vector<pair<int, int>> links[MAXN];
 *    reset();
 *    input();
 *    buildgraph();
 *    prime();
 */

#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<queue>
#include<cstring>
#include<map>
#include<limits>
using namespace std;

const int MAXN = 1024 * 24;
int TestNum = 0;
int cityNum = 0;
map<string, int> idFromCity;
vector<pair<int, int> > links[MAXN];
int length[MAXN];


void reset(){
  cityNum = 0;
  idFromCity.clear();
  for (int i = 0; i < MAXN; i++){
    links[i].clear();
  }
  memset(length, 0, sizeof(length));
}

int idFromStr(string s){
  map<string, int>::iterator it = idFromCity.find(s);
  if (it == idFromCity.end()){
    idFromCity.insert(make_pair(s, cityNum++));
    return cityNum - 1;
  }
  return it->second;
}
int from, to;
void input(){
  int routeNum;
  cin >> routeNum;
  while (routeNum--){
    string s, t;
    int begin, end;
    cin >> s >> t >> begin >> end;
    int s_id = idFromStr(s);
    int t_id = idFromStr(t);
    if (end > 12){
      continue;
    }
 //   cout << s << ", " << t << begin << " " <<end << endl;
    begin = (begin - 1) % 24 + 1;
    end   = (begin + end - 1) % 24 + 1;
  //  cout << begin << " " << end << endl;
    if (6 <= begin && begin < 18) continue; 
    if (6 < end && end <= 18) continue;
   // cout << "ok" << endl;
    links[s_id * 24 + begin - 1].push_back(make_pair(t_id * 24 + end - 1, 0));
    //cout << s_id * 24 + begin - 1 << "=>" << t_id * 24 + end - 1 << endl;
  }
  string s, t;
  cin >> s >> t;
  from = idFromStr(s);
  to = idFromStr(t);
}

int Prim(){
  //cout << from << "=> " << to << endl;
  //cout << from * 24 + 17 << "=> " << to * 24 + 5<< endl;
  ////////////////cout << cityNum << endl;
  int M = cityNum * 24;
  for (int i = 0; i < M; i++){
    int t = i % 24;
    if (t == 23){
      links[i].push_back(make_pair(i - 23, 0));
    }else if (t >= 17 || t < 5){
      links[i].push_back(make_pair(i + 1, 0));
    }else if (t == 5){
      links[i].push_back(make_pair(i + 12, 1));
    }
  }
  fill(length, length + MAXN, numeric_limits<int>::max());
  priority_queue<pair<int, int> > Q;
  Q.push(make_pair(0, from * 24 + 17));
  length[from * 24 + 17] = 0;
  while (!Q.empty()){
    int s = Q.top().second;
    int sl = Q.top().first;
   // cout << s << ", " << sl << endl;
    Q.pop();
    if (length[s] > sl){
      continue;
    }
    vector<pair<int, int> > &link = links[s];
    for (size_t i = 0; i < link.size(); i++){
      int t = link[i].first;
      int w = link[i].second;
      if (length[s] + w < length[t]){
        length[t] = length[s] + w;
        Q.push(make_pair(length[t], t));
      }
    }
  }
  return length[to * 24 + 5];
}

int main(){
  cin >> TestNum;
  for (int TestIdx = 1; TestIdx <= TestNum; TestIdx++){
    reset();
    input();
    int res = Prim();
    cout << "Test Case " << TestIdx << "." << endl;
    if (res == numeric_limits<int>::max()){
      cout << "There is no route Vladimir can take." << endl;
    }
    else{
      cout << "Vladimir needs " << res << " litre(s) of blood." << endl;
    }
  }
}


