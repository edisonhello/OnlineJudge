#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
struct Edge { int id, to; };
vector<Edge> G[maxn];
bool v[maxn], odd;
int T, N, a, b, deg[maxn], Max, kase;
stack<pair<int, int>> s;

void Init();
void DFS(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T; while (T--) {
    Init(); cin >> N;
    cout << "Case #" << ++kase << '\n';
    for (int i = 0; i < N; ++i) {
      cin >> a >> b;
      G[a].push_back((Edge){ i, b });
      G[b].push_back((Edge){ i, a });
      ++deg[a]; ++deg[b];
      Max = max({ Max, a, b });
    }
    for (int i = 1; i <= Max; ++i) if (deg[i] & 1) odd = true;
    if (odd) {
      cout << "some beads may be lost\n";
      if (T) cout << "\n";
      continue;
    }
    DFS(Max);
    if (T) cout << '\n';
  }
  return 0;
}

void Init() {
  for (int i = 0; i < maxn; ++i) G[i].clear();
  memset(v, false, sizeof(v));
  memset(deg, 0, sizeof(deg));
  odd = false; Max = 0;
}

void DFS(int x) {
  for (Edge e : G[x]) if (!v[e.id]) {
    v[e.id] = true;
    DFS(e.to);
    cout << e.to << ' ' << x << '\n';
  }
}
