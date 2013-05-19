// * 数组偏移   1开始
// * LCS(i, j) = MAX{  LCS(i-1, j),
//                     LCS(i, j-1),
//                     LCS(i-1, j-1) + 1, X[i] == Y[j]
//                  }


#include<vector>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;


const int MAXN = 256;

char X[MAXN];
char Y[MAXN];
int LX;
int LY;
int LCS[MAXN][MAXN];

void reset(){
  fill(&LCS[0][0], &LCS[MAXN-1][MAXN-1], 0);
}

int main(){
  while (scanf("%s %s", X + 1, Y + 1) != EOF){
    reset();
    LX = strlen(X + 1);
    LY = strlen(Y + 1);
    for (int xi = 1; xi <= LX; xi++){
      for (int yi = 1; yi <= LY; yi++){
        if (X[xi] == Y[yi]){
          LCS[xi][yi] = LCS[xi - 1][yi - 1] + 1;
        }else{
          LCS[xi][yi] = max(LCS[xi - 1][yi], LCS[xi][yi - 1]);
        }
      }
    }
    printf("%d\n", LCS[LX][LY]);
  }
}
