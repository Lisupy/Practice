/* 
 * Algorithm:   simulation
 * Complexity:  O(N)
 * IndexBased:  0
 * Trick:       table-driven
 * LayOut:
 *  init_table();
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cctype>
using namespace std;


char key[256];

void init_table(){
  string lines[4] = {"`1234567890-=", "QWERTYUIOP[]\\", "ASDFGHJKL;'", "ZXCVBNM,./"};
  for (size_t i = 0; i < 4; i++){
    for (size_t j = 0; j + 1 < lines[i].size(); j++){
      key[(int)lines[i][j + 1]] = lines[i][j];
    }
  }
  key[' '] = ' ';
  key['\n'] = '\n';
};

int main(){
  init_table();
  char ch;
  while (scanf("%c", &ch) != EOF){
  //  cout <<"[" << ch << "]";
    cout << key[(int)ch];
  }
}
