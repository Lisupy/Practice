#include<string>
#include<iostream>
using namespace std;

string string_remove(string s, char c){
  string t;
  for (size_t i = 0; i < s.size(); i++){
    if (s[i] != c){
      t += s[i];
    }
  }
  return t;
}

string check(string puzzle, string guess){
  int wrong_cnt = 0;
  string used;
  for (size_t i = 0; i < guess.size(); i++){
    char ch = guess[i];
    if (used.find(ch) != string::npos){
      continue;
    }
    if (puzzle.find(ch) == string::npos){
      wrong_cnt++;
      if (wrong_cnt >= 7){
        return "You lose.";
      }
    }else{
      puzzle = string_remove(puzzle, ch);
      if (puzzle == ""){
        return "You win.";
      }
    }
  }
  return "You chickened out.";
}

int main(){
  int Round;
  string puzzle, guess;
  while (cin >> Round && Round != -1){
    cin >> puzzle >> guess;
    cout << "Round " << Round << endl;
    cout << check(puzzle, guess) << endl;
  }
}
