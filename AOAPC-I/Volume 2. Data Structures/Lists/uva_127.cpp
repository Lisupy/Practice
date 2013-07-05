#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<list>
#include<stack>
using namespace std;


static inline bool match(const string &left, const string &right){
  return left[0] == right[0] || left[1] == right[1];
}

list<stack<string> > piles;
typedef list<stack<string> >::iterator IT;
int input(){
  piles.clear();
  string s;
  for (int i = 0; i < 52; i++){
    cin >> s;
    if (s[0] == '#'){
      return 0;
    }
    stack<string> ss;
    ss.push(s);
    piles.push_back(ss);
  }
  return 1;
}

bool check_and_move(IT it, int step){
  IT it2 = it;
  while (step--){
    if (it2 != piles.begin()){
      it2--;
    }else{
      return false;
    }
  }
  if (match(it->top(), it2->top())){
    it2->push(it->top());
    it->pop();
    if (it->empty()){
      piles.erase(it);
    }
    return true;
  }else{
    return false;
  }
}


void process(){
  while (true){
    bool found = false;
    for (IT it = piles.begin(); it != piles.end(); it++){
      if (check_and_move(it, 3) || check_and_move(it, 1)){
        found = true;
        break;
      }
    }
    if (!found){
      break;
    }
  };
}

void output(){
  if (piles.size() > 1){
    printf("%lu piles remaining:", piles.size());
  }else{
    printf("%lu pile remaining:", piles.size());
  }
  for (IT it = piles.begin(); it != piles.end(); it++){
    printf(" %lu", it->size());
  }
  printf("\n");
}

int main(){
  while (input()){
    process();
    output();
  }
}

