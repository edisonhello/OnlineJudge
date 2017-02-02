#include <bits/stdc++.h>
using namespace std;

const int maxn = 500000 + 5, MOD = 1000000007;
vector<int> T[maxn];
int N, a, b, ch[maxn], fa[maxn];
bool v[2][2][maxn];
long long dp[2][2][maxn], _dp[3][maxn];

long long DP(int, int, int);
inline long long mod(long long);
void DFS(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N - 1; ++i) cin >> a >> b, T[a].push_back(b), T[b].push_back(a);
  DFS(0, -1);
  for (int ans = 1; ; ++ans) {
    memset(v[ans & 1], false, sizeof(v[ans & 1]));
    for (int k = 0; k < 2; ++k) for (int i = 0; i < N; ++i) {
      if (!v[ans & 1][k][i]) DP(ans, k, i);
    }
    if (dp[ans & 1][0][0] > 0) { cout << ans - 1 << ' ' << dp[ans & 1][0][0] << '\n'; break; }
  }
  return 0;
}

void DFS(int x, int p) {
  fa[x] = p;
  ch[x] = 0;
  for (int u : T[x]) if (u != p) ch[x]++, DFS(u, x);
}

long long DP(int ans, int k, int x) {
  if (ans == 0) return 0;
  if (v[ans & 1][k][x]) return dp[ans & 1][k][x];
  for (int u : T[x]) if (u != fa[x]) DP(ans - 1, 0, u), DP(ans, 1, u);
  _dp[0][0] = 1;
  int it = 1;
  for (int u : T[x]) if (u != fa[x]) _dp[0][it] = mod(_dp[0][it - 1] * dp[(ans - 1) & 1][0][u]), ++it;
  for (int i = 1; i <= 2; ++i) {
    it = 1;
    _dp[i][0] = 0;
    for (int u : T[x]) if (u != fa[x]) {
      _dp[i][it] = mod(_dp[i][it - 1] * dp[(ans - 1) & 1][0][u]);
      _dp[i][it] += mod(_dp[i - 1][it - 1] * dp[ans & 1][1][u]);
      _dp[i][it] = mod(_dp[i][it]);
      if (i > it) _dp[i][it] = 0;
      ++it;
    }
  }
  v[ans & 1][0][x] = true; v[ans & 1][1][x] = true;
  dp[ans & 1][1][x] = mod(_dp[0][ch[x]] + _dp[1][ch[x]]);
  dp[ans & 1][0][x] = mod(dp[ans & 1][1][x] + _dp[2][ch[x]]);
  return dp[ans & 1][k][x];
}

inline long long mod(long long x) {
  return x >= MOD ? x % MOD : x;
}
