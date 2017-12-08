#include<string>
#include<functional>
#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<tuple>
#include<limits>
#include<cstring>
using namespace std;
int N, M;;
int d[127][127];
char grid[127][127];
int dist[127][127];
bool visited[127][127];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) {
    grid[0][i] = '1';
    grid[M + 1][i] = '1';
  }
  for (int i = 1; i <= M; i++) {
    scanf("%s", grid[i] + 1);
    grid[i][0] = '1';
    grid[i][N + 1] = '1';
  }
  memset(dist, 0x3f, sizeof(dist));
  dist[1][1] = 0;
  visited[1][1] = true;
  queue<pair<int, int>> Q;
  Q.push({1, 1});
  while (Q.size()) {
    auto s = Q.front();
    Q.pop();
    int x = s.first, y = s.second;
    // cout << "pop " << x << " " << y << endl;
    for (int i = 0; i < 4; i++) {
      int nx = x, ny = y;
      while (grid[nx + dx[i]][ny + dy[i]] != '1') {
        nx += dx[i], ny += dy[i];
        if (grid[nx][ny] == '2') {
          cout << dist[x][y] + 1 << endl;
          return 0;
        }
      }
      if (visited[nx][ny]) continue;
      visited[nx][ny] = true;
      dist[nx][ny] = dist[x][y] + 1;
      // cout << "push " << nx << " " << ny << endl;
      Q.push({nx, ny});
    }
  }

}