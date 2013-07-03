#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;


int main(){
  string s;
  while (cin >> s && s != "0:00"){
    size_t pos = s.find(":");
    double H = atoi(s.substr(0, pos).data());
    double M = atoi(s.substr(pos + 1).data());
    H = (int)H % 12;
    double ans1 = (H * 60 + M) / 720  * 360;
    double ans2 = M / 60 * 360;
  //  printf("%.03lf %.03lf\n", ans1, ans2);
    double ans = fabs(ans1 - ans2);
    ans = min(ans, 360 - ans);
    printf("%.03lf\n", ans);
  }
}


