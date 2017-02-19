#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
vector<int> G[maxn], R[maxn], topo;
int N, M, p, a, b;
bool v[maxn];

void Init();
void DFS(int);
void dfs(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (cin >> N >> M, (N || M)) {
    Init();
    while (M--) {
      cin >> a >> b >> p;
      G[a].push_back(b); R[b].push_back(a);
      if (p == 2) G[b].push_back(a), R[a].push_back(b);
    }
    memset(v, false, sizeof(v));
    for (int i = 1; i <= N; ++i) if (!v[i]) DFS(i);
    reverse(topo.begin(), topo.end());
    memset(v, false, sizeof(v));
    dfs(topo[0]);
    bool ans = true;
    for (int i = 1; i <= N; ++i) if (!v[i]) ans = false;
    cout << ans << '\n';
  }
  return 0;
}

void Init() {
  for (int i = 0; i < maxn; ++i) G[i].clear(), R[i].clear();
  topo.clear();
}

void DFS(int x) {
  v[x] = true;
  for (int u : G[x]) if (!v[u]) DFS(u);
  topo.push_back(x);
}

void dfs(int x) {
  v[x] = true;
  for (int u : R[x]) if (!v[u]) dfs(u);
}
