/*
 * Algorithm:   simulation
 * Complexity:  
 * IndexBased:  1
 * Trick:
 * Layout:
 *  n
 *  vector<vector<int> > shuffles;
 *  vector<int> cards;
 *  vector<int> shuffle_execute(vector<int> shuffle, vector<int> cards)
 *  string card_get_by_rank();
 *  init_cards(vector<int> cards);
 */


#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;


int n;
vector<vector<int> > shuffles;
vector<int> onhand;

vector<int> shuffle_execute(vector<int> shuffle, vector<int> cards){
  //cout << "shuffle_execute" << endl;
  vector<int> new_cards(53);
  for (size_t j = 1; j < cards.size(); j++){
    int i = shuffle[j];
    new_cards[j] = cards[i];
  }
  return new_cards;
}

const char* value_table[] = {
  "2",
  "3",
  "4",
  "5",
  "6",
  "7",
  "8",
  "9",
  "10",
  "Jack",
  "Queen",
  "King",
  "Ace",
};

const char* suit_table[] = {
  "Clubs",
  "Diamonds",
  "Hearts",
  "Spades",
};

string suit_str(int suit){
  return suit_table[suit];
}

string value_str(int value){
  return value_table[value];
}
string card_get_by_rank(int rank){
  string s;
  int value = (rank - 1) % 13;
  s += value_str(value);
  s += " of ";
  int suit = (rank -1) / 13;
  s += suit_str(suit);
  return s;
}


void reset(){
  shuffles.clear();
  onhand.resize(53);
  for (size_t i = 0; i < onhand.size(); i++){
    onhand[i] = i;
  }
}


int main(){
  int numCase;
  cin >> numCase;
  while (numCase--){
    reset();
    cin >> n;
    shuffles.resize(n + 1);
    for (int i = 1; i <= n; i++){
      shuffles[i].resize(53);
      for (int j = 1; j <= 52; j++){
        cin >> shuffles[i][j];
      }
    }
    cin.ignore();
    string line;
    while (getline(cin, line) && line.size() > 0){
      //cout << "===[" << line << "]" << endl;
      istringstream iss(line);
      int k;
      iss >> k;
      //cout << "[" << k << "]" << endl;
      onhand = shuffle_execute(shuffles[k], onhand);
    }

    for (size_t i = 1; i <= 52; i++){
      cout << card_get_by_rank(onhand[i]) << endl;
    }
    if (numCase){
      cout << endl;
    }
  }
}






