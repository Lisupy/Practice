#include<string>
#include<cstdio>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cctype>
using namespace std;

const int MAXN = 10*1024;

int l[MAXN];
int r[MAXN];
int f[MAXN];
char e[MAXN];
int c[MAXN];
int idx[MAXN];
int o[MAXN];
int d[MAXN];
int len; 
vector<string> vs;
void get_depth(int root,int depth){
  //printf("%d %d\n", root, depth);
  if (vs.size() == depth)
    vs.push_back("");
  vs[depth]+=e[root];
  //d[root] = depth;
  if (islower(e[root]))
    return;
  get_depth(l[root],depth+1);
  get_depth(r[root],depth+1);
}
inline bool cmp(int a, int b){
  if (d[a] > d[b]) return true;
  if (d[a] < d[b]) return false;
  return a>b;
}

int Stack[MAXN];
int Top = 0;
int main(){
  int T;
  scanf("%d", &T);
  while(T--){
    scanf("%s", e);
   // gets(e);
    len = strlen(e);
    //stack<int> S;
    vs = vector<string>();
    for (int i = 0; i < len; i++){
      c[i] = 0;
      if (isupper(e[i])){
        l[i] = Stack[--Top];
        r[i] = Stack[--Top];
    //    l[i] = S.top(); S.pop();
     //   r[i] = S.top(); S.pop();
        f[l[i]] = f[r[i]] = i; 
      //  c[i] = l[i]+r[i];
      }
      //c[i]++;
      //S.push(i);
      Stack[Top++] = i; 
    }
    //int root = S.top(); S.pop();
    int root=Stack[--Top];
    get_depth(root,0);
    //for (int i = 0; i < len; i++)
    //  idx[i] = i;
    //sort(idx, idx+len, cmp);
   // for (int i = 0; i < len; i++){
   //   printf("%d", d[i]);
   // }
   // printf("\n");
    for (int i = vs.size()-1; i >=0 ; i--){
      printf("%s", vs[i].c_str());
    }
    printf("\n");
  }
}
