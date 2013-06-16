/*
 * Algorithm:   BigNumber
 * Complexity:  O(N)
 * Trick:
 * IndexBased:  0
 * LayOut:
 *  bignum_add
 *  str_to_bignum
 */


#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;


void bignum_display(vector<int> a){
  reverse(a.begin(), a.end());
  for (size_t i = 0; i < a.size(); i++){
    cout << a[i] << " ";
  }
  cout << endl;
}

vector<int> str_to_bignum(string s){
  vector<int> a(s.size());
  for (size_t i = 0; i < s.size(); i++){
    a[i] = (s[i] - '0');
  }
  reverse(a.begin(), a.end());
  while (a.size() > 0 && a.back() == 0){
    a.erase(a.end() - 1);
  }
  return a;
}

vector<int> bignum_add(vector<int> a, vector<int> b, int &carry_cnt){
  carry_cnt = 0;
  vector<int> c(max(a.size(), b.size()));
  int carry = 0;
  for (size_t i = 0; i < max(a.size(), b.size()); i++){
    int da = i < a.size() ? a[i] : 0;
    int db = i < b.size() ? b[i] : 0;
    int dc = da + db + carry;
    carry = 0;
    if (dc >= 10){
      carry = 1;
      dc -= 10;
      carry_cnt++;
    }
    c[i] = dc;
  }
  if (carry != 0){
    c.push_back(carry);
  }
  return c;
}


int main(){
 // int a, b
  string sa, sb;
  while (cin >> sa >> sb && !(sa == sb && sa == "0")){
//  while (cin >> a >> b && (a != 0 || b != 0){
    vector<int> bg_a = str_to_bignum(sa);
    vector<int> bg_b = str_to_bignum(sb);
   // bignum_display(bg_a);
    //bignum_display(bg_b);
    if (bg_a.size() == 0 && bg_b.size() == 0){
      break;
    }
    int carry_cnt = 0;
    vector<int> bg_c = bignum_add(bg_a, bg_b, carry_cnt);
    if (carry_cnt == 0){
      cout << "No carry operation." << endl;
    }else if (carry_cnt == 1){
      cout << "1 carry operation." << endl;
    }else{
      cout << carry_cnt << " carry operations." << endl;
    }
  }
}

