#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 5, lg = 20;
struct Edge { int from, to; long long cost; };
int T, N, M, K, loc[maxn], sz[maxn], fa[maxn], cnt[maxn], dep[maxn];
long long dis[lg][maxn];
pair<long long, long long> Fa[maxn], Ch[maxn];
vector<Edge> G[maxn];
bool v[maxn];

void Init();
int CenDecomp(int, int);
void GetSize(int, int);
int FindCenter(int, int, int);
void GetDis(int, int, int, long long);
void modify(int, int);
long long query(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T;
  while (T--) {
    Init();
    cin >> N >> M >> K;
    for (int i = 0; i < N - 1; ++i) {
      int a, b, w; cin >> a >> b >> w;
      G[a].push_back((Edge){ a, b, w });
      G[b].push_back((Edge){ b, a, w });
    }
    CenDecomp(1, 0);
    modify(1, M - 1);
    while (K--) {
      int s, x; cin >> s >> x;
      if (s == 1) loc[s] = x;
      else {
        modify(loc[s], -1);
        loc[s] = x;
        modify(loc[s], 1);
      }
      cout << query(loc[1]) << '\n';
    }
  }
  return 0;
}

void Init() {
  for (int i = 0; i < maxn; ++i) G[i].clear();
  fill(loc, loc + maxn, 1);
  memset(v, false, sizeof(v));
  memset(cnt, 0, sizeof(cnt));
  memset(Fa, 0, sizeof(Fa));
  memset(Ch, 0, sizeof(Ch));
  memset(sz, 0, sizeof(sz));
  memset(dep, 0, sizeof(dep));
  memset(dis, 0, sizeof(dis));
  memset(fa, 0, sizeof(fa));
}

void GetSize(int x, int fa) {
  sz[x] = 1;
  for (Edge e : G[x]) if (e.to != fa && !v[e.to]) {
    GetSize(e.to, x);
    sz[x] += sz[e.to];
  }
}

int CenDecomp(int x, int depth) {
  GetSize(x, 0);
  int cen = FindCenter(x, 0, x);
  v[cen] = true;
  dep[cen] = depth;
  GetDis(cen, 0, depth, 0);
  for (Edge e : G[cen]) if (!v[e.to]) {
    int ch = CenDecomp(e.to, depth + 1);
    fa[ch] = cen;
  }
  return cen;
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

void GetDis(int x, int fa, int depth, long long d) {
  dis[depth][x] = d;
  for (Edge e : G[x]) if (e.to != fa && !v[e.to]) {
    GetDis(e.to, x, depth, d + e.cost);
  }
}

void modify(int x, int v) {
  cnt[x] += v;
  int d = dep[x];
  int now = x;
  while (d--) {
    Fa[x].first += v;
    Fa[x].second += (long long)v * dis[d][now];
    x = fa[x];
    Ch[x].first += v;
    Ch[x].second += (long long)v * dis[d][now];
  }
}

long long query(int x) {
  long long ret = Ch[x].second;
  int d = dep[x];
  int now = x;
  while (d--) {
    ret += Ch[fa[x]].second;
    ret -= Fa[x].second;
    ret += (Ch[fa[x]].first + cnt[fa[x]] - Fa[x].first) * dis[d][now];
    x = fa[x];
  }
  return ret;
}
