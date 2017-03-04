#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
vector<int> G[maxn], leaf;
int T, n, fa[maxn], dep[maxn], s, k;
bool server[maxn];

void dfs(int, int, int);
bool dfs2(int, int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    for (int i = 0; i < maxn; ++i) G[i].clear();
    leaf.clear(); memset(server, false, sizeof(server));
    cin >> n;
    cin >> s >> k;
    for (int i = 0; i < n - 1; ++i) {
      int a, b; cin >> a >> b;
      G[a].push_back(b); G[b].push_back(a);
    }
    server[s] = true;
    dfs(s, 0, 0);
    sort(leaf.begin(), leaf.end(), [=](const int& a, const int& b) {
      return dep[a] > dep[b];
    });
    for (int u : leaf) {
      cerr << "u: " << u << '\n';
      bool ok = false;
      int x = u;
      for (int i = 0; i < k && !ok; ++i) {
        if (fa[u]) u = fa[u];
        else break;
        if (server[u]) ok = true;
      }
      if (!ok) if (!dfs2(x, 0, 0)) server[u] = true;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) if (server[i]) ++cnt;
    cout << cnt - 1 << '\n';
  }
  return 0;
}

void dfs(int x, int p, int d) {
  fa[x] = p;
  dep[x] = d;
  int ch = 0;
  for (int u : G[x]) if (u != p) ++ch, dfs(u, x, d + 1);
  if (ch == 0) leaf.push_back(x);
}

bool dfs2(int x, int p, int d) {
  if (server[x]) return true;
  if (d == k) return false;
  for (int u : G[x]) if (u != p) if (dfs2(u, x, d + 1)) return true;
  return false;
}
