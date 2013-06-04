/*
 * Algorithm:   simulation
 * Complexity:
 * Trick:
 * Complexity:
 * LayOut:  table-driven
 *  is_XXX        return 0 or value
 *  compare_XXX
 */


#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<numeric>
#include<cassert>
#include<sstream>
using namespace std;



int value_id(string card){
  char c = card[0];
  if (isdigit(c)){
    return c - '0';
  }
  switch (c){
  case 'T':return 10;
  case 'J':return 11;
  case 'Q':return 12;
  case 'K':return 13;
  case 'A':return 14;
  }
  assert(0);
}

bool suit_eq(string a, string b){
  return a[1] == b[1];
}

bool value_eq(string a, string b){
  return a[0] == b[0];
}

bool more_one(string a, string b){
  return value_id(a) - 1 == value_id(b);
}

int is_straight_flush(vector<string> cards){
  for (size_t i = 1; i < cards.size(); i++){
    if (!suit_eq(cards[i], cards[i - 1])){
      return 0;
    }
  }
  for (size_t i = 1; i < cards.size(); i++){
    if (!more_one(cards[i], cards[i - 1])){
      return 0;
    }
  }
  return value_id(cards[4]);
}

int is_four_of_a_kind(vector<string> cards){
  if (value_eq(cards[0], cards[3])){
    return value_id(cards[0]);
  }
  if (value_eq(cards[1], cards[4])){
    return value_id(cards[1]);
  }
  return 0;
}

int is_full_house(vector<string> cards){
  if (value_eq(cards[0], cards[1]) && value_eq(cards[2], cards[4])){
    return value_id(cards[2]);
  }
  if (value_eq(cards[0], cards[2]) && value_eq(cards[3], cards[4])){
    return value_id(cards[0]);
  }
  return 0;
}

int get_hand_value(vector<string> cards){
  int res = 0;
  reverse(cards.begin(), cards.end());
  for (size_t i = 0; i < cards.size(); i++){
    res = res * 16 + value_id(cards[i]);
  }
  return res;
}

int is_flush(vector<string> cards){
  for (size_t i = 1; i < cards.size(); i++){
    if (!suit_eq(cards[i], cards[i - 1])){
      return 0;
    }
  }
  return get_hand_value(cards);
}

int is_straight(vector<string> cards){
  for (size_t i = 1; i < cards.size(); i++){
    if(!more_one(cards[i], cards[i - 1])){
      return 0;
    }
  }
  return value_id(cards[4]);
}

int is_three_of_a_kind(vector<string> cards){
  for (size_t i = 2; i < cards.size(); i++){
    if (value_eq(cards[i], cards[i - 2])){
      return value_id(cards[i]);
    }
  }
  return 0;
}

int get_two_pairs_value(vector<string> pairs, vector<string> cards){
  int a = value_id(pairs[0]);
  int b = value_id(pairs[1]);
  if (a < b){
    swap(a, b);
  }
  for (size_t i = 0; i < cards.size(); i++){
    int c = value_id(cards[i]);
    if (a != c && b != c){
      return a * 16 * 16 + b * 16 + c;
    }
  }
  assert(0); 
}

int is_two_pairs(vector<string> cards){
  vector<string> pairs;
  for (size_t i = 1; i < cards.size(); i++){
    if (value_eq(cards[i], cards[i - 1])){
      pairs.push_back(cards[i]);
    }
  }
  if (pairs.size() == 2){
    return get_two_pairs_value(pairs, cards);
  }
  return 0;
}

int get_pair_value(vector<string> pairs, vector<string> cards){
  return value_id(pairs[0]) * 16 * 16 * 16 * 16 * 16 * 16 + get_hand_value(cards);
}

int is_pair(vector<string> cards){
  vector<string> pairs;
  for (size_t i = 1; i < cards.size(); i++){
    if (value_eq(cards[i], cards[i - 1])){
      pairs.push_back(cards[i]);
    }
  }
  if (pairs.size() == 1){
    return get_pair_value(pairs, cards);
  }
  return 0;
}

int is_high_card(vector<string> cards){
  return get_hand_value(cards);
}

struct Check{
  const char* name;
  int (*cmp)(vector<string> cards);
};

Check checks[] = {
  {"Straight Flush",  is_straight_flush},
  {"Four of a kind",  is_four_of_a_kind},
  {"Full House",      is_full_house}, 
  {"Flush",           is_flush},
  {"Straight",        is_straight},
  {"Three of a kine", is_three_of_a_kind},
  {"Two Pairs",       is_two_pairs},
  {"Pair",            is_pair},
  {"High Card",       is_high_card},
};

bool card_cmp(const string &a, const string &b){
  return value_id(a) < value_id(b);
}

string process(vector<string> black, vector<string> white){
  sort(black.begin(), black.end(), card_cmp);
  sort(white.begin(), white.end(), card_cmp);
  for (size_t i = 0; i < sizeof(checks)/sizeof(Check); i++){
    Check& check = checks[i];
    int black_value = check.cmp(black);
    int white_value = check.cmp(white);
    if (black_value > white_value){
      return "Black wins.";
    }else if (black_value < white_value){
      return "White wins.";
    }else if (black_value != 0){
      return "Tie.";
    }
  }
  return "Tie.";
  assert(0);
}

int input(vector<string> &black, vector<string> &white){
  black.resize(5);
  white.resize(5);

  string line;
  getline(cin, line);
  if (!cin || line.length() == 0){
    return 0;
  }

  istringstream iss(line);
  for (size_t i = 0; i < 5; i++){
    iss >> black[i];
  }
  for (size_t i = 0; i < 5; i++){
    iss >> white[i];
  }

  return 1;
}

int main(){
  vector<string> black;
  vector<string> white;
  while (input(black, white)){
    cout << process(black, white) << endl;
  }
}









