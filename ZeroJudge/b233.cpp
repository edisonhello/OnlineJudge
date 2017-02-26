#include <bits/stdc++.h>
using namespace std;

const int maxn = 30000 + 5;
vector<int> G[maxn], BCC[maxn];
int n, m, k, tin[maxn], low[maxn], bcc[maxn], ans, sz, Min;
struct Edge { int from, to; };
stack<Edge> s;
bool cut[maxn], v[maxn];

int dfs(int, int);
void GetSize(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m;
  while (m--) {
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  cin >> k;
  for (int i = 1; i <= n; ++i) if (!tin[i]) dfs(i, 0);
  for (int i = 1; i <= n; ++i) {
    for (int j : G[i]) if (bcc[i] != bcc[j])
  }
  ans = n + 1; Min = n + 1;
  for (int i = 1; i <= n; ++i) {
    if (i == k) continue;
    if (!cut[i]) continue;
    memset(v, false, sizeof(v));
    sz = 0;
    GetSize(k, i);
    if (sz < Min) ans = i, Min = sz;
    else if (sz == Min) ans = min(ans, i);
  }
  if (ans == n + 1) return cout << "0\n", 0;
  cout << ans << ' ' << Min << '\n';
  return 0;
}

int dfs(int x, int fa) {
  static int ind = 0;
  static int bccno = 0;
  tin[x] = low[x] = ++ind;
  int ch = 0;
  for (int u : G[x]) {
    s.push((Edge){ x, u });
    if (tin[u] && tin[u] < tin[x] && u != fa) {
      low[x] = min(low[x], tin[u]);
    }
    if (!tin[u]) {
      ++ch;
      int res = dfs(u, x);
      low[x] = min(low[x], res);
      if (res >= tin[x]) {
        ++bccno;
        cut[x] = true;
        while (true) {
          Edge e = s.top(); s.pop();
          if (bcc[e.from] != bccno) bcc[e.from] = bccno, BCC[bccno].push_back(e.from);
          if (bcc[e.to] != bccno) bcc[e.to] = bccno, BCC[bccno].push_back(e.to);
          if (e.from == x && e.to == u) break;
        }
      }
    }
  }
  if (ch == 1 && !fa) cut[x] = false;
  return low[x];
}

void GetSize(int x, int ct) {
  v[x] = true;
  ++sz;
  if (x == ct) return;
  for (int u : G[x]) if (!v[u]) GetSize(u, ct);
}
