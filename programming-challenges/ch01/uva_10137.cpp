//Algorithm:  sum,
//Complexity: N*lgN
//IndexBased: 0
//Trick:      


#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<numeric>
using namespace std;



const int MAXN = 1024;

vector<double> costs;
double sum;
double mean;
double more_than_mean;
double less_than_mean;

int n;


double round_to_one_cent(double d){
  char tmp[16];
  sprintf(tmp, "%.2lf", d);
  sscanf(tmp, "%lf", &d);
  return d;
}

int main(){
  while (scanf("%d", &n) && n){
    costs.clear();
    for (int i = 0; i < n; i++){
      double cost;
      scanf("%lf", &cost);
      costs.push_back(cost);
    }

    sum = accumulate(costs.begin(), costs.end(), 0.0);
    mean = round_to_one_cent(sum / n);

    more_than_mean = 0;
    less_than_mean = 0;
    for (size_t i = 0; i < costs.size(); i++){
      double cost = costs[i];
      if (cost > mean){
        more_than_mean += cost - mean;
      }else if (cost < mean){
        less_than_mean += mean - cost;
      }
    }

    double ans = min(more_than_mean, less_than_mean);
    printf("$%.02lf\n", ans);
  }
}


