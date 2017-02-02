#include <bits/stdc++.h>
using namespace std;

const int maxn = 500000 + 5, lg = 19, MOD = 1000000007;
vector<int> T[maxn];
bool v[2][lg][maxn], first;
int N, a, b, cur, fa[maxn];
long long f[2][maxn], g[2][maxn];

long long F(int, int);
long long G(int, int);
void DFS(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N - 1; ++i) cin >> a >> b, T[a].push_back(b), T[b].push_back(a);
  cur = 0;
  first = true;
  DFS(0, -1);
  for (int ans = 0; ; ++ans) {
    if (ans) first = false;
    memset(v[0][cur], false, sizeof(v[0][cur]));
    memset(v[1][cur], false, sizeof(v[1][cur]));
    for (int i = 0; i < N; ++i) if (!v[0][cur][i]) F(cur, i);
    for (int i = 0; i < N; ++i) if (!v[1][cur][i]) G(cur, i);
    if (f[cur][0] > 0) { cout << ans << ' ' << f[cur][0] << '\n'; break; }
    cur ^= 1;
  }
  return 0;
}

long long F(int n, int s) {
  // cout << "F: " << n << ' ' << s << ' ' << fa << '\n';
  if (n < 0) return 0;
  if (v[0][n][s]) return f[n][s];
  f[n][s] = G(n, s);
  for (int i = 0; i < T[s].size(); ++i) if (T[s][i] != fa[s]) {
    for (int j = 0; j < T[s].size(); ++j) if (T[s][j] != fa[s] && T[s][i] < T[s][j]) {
      long long d = (G(n, T[s][i]) % MOD) * (G(n, T[s][j]) % MOD) % MOD;
      for (int k = 0; k < T[s].size(); ++k) if (T[s][k] != fa[s] && T[s][k] != T[s][i] && T[s][k] != T[s][j]) {
        d = d * F(first ? n - 1 : n ^ 1, T[s][k]) % MOD;
      }
      f[n][s] += d;
      f[n][s] %= MOD;
    }
  }
  v[0][n][s] = true;
  cout << "f[" << n << "][" << s << "] = " << f[n][s] << '\n';
  return f[n][s] % MOD;
}

long long G(int n, int s) {
  // cout << "G: " << n << ' ' << s << ' ' << fa << '\n';
  if (n < 0) return 0;
  if (v[1][n][s]) return g[n][s];
  g[n][s] = 1LL;
  for (int a : T[s]) if (a != fa[s]) g[n][s] = g[n][s] * F(first ? n - 1 : n ^ 1, a) % MOD;
  for (int a : T[s]) if (a != fa[s]) {
    long long d = G(n, a);
    for (int b : T[s]) if (b != fa[s] && a != b) {
      d = d * F(first ? n - 1 : n ^ 1, b) % MOD;
    }
    g[n][s] += d;
  }
  v[1][n][s] = true;
  cout << "g[" << n << "][" << s << "] = " << g[n][s] << '\n';
  return g[n][s] % MOD;
}

void DFS(int x, int p) {
  fa[x] = p;
  for (int u : T[x]) if (u != p) DFS(u, x);
}
