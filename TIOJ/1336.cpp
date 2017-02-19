#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int W, H, g, b;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[] = { 0, 1, 0, -1, 1, -1, 1, -1};
bool v[maxn][maxn];
string m[maxn];

void DFS(int, int, char);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> W >> H;
  for (int i = 0; i < H; ++i) cin >> m[i];
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (v[i][j]) continue;
      if (m[i][j] == 'G') ++g, DFS(i, j, m[i][j]);
      if (m[i][j] == '-') ++b, DFS(i, j, m[i][j]);
    }
  }
  cout << g << ' ' << b << '\n';
  return 0;
}

void DFS(int x, int y, char c) {
  v[x][y] = true;
  for (int i = 0; i < 8; ++i) {
    if (x + dx[i] >= H || x + dx[i] < 0 || y + dy[i] >= W || y + dy[i] < 0) continue;
    if (v[x + dx[i]][y + dy[i]]) continue;
    if (m[x + dx[i]][y + dy[i]] == c) DFS(x + dx[i], y + dy[i], c);
  }
}
