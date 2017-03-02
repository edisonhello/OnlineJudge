#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
vector<int> G[maxn], leaf;
int n;

void dfs(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n) {
    leaf.clear();
    for (int i = 0; i < maxn; ++i) G[i].clear();
    for (int i = 0; i < n - 1; ++i) {
      int a, b; cin >> a >> b;
      G[b].push_back(a);
      G[a].push_back(b);
    }
    dfs(1, -1);
    int m = (int)leaf.size(), offset = m / 2;
    cout << (m + 1) / 2 << '\n';
    for (int i = 0; i < m / 2; ++i) cout << leaf[i] << ' ' << leaf[i + offset] << '\n';
    if (m & 1) cout << leaf[m - 1 - offset] << ' ' << leaf[m - 1] << '\n';
  }
  return 0;
}

void dfs(int x, int fa) {
  for (int u : G[x]) if (u != fa) dfs(u, x);
  if (G[x].size() == 1) leaf.push_back(x);
}
