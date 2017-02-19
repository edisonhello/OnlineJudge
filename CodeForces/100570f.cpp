#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5, lg = 20;
struct Edge { int from, to, cost; };
vector<Edge> G[maxn];
int N, Q, sz[maxn], fa[maxn], dep[maxn];
long long dis[lg][maxn];
bool v[maxn];

int CenterDecomp(int, int);
void GetSize(int, int);
int FindCenter(int, int, int);
void GetDis(int, int, int, long long);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> N >> Q;
  for (int i = 0; i < N - 1; ++i) {
    int a, b, w; cin >> a >> b >> w;
    G[a].push_back((Edge){ a, b, w });
    G[b].push_back((Edge){ b, a, w });
  }
  CenterDecomp(1, 0);
  for (int i = 1; i <= N; ++i) cout << dep[i] << ' ';
  while (Q--) {

  }
}

int CenterDecomp(int x, int depth) {
  GetSize(x, 0);
  int cen = FindCenter(x, 0, x);
  v[cen] = true;
  dep[cen] = depth;
  GetDis(x, 0, 0, 0);
  for (Edge e : G[cen]) if (!v[e.to]) {
    int ch = CenterDecomp(e.to, depth + 1);
    fa[ch] = cen;
  }
  return cen;
}

void GetSize(int x, int fa) {
  sz[x] = 1;
  for (Edge e : G[x]) if (e.to != fa && !v[e.to]) {
    GetSize(e.to, x);
    sz[x] += sz[e.to];
  }
}

int FindCenter(int x, int fa, int root) {
  int Max = 0;
  for (Edge e : G[x]) if (e.to != fa && !v[e.to]) {
    int cen = FindCenter(e.to, x, root);
    if (cen) return cen;
    Max = max(Max, sz[e.to]);
  }
  Max = max(Max, sz[root] - sz[x]);
  if (Max <= sz[root] / 2) return x;
  return 0;
}

void GetDis(int x, int fa, int dep, long long d) {
  dis[dep][x] = d;
  for (Edge e : G[x]) if (e.to != fa && !v[e.to]) {
    GetDis(e.to, x, dep, d + e.cost);
  }
}
