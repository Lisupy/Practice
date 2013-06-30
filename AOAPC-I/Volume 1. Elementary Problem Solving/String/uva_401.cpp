#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



bool is_palindrome(string s){
  string t(s.rbegin(), s.rend());
  return s == t;
}

char mirror_tbl[][2] = 
{
  {'A', 'A'},   
  {'B', ' '}, 
  {'C', ' '}, 
  {'D', ' '}, 
  {'E', '3'},   
  {'F', ' '}, 
  {'G', ' '}, 
  {'H', 'H'},   
  {'I', 'I'},   
  {'J', 'L'},   
  {'K', ' '}, 
  {'L', 'J'},   
  {'M', 'M'},
  {'N', ' '},
  {'O', 'O'},
  {'P', ' '},
  {'Q', ' '},
  {'R', ' '},
  {'S', '2'},
  {'T', 'T'},
  {'U', 'U'},
  {'V', 'V'},
  {'W', 'W'},
  {'X', 'X'},
  {'Y', 'Y'},
  {'Z', '5'},
  {'1', '1'},
  {'2', 'S'},
  {'3', 'E'},
  {'4', ' '},
  {'5', 'Z'},
  {'6', ' '},
  {'7', ' '},
  {'8', '8'},
  {'9', ' '},
};

char mirror_char(char ch){
  for (size_t i = 0; i < sizeof(mirror_tbl) / sizeof(mirror_tbl[0]); i++){
    if (mirror_tbl[i][0] == ch){
      return mirror_tbl[i][1];
    }
  }
  return ' ';
}

bool is_mirrored(string s){
  string t(s.rbegin(), s.rend());
  for (size_t i = 0; i < s.size(); i++){
    if (mirror_char(s[i]) !=  t[i]){
      return false;
    }
  }
  return true;
}

int main(){
  string s;
  while (cin >> s){
    bool s_is_mirrored = is_mirrored(s);
    bool s_is_palidorme = is_palindrome(s);
    string ans = "";
    if (!s_is_mirrored && !s_is_palidorme){
      ans = " -- is not a palindrome.";
    }
    if (!s_is_mirrored && s_is_palidorme){
      ans = " -- is a regular palindrome.";
    }
    if (s_is_mirrored && !s_is_palidorme){
      ans = " -- is a mirrored string.";
    }
    if (s_is_mirrored && s_is_palidorme){
      ans = " -- is a mirrored palindrome.";
    }
    cout << s << ans << endl;
    cout << endl;
  }
}

