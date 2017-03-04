#include <bits/stdc++.h>
using namespace std;

const int maxn = 20 + 5, maxs = 500 + 5;
int mat[maxn << 1][maxn << 1], n, s, _dp[maxn << 1][maxn << 1][maxs];

int dp(int, int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n >> s, n || s) {
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n - i + 1; ++j) cin >> mat[i][j];
    for (int i = n + 1; i <= 2 * n - 1; ++i) for (int j = 1; j <= i - n + 1; ++j) cin >> mat[i][j];
    int ans = 0;
    memset(_dp, -1, sizeof(_dp));
    for (int i = 1; i <= n; ++i) ans += dp(2 * n - 1, i, s);
    cout << ans << '\n';
  }
  return 0;
}

int dp(int level, int pos, int s) {
  if (level == 0) {
    if (s == 0) return 1;
    return 0;
  }
  if (_dp[level][pos][s] != -1) return _dp[level][pos][s];
  _dp[level][pos][s] = 0;
  if (level > n) _dp[level][pos][s] = dp(level - 1, pos - 1, s - mat[level][pos]) + dp(level - 1, pos, s - mat[level][pos]);
  else _dp[level][pos][s] = dp(level - 1, pos, s - mat[level][pos]) + dp(level - 1, pos + 1, s - mat[level][pos]);
  return _dp[level][pos][s];
}
