#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 5, lg = 14;
vector<int> G[maxn];
int N, Q, a, b, C, dep[maxn], p[lg][maxn], dis[lg][maxn];
string s1, s2;

void DFS(int, int, int);
void LCA(int, int);
void Dis(int, int, int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> C;
  while (C--) {
    cin >> N >> Q;
    memset(dep, 0, sizeof(dep));
    memset(p, -1, sizeof(p));
    memset(dis, 0, sizeof(dis));
    for (int i = 0; i < N; ++i) G[i].clear();
    for (int i = 0; i < N - 1; ++i) cin >> a >> b, G[a].push_back(b), G[b].push_back(a);
    DFS(0, -1, 0);
    while (Q--) {
      cin >> s1 >> a >> s2 >> b;
      cout << s1 << " and " << s2 << ": ";
      LCA(a, b);
    }
  }
  return 0;
}

void DFS(int x, int fa, int d) {
  dep[x] = d;
  p[0][x] = fa;
  dis[0][x] = 1;
  for (int k = 1; k < lg; ++k) {
    if ((1 << k) > dep[x]) break;
    p[k][x] = p[k - 1][p[k - 1][x]];
    dis[k][x] += dis[k - 1][x] + dis[k - 1][p[k - 1][x]];
  }
  for (int u : G[x]) if (u != fa) {
    DFS(u, x, d + 1);
  }
}

void LCA(int a, int b) {
  int disa = 0, disb = 0;
  if (a == b) { cout << a << '\n'; return; }
  if (dep[a] > dep[b]) swap(a, b);
  int aa = a, bb = b;
  for (int k = 0; k < lg; ++k) {
    if ((dep[b] - dep[a]) >> k & 1) disb += dis[k][b], b = p[k][b];
  }
  if (a == b) { Dis(aa, bb, disa, disb); return; }
  for (int k = lg - 1; k >= 0; --k) {
    if (p[k][a] != p[k][b]) {
      disa += dis[k][a], disb += dis[k][b];
      a = p[k][a], b = p[k][b];
    }
    if (a == b) { Dis(aa, bb, disa, disb); return; }
  }
  disa += dis[0][a], disb += dis[0][b];
  Dis(aa, bb, disa, disb);
}

void Dis(int aa, int bb, int disa, int disb) {
  int diss = disa + disb;
  if (disa > disb) {
    // for (int i = 0, k = 0; i < diss / 2 && k < lg; ++k) i += dis[k][aa], aa = p[k][aa];
    int k;
    for (k = 0; k < lg; ++k) {
      if (dis[k][aa] >= diss / 2) break;
      aa = p[k][aa];
    }
    if (diss & 1) cout << min(aa, p[0][aa]) << ' ' << max(aa, p[0][aa]) << '\n';
    else cout << aa << '\n';
  } else {
    int k = 0;
    // for (int i = 0, k = 0; i < diss / 2 && k < lg; ++k) i += dis[k][bb], bb = p[k][bb];
    int now = 0;
    for (k = lg; k >= 0; --k) {

      if (now + )
    }
    if (diss & 1) cout << min(bb, p[0][bb]) << ' ' << max(bb, p[0][bb]) << '\n';
    else cout << bb << '\n';
  }
}
