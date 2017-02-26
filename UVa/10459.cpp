#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
int n, dp[maxn], height;
vector<int> G[maxn];

void dfs(int, int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (cin >> n) {
    for (int i = 0; i < maxn; ++i) G[i].clear();
    for (int i = 1; i <= n; ++i) {
      int k, adj; cin >> k;
      while (k--) cin >> adj, G[i].push_back(adj), G[adj].push_back(i);
    }
    dfs(1, 0);
  }
  return 0;
}

void dfs(int x, int fa, int d) {
  dp[x] = d;

}
