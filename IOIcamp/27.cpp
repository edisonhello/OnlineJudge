#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int maxn = 10000 + 5;
vector<int> G[maxn], R[maxn], BCC[maxn];
int T, N, M, tin[maxn], low[maxn], stamp, deg[maxn], bcc, bccno[maxn];
bool cut[maxn], v[maxn], add[maxn];
stack<pair<int, int>> s;

void Init();
int DFS(int, int);
void dfs(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> N >> M;
    Init();
    int a, b;
    while (cin >> a >> b, (a != -1 || b != -1)) {
      G[a].push_back(b); G[b].push_back(a);
    }
    for (int i = 0; i < N; ++i) if (!tin[i]) DFS(i, -1);
    for (int i = 1; i <= bcc; ++i) {
      for (int j : BCC[i]) ++deg[j];
    }
    vector<int> ans;
    for (int i = 0; i < N; ++i) ans.push_back(i);
    sort(ans.begin(), ans.end(), [](const int& a, const int& b) -> bool {
      return deg[a] == deg[b] ? a < b : deg[a] > deg[b];
    });
    for (int i = 0; i < M; ++i) cout << ans[i] << ' ' << deg[ans[i]] << '\n';
  }
  return 0;
}

void Init() {
  for (int i = 0; i < maxn; ++i) G[i].clear(), BCC[i].clear();
  memset(tin, 0, sizeof(tin));
  memset(deg, 0, sizeof(deg));
  memset(low, 0, sizeof(low));
  memset(cut, false, sizeof(cut));
  memset(bccno, 0, sizeof(bccno));
  bcc = 0;
  stamp = 0;
}

int DFS(int x, int fa) {
  tin[x] = ++stamp;
  low[x] = tin[x];
  int ch = 0;
  for (int u : G[x]) {
    if (!tin[u]) {
      s.push(make_pair(x, u));
      ++ch;
      int lowu = DFS(u, x);
      low[x] = min(low[x], lowu);
      if (lowu >= tin[x]) {
        cut[x] = true;
        ++bcc;
        while (true) {
          pair<int, int> e = s.top(); s.pop();
          if (bccno[e.fi] != bcc) BCC[bcc].push_back(e.fi), bccno[e.fi] = bcc;
          if (bccno[e.se] != bcc) BCC[bcc].push_back(e.se), bccno[e.se] = bcc;
          if (e.fi == x && e.se == u) break;
        }
      }
    } else if (tin[u] < tin[x] && u != fa) {
      s.push(make_pair(x, u));
      low[x] = min(low[x], tin[u]);
    }
  }
  if (fa < 0 && ch == 1) cut[x] = false;
  return low[x];
}
