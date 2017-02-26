#include <bits/stdc++.h>
using namespace std;

int n, dp[50], ans;
vector<int> G[50], ed;
bool jizz;

void dfs(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (cin >> n) {
    if (jizz) cout << "\n";
    jizz = true;
    for (int i = 0; i < 50; ++i) G[i].clear();
    ed.clear();
    for (int i = 0; i < n; ++i) {
      int a, k; cin >> k;
      if (!k) ed.push_back(i);
      while (k--) cin >> a, G[a].push_back(i);
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) if (!dp[i]) dfs(i);
    ans = 0; for (int i : ed) ans += dp[i];
    cout << ans << '\n';
  }
  return 0;
}

void dfs(int x) {
  if (dp[x]) return;
  if (x == 0) { dp[x] = 1; return; }
  dp[x] = 0;
  for (int u : G[x]) dfs(u), dp[x] += dp[u];
}
