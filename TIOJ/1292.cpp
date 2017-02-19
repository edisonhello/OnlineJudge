#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 5;
vector<int> G[maxn];
int N, dp[2][maxn];

void dfs(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    int a, b; cin >> a >> b;
    G[a].push_back(b); G[b].push_back(a);
  }
  dfs(1, 0);
  cout << min(dp[0][1], dp[1][1]) << '\n';
  return 0;
}

void dfs(int x, int fa) {
  dp[1][x] = 1;
  dp[0][x] = 0;
  for (int u : G[x]) if (u != fa) {
    dfs(u, x);
    dp[1][x] = min(dp[1][x] + dp[0][u], dp[1][x] + dp[1][u]);
    dp[0][x] += dp[1][u];
  }
}
