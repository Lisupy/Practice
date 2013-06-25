/*
 * dp[i][j] = dp[i - 1][j] + (i == j ? dp[i - 1][j - 1] : 0);
 * dp[0][0] = 1
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

const int BASE = 1000*10;

vector<int> bignum_add(vector<int> a, vector<int> b){
  vector<int> c;
  int carry = 0;
  for (size_t i = 0; i < max(a.size(), b.size()); i++){
    int da = i < a.size() ? a[i] : 0;
    int db = i < b.size() ? b[i] : 0;
    int dc = da + db + carry;
    carry = dc / BASE;
    c.push_back(dc % BASE);
  }
  if (carry){
    c.push_back(carry);
  }
  return c;
}

string str_from_int(int n, int e){
  char buf[24];
  sprintf(buf, "%0*d", e, n);
  return buf;
}

string str_from_bignum(vector<int> a){
  if (a.size() == 0){
    return "0";
  }
  string s;
  reverse(a.begin(), a.end());
  s += str_from_int(a[0], 0);
  for (size_t i = 1; i < a.size(); i++){
    s += str_from_int(a[i], 4);
  }
  return s;
}
vector<int> dp[1024 * 10][128];

vector<int> distinct_subsequences(string Z, string X){
  int lz = Z.size();
  int lx = X.size();
  for (int i = 0; i <= lz; i++){
    for (int j = 0; j <= lx; j++){
      dp[i][j].clear();
    }
  }
  dp[0][0].push_back(1);
  for (int i = 0; i <= lz; i++){
    for(int j = 0; j <= lx; j++){
      if (i - 1 >= 0){
      //  dp[i][j] += dp[i - 1][j];
        dp[i][j] = bignum_add(dp[i][j], dp[i - 1][j]);
      }
      if (i - 1 >= 0 && j - 1 >= 0){
        if (Z[i - 1] == X[j - 1]){
         // dp[i][j] += dp[i - 1][j - 1];
          dp[i][j] = bignum_add(dp[i][j], dp[i - 1][j - 1]);
        }
      }
   //   cout << dp[i][j] << " ";
    }
    //cout << endl;
  }

  return dp[lz][lx];
}

int main(){
  int N;
  cin >> N;
  while (N--){
    string Z, X;
    cin >> Z >> X;
    vector<int> res = distinct_subsequences(Z, X);
    cout << str_from_bignum(res) << endl;
  }
}
