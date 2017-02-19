#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;
int N, Q, dp[2][maxn * maxn][maxn * maxn], w1[maxn][maxn], w2[maxn * maxn][maxn * maxn];
inline int id(int x, int y) { return x * N + y; }

int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> w1[i][j];
    }
  }
  for (int i = 0; i < N * N; ++i) for (int j = 0; j < N * N; ++j) w2[i][j] = 1000000;
  for (int i = 0; i < N * N; ++i) w2[i][i] = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i)         w2[id(i - 1, j)][id(i, j)] = w1[i][j];
      if (i < N - 1) w2[id(i + 1, j)][id(i, j)] = w1[i][j];
      if (j)         w2[id(i, j - 1)][id(i, j)] = w1[i][j];
      if (j < N - 1) w2[id(i, j + 1)][id(i, j)] = w1[i][j];
    }
  }
  for (int i = 0; i < N * N; ++i) for (int j = 0; j < N * N; ++j) dp[1][i][j] = 1000000;
  for (int i = 0; i < N * N; ++i) for (int j = 0; j < N * N; ++j) {
    if (w2[i][j] < 1000000) dp[1][i][j] = 0;
  }
  for (int a = 0; a < N * N; ++a) for (int b = 0; b < N * N; ++b) dp[0][a][b] = w2[a][b];
  for (int k = 0; k < N * N; ++k) {
    for (int i = 0; i < N * N; ++i) {
      for (int j = 0; j < N * N; ++j) {
        dp[0][i][j] = min(dp[0][i][j], dp[0][i][k] + dp[0][k][j]);
        dp[1][i][j] = min({ dp[0][i][k] + dp[1][k][j], dp[1][i][k] + dp[0][k][j], dp[1][i][j] });
      }
    }
  }
  cin >> Q;
  while (Q--) {
    int x, y, xx, yy; cin >> x >> y >> xx >> yy; --x, --y, --xx, --yy;
    if (x == xx && y == yy) { cout << "0\n"; continue; }
    cout << min(dp[1][id(x, y)][id(xx, yy)] + w1[x][y], dp[1][id(xx, yy)][id(x, y)] + w1[xx][yy]) << '\n';
  }
  return 0;
}
