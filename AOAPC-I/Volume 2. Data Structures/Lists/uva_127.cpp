#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<list>
using namespace std;


bool match(string left, string right){
  return left[0] == right[0] || left[1] == right[1];
}

vector<string> cards;
vector<int> nums;
int input(){
  cards.clear();
  nums.clear();
  string s;
  for (int i = 0; i < 52; i++){
    cin >> s;
    if (s == "#"){
      return 0;
    }
    cards.push_back(s);
    nums.push_back(1);
  }
  return 1;
}

void combine(int left, int right){
  cards[left] = cards[right];
  nums[left] += nums[right];
  cards.erase(cards.begin() + right);
  nums.erase(nums.begin() + right);
}

void debug(){
  for (size_t i = 0; i < cards.size(); i++){
    cout << cards[i] << "(" << nums[i] << ") " ;
  }
  cout << endl;
}

void process(){
  while (true){
    bool found = false;
    for (size_t i = 0; i < cards.size() && !found; i++){
      size_t js[2] = {i - 3, i - 1};
      for (int k = 0; k < 2 && !found; k++){
        size_t j = js[k];
        if (j < cards.size() && match(cards[i], cards[j])){
          combine(j, i);
          found = true;
          break;
        }
      }
    }
    if (!found){
      break;
    }
  };
}

void output(){
  if (cards.size() > 1){
    printf("%lu piles remaining:", nums.size());
  }else{
    printf("%lu pile remaining:", nums.size());
  }
  for (size_t i = 0; i < nums.size(); i++){
    printf(" %d", nums[i]);
  }
  printf("\n");
}

int main(){
  while (input()){
    process();
    output();
  }
}

