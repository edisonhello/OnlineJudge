#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000000 + 5;
vector<int> G[maxn];
int low[maxn], N, tin[maxn], stamp;
vector<pair<int, int>> bridge;

void Init();
int DFS(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (cin >> N) {
    Init();
    for (int i = 0; i < N; ++i) {
      int a, b; cin >> a;
      string s; cin >> s;
      stringstream ss(s.substr(1, s.length() - 2));
      int k; ss >> k;
      while (k--) cin >> b, G[a].push_back(b);
    }
    for (int i = 0; i < N; ++i) if (!tin[i]) DFS(i, -1);
    cout << bridge.size() << " critical links\n";
    sort(bridge.begin(), bridge.end());
    for (auto i : bridge) cout << i.first << " - " << i.second << '\n';
    cout << '\n';
  }
  return 0;
}

void Init() {
  for (int i = 0; i < maxn; ++i) G[i].clear();
  memset(low, 0, sizeof(low));
  memset(tin, 0, sizeof(tin));
  stamp = 0;
  bridge.clear();
}

int DFS(int x, int fa) {
  tin[x] = ++stamp;
  low[x] = tin[x];
  for (int u : G[x]) {
    if (!tin[u]) {
      int res = DFS(u, x);
      low[x] = min(low[x], res);
      if (res > tin[x]) bridge.push_back(minmax(x, u));
    }
    else if (tin[u] < tin[x] && u != fa) {
      low[x] = min(low[x], tin[u]);
    }
  }
  return low[x];
}
