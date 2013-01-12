#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int MAXU = 16;

int number_of_scenarios;


void output_slice(int depth, int u){
  for (int line = -u; line <= u; line++){
    for (int row = -u; row <= u; row++){
      int dis = abs(line)+abs(row)+abs(depth);
      if (dis > u)
        printf(".");
      else
        printf("%d", dis);
    }
    printf("\n");
  }
}
void output_scenario(int u){
  int slice = 0;
  for (int depth = -u; depth <= u; depth++){
    printf("slice #%d:\n", ++slice);
    output_slice(depth, u);
  }
}
int main(){
  scanf("%d", &number_of_scenarios);
  for(int sce = 1; sce <= number_of_scenarios; sce++){
    int u;
    scanf("%d", &u);
    printf("Scenario #%d:\n", sce);
    output_scenario(u);
    printf("\n");
  }

}
