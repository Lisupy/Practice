/*
 * Algorithm:   topological sort
 * Complexity:  O(N * M)
 * IndexBased:  0
 * Trick:
 *  input();
 *  reset();
 *  topological_sort();
 *  output();
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

const int MAXN = 1024;
const int MAXM = MAXN * 6;

vector<int> links[MAXM];
int in_degree[MAXM];
int longest_path[MAXM];
int Prev[MAXM];

int N;
int M;
int color[MAXN][6];
void rebuild_graph(){
  for (int i = 0; i < MAXM; i++){
    links[i].clear();
  }
  fill(longest_path, longest_path + MAXM, 0);
  fill(Prev, Prev + MAXM, -1);
  for (int i = 0; i < N; i++){
    const int *a = color[i];
    for (int j = i + 1; j < N; j++){
      const int *b = color[j];
      for (int ki = 0; ki < 6; ki++){
        for (int kj = 0; kj < 6; kj++){
          int opp = (ki / 2) * 2 + (1 - ki % 2);
         // cout << ki << "<< " << opp << endl;
          if (a[opp] == b[kj]){
            links[i * 6 + ki].push_back(j * 6 + kj);
          }
        }
      }
    }
  }
}

void topological_sort(){
  fill(in_degree, in_degree + MAXM, 0);
  for (int s = 0; s < M; s++){
    vector<int> &link = links[s];
    for (size_t j = 0; j < link.size(); j++){
      int t = link[j];
      in_degree[t]++;
    }
  }
  queue<int> Q;
  for (int s = 0; s < M; s++){
    if (in_degree[s] == 0){
      Q.push(s);
    }
  }
  while (!Q.empty()){
    int s = Q.front();
    Q.pop();

    int sl = longest_path[s];
    vector<int> &link = links[s];
    for (size_t i = 0; i < link.size(); i++){
      int t = link[i];
      if (longest_path[t] < sl + 1){
        longest_path[t] = sl + 1;
        Prev[t] = s;
      }
      in_degree[t]--;
      if (in_degree[t] == 0){
        Q.push(t);
      }
    }
  }
}
const char* face_strs[] = {
  "front",
  "back",
  "left",
  "right",
  "top",
  "bottom",
};
void output(){
  int longest_pos = max_element(longest_path, longest_path + M) - longest_path;
  int longest = longest_path[longest_pos];
  cout << longest + 1 << endl;
  vector<int> path;
  int pos = longest_pos;
  while (pos != -1){
    path.push_back(pos);
    pos = Prev[pos];
  }
  reverse(path.begin(), path.end());
 // for (int i = 0; i < M; i++){
  //  cout << i << ":" << longest_path[i] << ", " << Prev[i] << endl;
  //}
  for (size_t i = 0; i < path.size(); i++){
    int t = path[i];
 //   cout << t << endl;
    int cube = t / 6 + 1;
    int face = t % 6;
//    cout << cube << ", " << face << " => " <<color[cube - 1][face] << endl;
    const char* face_str = face_strs[face];
    cout << cube << " " << face_str << endl;
  }
}


int main(){
  int CaseNum = 0;

  while (cin >> N && N){
    M = N * 6;
    for (int i = 0; i < N; i++){
      for (int j = 0; j < 6; j++){
        cin >> color[i][j];
      }
    }
    rebuild_graph();
    topological_sort();
    if (CaseNum){
      cout << endl;
    }
    cout << "Case #" << ++CaseNum << endl;
    output();
  }
}



