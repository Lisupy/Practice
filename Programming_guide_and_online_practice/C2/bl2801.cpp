#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 16;
const int MAXM = 16;
const int MAXP = 128;

int M,N;
int P;

int a[256];

int main(){
  scanf("%d%d%d", &N, &M, &P);
  
  char buf[128];
  for (int i = 0; i < N; i++){
    scanf("%s", buf);
    for (int j = 0; j < M; j++){
      a[buf[j]]++;
    }
  }

  for (int i = 0; i < P; i++){
    string word;
    cin >> word;
    for (int j = 0; j < word.length(); j++){
      a[word[j]]--;
    }
  }

  string s;
  for (int i = 0; i < 256; i++){
    s.append(a[i], char(i));
  }

  sort(s.begin(), s.end());

  cout<<s<<endl;
}
