#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 5, maxm = 40000 + 5;
int N, M, a, b, stamp, tin[maxn], bcc;
struct Edge { int id, to; };
vector<Edge> G[maxn];
vector<int> BCC[maxn];
bool bridge[maxm], v[maxn];

int DFS(int, int);
void dfs(int);
bool cmp(const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; }

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    cin >> a >> b;
    G[a].push_back((Edge){ i, b });
    G[b].push_back((Edge){ i, a });
  }
  DFS(0, -1);
  for (int i = 0; i < N; ++i) if (!v[i]) ++bcc, dfs(i);
  for (int i = 1; i <= bcc; ++i) sort(BCC[i].begin(), BCC[i].end());
  sort(BCC + 1, BCC + bcc + 1, cmp);
  for (int i = 1; i <= bcc; ++i) {
    cout << i << ": ";
    for (int j : BCC[i]) cout << j << ' ';
    cout << '\n';
  }
  return 0;
}

int DFS(int x, int fa) {
  tin[x] = ++stamp;
  int low = tin[x];
  int child = 0;
  for (Edge e : G[x]) {
    if (!tin[e.to]) {
      ++child;
      int lowv = DFS(e.to, x);
      low = min(low, lowv);
      if (lowv >= tin[x]) bridge[e.id] = true;
    } else if (tin[e.to] < tin[x] && e.to != fa) {
      low = min(low, tin[e.to]);
    }
  }
  return low;
}

void dfs(int x) {
  BCC[bcc].push_back(x);
  v[x] = true;
  for (Edge e : G[x]) if (!v[e.to] && !bridge[e.id]) dfs(e.to);
}
