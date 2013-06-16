#include<iostream>
#include<cstdio>
using namespace std;



int main(){
  int m, n;
  while (cin >> m >> n && (m != 1 || n != 1)){
    int m_l = 0, n_l = 1;
    int m_r = 1, n_r = 0;
    while (m_l * n_r < m_r * n_l){
     // cout << m_l << " " << n_l << ", " << m_r << " " << n_r << endl;
      int m_mid = m_l + m_r;
      int n_mid = n_l + n_r;
      //cout << m_mid << " " << n_mid << endl;
      if (m_mid * n == m * n_mid){
        break;
      }else if (m_mid * n <  n_mid * m){
        cout << "R";
        m_l = m_mid, n_l = n_mid;
      }else{
        cout << "L";
        m_r = m_mid, n_r = n_mid;
      }
      //getchar();
    }
    cout << endl;
    //cout << "Done!" << endl;
  }
}
    

    

