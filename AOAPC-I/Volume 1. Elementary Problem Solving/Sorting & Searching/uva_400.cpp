#include<iostream>
#include<algorithm>
#include<cstdio>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;


int N;
vector<string> files;



int main(){
  while (cin >> N){
    files.resize(N);
    size_t longest = 0;
    for (int i = 0; i < N; i++){
      cin >> files[i];
      longest = max(longest, files[i].size());
    }
    sort(files.begin(), files.end());


    cout << string(60, '-') << endl;

//    cout << longest << endl;
    int numPerline = floor(62.0 / (longest + 2));
 //   cout << numPerline << endl;
    int lineNum = ceil(double(files.size()) / numPerline);
  //  cout << lineNum << endl;

    vector<vector<string> > lines(lineNum);
    for (size_t i = 0; i < files.size(); i++){
      lines[i % lineNum].push_back(files[i]);
    }

   // cout << "preprocess done!" << endl;
    for (size_t i = 0; i < lines.size(); i++){
      vector<string> &line = lines[i];
      for (size_t j = 0; j < line.size(); j++){
        if (j != 0){
          cout << "  ";
        }
        cout << line[j];
        cout << string(longest - line[j].size(), ' ');
      }
      cout << endl;
    }
  }
}


    

