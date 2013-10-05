// File Name: 11019.cpp
// Author: zlbing
// Created Time: 2013/3/23 14:37:07

#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
using namespace std;
#define CL(x,v); memset(x,v,sizeof(x));
#define INF 0x3f3f3f3f
#define LL long long
#define REP(i,r,n) for(int i=r;i<=n;i++)
#define RREP(i,n,r) for(int i=n;i>=r;i--)
const int SIGMA_SIZE = 26;
const int MAXNODE = 111000;
const int MAXS = 150 + 10;

map<string,int> ms;
//ms是为了满足特殊要求,比如模板串相同时
struct ACautomata {
  int ch[MAXNODE][SIGMA_SIZE];
  int f[MAXNODE];    // fail函数
  int val[MAXNODE];  // 每个字符串的结尾结点都有一个非0的val
  int last[MAXNODE]; // 输出链表的下一个结点
  int next[MAXS];
  int sz;
  int d[1005][1005];
  void init() {
    sz = 1;
    memset(ch[0], 0, sizeof(ch[0]));
    ms.clear();
    memset(d,0,sizeof(d));
    memset(next,0,sizeof(next));
  }

  // 字符c的编号
  int idx(char c) {
    return c-'a';
  }

  // 插入字符串。v必须非0
  void insert(char *s, int v) {
    int u = 0, n = strlen(s);
    for(int i = 0; i < n; i++) {
      int c = idx(s[i]);
      if(!ch[u][c]) {
        memset(ch[sz], 0, sizeof(ch[sz]));
        val[sz] = 0;
        ch[u][c] = sz++;
      }
      u = ch[u][c];
    }
    if(val[u])
    {
        next[v]=val[u];
    }
    val[u] = v;
    ms[string(s)] = v;
  }

  // 递归打印匹配文本串str[i]结尾的后缀,以结点j结尾的所有字符串
  void print(int i,int j,int x) {
    if(j) {
        if(x-val[j]+1>0)
        d[x-val[j]+1][i]++;
        int t=val[j];
        while(next[t])
        {
            t=next[t];
            if(x-t+1>0)
                d[x-t+1][i]++;
        }
      print(i,last[j],x);
    }
  }

  // 在T中找模板
  int find(char* T,int x) {
    int n = strlen(T);
    int j = 0; // 当前结点编号，初始为根结点
    for(int i = 0; i < n; i++) { // 文本串当前指针
      int c = idx(T[i]);
      j = ch[j][c];
      if(val[j]) print(i,j,x);
      else if(last[j]) print(i,last[j],x); // 找到了！
    }
  }

  // 计算fail函数
  void getFail() {
    queue<int> q;
    f[0] = 0;
    // 初始化队列
    for(int c = 0; c < SIGMA_SIZE; c++) {
      int u = ch[0][c];
      if(u) { f[u] = 0; q.push(u); last[u] = 0; }
    }
    // 按BFS顺序计算fail
    while(!q.empty()) {
      int r = q.front(); q.pop();
      for(int c = 0; c < SIGMA_SIZE; c++) {
        int u = ch[r][c];
        if(!u) {
            ch[r][c]=ch[f[r]][c];
            continue;
        }
        q.push(u);
        int v = f[r];
        while(v && !ch[v][c]) v = f[v];
        f[u] = ch[v][c];
        last[u] = val[f[u]] ? f[u] : last[f[u]];
      }
    }
  }

};
ACautomata solver;
char str[1005][1005];
char str1[105][105];
int main(){
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,M,X,Y;
        scanf("%d%d",&N,&M);
        REP(i,1,N)
            scanf("%s",str[i]);
        scanf("%d%d",&X,&Y);
        REP(i,1,X)
            scanf("%s",str1[i]);
        solver.init();
        REP(i,1,X){
            solver.insert(str1[i],i);
        }
        solver.getFail();
        REP(i,1,N)
        {
            solver.find(str[i],i);
        }
        int ans=0;
        REP(i,1,N)
            REP(j,1,M)
            if(solver.d[i][j]==X)
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
