#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

const int MAXN = 5100;
const int MAXR = 10*1024*2;
int x1[MAXN], x2[MAXN], Y1[MAXN], y2[MAXN];
int counts[MAXR*4];
int covers[MAXR*4];
int N;
#define root 1,1,MAXR
#define father idx/2
#define lson  idx*2, l, (l+r)/2
#define rson idx*2+1, (l+r)/2+1, r

void change(int idx, int l, int r, int left, int right, int c)
{
  if (l > r){
    return;
  }
  if (left <= l && r <= right){
    counts[idx] += c;
  }
  else if (r < left || right < l){
    return;
  }
  else if (l != r){
    change(lson, left, right, c);
    change(rson, left, right, c);
  }
  if (counts[idx] > 0){
    covers[idx] = r-l+1;
  }
  else{
    covers[idx] = 0;
    if (idx*2 < MAXR*4) 
      covers[idx] += covers[idx*2]; 
    if (idx*2+1 < MAXR*4)
      covers[idx] += covers[idx*2+1];
  }
}
void init()
{
  memset(counts, 0, sizeof(counts));
  memset(covers, 0, sizeof(covers));
}
struct seg{
  int l,r;
  int c;
  int x; 
  seg(int _l, int _r, int _c, int _x):l(_l),r(_r),c(_c),x(_x){};
};

bool operator<(const struct seg &s1, const struct seg &s2)
{
  if (s1.x == s2.x){
    return s1.c > s2.c;
  }
  return s1.x<s2.x;
}

int Cal(vector<seg> &v)
{
  sort(v.begin(), v.end());
  init();
  int ans = 0;
  int cover = 0;
  for (int i = 0; i < v.size(); i++){
  //  printf("%d:%d(%d,%d),%d", i,v[i].x,v[i].l, v[i].r, v[i].c);
    change(root, v[i].l,v[i].r,v[i].c);
    ans += abs(covers[1] - cover);
    cover = covers[1];
   // printf("====>>%d\n", covers[1]);
  }
  return ans;
}
int main()
{
  scanf("%d", &N);
  for (int i = 0; i < N; i++){
    scanf("%d %d %d %d", x1+i, Y1+i, x2+i, y2+i);
    x1[i] += 10000;
    x2[i] += 10000;
    Y1[i] += 10000;
    y2[i] += 10000;
  }
  int ans = 0;
  vector<seg> v; 
  for (int i = 0; i < N; i++){
    v.push_back(seg(x1[i],x2[i]-1,1,Y1[i]));
    v.push_back(seg(x1[i],x2[i]-1,-1,y2[i]));
  }
  ans += Cal(v);
  v.clear();
  for (int i = 0; i < N; i++){
    v.push_back(seg(Y1[i], y2[i]-1, 1, x1[i]));
    v.push_back(seg(Y1[i], y2[i]-1, -1, x2[i]));
  }
  ans += Cal(v);
  printf("%d\n", ans);
}
