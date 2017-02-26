#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int n, t, fa[maxn], dp[maxn];
vector<int> G[maxn];

void dfs(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (cin >> n >> t, n || t) {
    for (int i = 0; i < maxn; ++i) G[i].clear();
    for (int i = 1; i <= n; ++i) cin >> fa[i], G[i].push_back(fa[i]), G[fa[i]].push_back(i);
    memset(dp, 0, sizeof(dp));
    dfs(0, -1);
    cout << dp[0] << '\n';
  }
  return 0;
}

void dfs(int x, int fa) {
  int ch = 0;
  vector<int> chs;
  for (int u : G[x]) if (u != fa) {
    ++ch;
    dfs(u, x);
    chs.push_back(dp[u]);
  }
  if (ch == 0) { dp[x] = 1; return; }
  sort(chs.begin(), chs.end());
  int chosen = 0;
  for (int i : chs) {
    dp[x] += i;
    ++chosen;
    if ((double)chosen / (double)ch >= (double)t / (double)100.0) break;
  }
}
