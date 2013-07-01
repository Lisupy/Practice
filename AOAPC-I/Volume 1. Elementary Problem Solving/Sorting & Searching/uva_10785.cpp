#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int N;
map<int, string> cache;


string allVowels;
string allConsonant;

string gen(int n){
  if (cache[n] != ""){
    return cache[n];
  }
  string s(n, ' ');
  size_t posVowel = 0;
  size_t posConst = 0;
  string Vowels = allVowels.substr(0, (n + 1) / 2);
  string Consonants = allConsonant.substr(0, n / 2);
  sort(Vowels.begin(), Vowels.end());
  sort(Consonants.begin(), Consonants.end());
  for (int i = 0; i < n; i++){
    if (i % 2 == 0){
      s[i] = Vowels[posVowel++];
    }else{
      s[i] = Consonants[posConst++];
    }
  }
  return cache[n] = s;
}
const char* vowels = "AUEOI";
const char* consonants = "JSBKTCLDMVNWFXGPYHQZR";
int main(){
  for (int i = 0; vowels[i] ; i++){
    allVowels.append(21, vowels[i]);
  }
  for (int i = 0; consonants[i] ; i++){
    allConsonant.append(5, consonants[i]);
  }
  cin >> N;
  for (int ni = 1; ni <= N; ni++){
    int n;
    cin >> n;
    cout << "Case " << ni << ": " << gen(n) << endl;
  }
}
    
