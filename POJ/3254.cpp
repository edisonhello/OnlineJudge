#include <bits/stdc++.h>
using namespace std;

const int maxn = 12, MOD = 100000000;
int dp[maxn][1 << maxn], M, N, m[maxn][maxn];
bool v[maxn][1 << maxn];

int DP(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> M;
  for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) cin >> m[i][j];
  memset(dp, 0, sizeof(dp));
  cout << DP(N, (1 << M) - 1);
  return 0;
}

int DP(int r, int s) {
  if (v[r][s]) return dp[r][s];
  v[n][s] = true;
  if (r == 0) {
    for (int i = 0; i < M; ++i) {
      int ss = s;
      bool valid = true;
      if (!(ss & (1 << i))) valid = false;
      else ss ^= (1 << i);
      if (i) if (!(ss & (1 << (i - 1)))) valid = false;
      else ss ^= (1 << (i - 1));
      if (i < M - 1) if (!(ss & (1 << (i + 1)))) valid = false;
      else ss ^= (1 << (i + 1));
      if (valid && m[r][i]) dp[r][s] += 1 + DP(r, ss);
    }
    return dp[n][s];
  }
  for (int i = 0; i < M; ++i) {
    int ss = s;
    bool valid = true;
    if (!(ss & (1 << i))) valid = false;
    else ss ^= (1 << i);
    if (i) if (!(ss & (1 << (i - 1)))) valid = false;
    else ss ^= (1 << (i - 1));
    if (i < M - 1) if (!(ss & (1 << (i + 1)))) valid = false;
    else ss ^= (1 << (i + 1));
    if (valid && m[r][i]) dp[r][s] += DP(n, ss);
    
  }
  return dp[n][s];
}
