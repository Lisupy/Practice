#include <cstdio>
#include <cstring>
#include <cassert>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct Cube {
  char a[32];
  bool operator <(const Cube &c) const { return memcmp(a, c.a, 27) < 0; }
};

struct Figure {
  Cube *c;
  int n;
} figure[7];

char RX[]={7,8,9,16,17,18,25,26,27,4,5,6,13,14,15,22,23,24,1,2,3,10,11,12,19,20,21};
char RY[]={7,4,1,8,5,2,9,6,3,16,13,10,17,14,11,18,15,12,25,22,19,26,23,20,27,24,21};
char RZ[]={3,12,21,6,15,24,9,18,27,2,11,20,5,14,23,8,17,26,1,10,19,4,13,22,7,16,25};
char RA[64][32];

void rot(char *s, char *tab) {
  char t[32];
  for (int i = 0; i < 27; i++) t[tab[i]-1] = s[i];
  for (int i = 0; i < 27; i++) s[i] = t[i];
}

void make_rots() {
  char c[32];
  for (int i = 0; i < 27; i++) c[i] = i+1;

  int k = 0;
  for (int x = 0; x < 4; x++, rot(c, RX))
    for (int y = 0; y < 4; y++, rot(c, RY))
      for (int z = 0; z < 4; z++, rot(c, RZ)) {
        memcpy(RA[k++], c, 27);
        for (int i = 0; i < k-1; i++)
          if (memcmp(RA[i], RA[k-1], 27) == 0) { k--; break; }
      }
  assert(k == 24);
}

bool trans(char s[], int dx, int dy, int dz) {
  char t[27];
  for (int i = 0; i < 27; i++) t[i] = '.';

  for (int x = 0; x < 3; x++)
    for (int y = 0; y < 3; y++)
      for (int z = 0; z < 3; z++) {
        int c = s[9*y+3*z+x];
        if (c != '.') {
          int u = 9*(y+dy)+(3*z+dz)+(x+dx);
          if (u < 0 || u >= 27) return false;
          t[u] = c;
        }
      }

  for (int i = 0; i < 27; i++) s[i] = t[i];
  return true;
}

int main()
{
  make_rots();

  for (int fig = 'a'; fig <= 'g'; fig++) {
    vector<Cube> res;
    set<Cube> S;

    for (int r = 0; r < 24; r++)
      for (int dx = -2; dx <= 2; dx++)
        for (int dy = -2; dy <= 2; dy++)
          for (int dz = -2; dz <= 2; dz++) {
            Cube c;

            const char *pieces = "adcaccaacddgbfgffedggbfebee";
            for (int i = 0; i < 27; i++)
              c.a[i] = (pieces[i] == fig) ? fig : '.';

            rot(c.a, RA[r]);
            if (!trans(c.a, dx, dy, dz)) continue;

            if (S.count(c) == 0) {
              res.push_back(c);
              S.insert(c);
            }
          }

    Figure &F = figure[fig-'a'];
    F.n = res.size();
    F.c = new Cube[F.n];
    for (int i = 0; i < F.n; i++)
      F.c[i] = res[i];
  }

}
