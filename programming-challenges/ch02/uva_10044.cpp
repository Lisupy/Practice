/*
 * Algorithm:   floyd
 * Complexity:  O(N^3)
 * IndexBased:  0
 * Trick:       string parse
 * LayOut:
 *  reset();
 *  numScenarios
 *  input()
 *  get_id_by_name()
 *  process() // floyd
 */
/*
 *  query上出现的名字，在papers上不一定有
 *  papers建立邻接表，要避免重复，考虑用set
 *  数据有误。当只有一个作者的pater，是这种格式的Hsueh, Z. : XXXX
 */

#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<queue>
#include<set>
using namespace std;

const int INF = 0x7fffff;
int numScenarios;
int P, N;

vector<string> names;
map<string, int> ids;
vector<set<int> > adjacent;

void reset(){
  names.clear();
  ids.clear();
  adjacent.clear();
}

int get_id_by_name(string name){
  map<string, int>::iterator it;
  it = ids.find(name);
  if (it == ids.end()){
    names.push_back(name);
    ids.insert(make_pair(name, names.size() - 1));
    return names.size() - 1;
  }else{
    return it->second;
  }
}

int main(){
  cin >> numScenarios;
  cin.ignore();
  for (int scenario_i = 1; scenario_i <= numScenarios; scenario_i++){
    reset();
    cout << "Scenario " << scenario_i << endl;
    cin >> P >> N;
    if (P == 0){
      break;
    }
    cin.ignore();

    while (P--){
      string line;
      getline(cin, line);
      int end_pos = line.find(':');
      //for the wrong input
      while (line[end_pos -1] == ' '){
        end_pos--;
      }
      line[end_pos] = ',';
//      cout << "[" << line << "]" << endl;
      int start_pos = 0;
      vector<int> authors;
      while (start_pos <= end_pos){
        int next_pos = line.find(".,", start_pos);
        string name = line.substr(start_pos, next_pos - start_pos + 1);
        start_pos = next_pos + 3;
        authors.push_back(get_id_by_name(name));
     //   cout << name << ":" << get_id_by_name(name) << endl;
      }
      adjacent.resize(names.size());
      
      for (size_t i = 0; i < authors.size(); i++){
        for (size_t j = 0; j < authors.size(); j++){
          if (i == j){
            continue;
          }
          int s = authors[i];
          int t = authors[j];
          adjacent[s].insert(t);
          adjacent[t].insert(s);
        }
      }
    }

    int size = names.size();
    vector<int> ernums(size, -1);
    int erid = get_id_by_name("Erdos, P.");
    ernums[erid] = 0;
    queue<int> Q;
    Q.push(erid);
    while (!Q.empty()){
      int s = Q.front();
      Q.pop();
      set<int>::iterator it;
      set<int> &link = adjacent[s]; 
      for (it = link.begin(); it != link.end(); it++){
        int t = *it;
        if (ernums[t] == -1){
          ernums[t] = ernums[s] + 1;
          Q.push(t);
        }
      }
    } 
#if 0
    for (int s = 0; s < size; s++){
      for (int t = 0; t < size; t++){
        printf("%8d ", d[s][t]);
      }
      printf("\n");
    }
#endif
    while (N--){
      string line;
      getline(cin, line);
     // cout << line << ":" << get_id_by_name(line) << endl;
      //cout << "Erdos, P. :" << get_id_by_name("Erdos, P.") << endl;
      size_t id = get_id_by_name(line);
      int ernum = id < ernums.size()? ernums[id] : -1; 
      cout << line << " ";
      if (ernum != -1){
        cout << ernum << endl;
      }else{
        cout << "infinity" << endl;
      }
    }
  }
}
        
        
