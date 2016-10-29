#include <iostream>
#include <vector>
#include <bitset>
#include <set>
#define INF (1<<30)
using namespace std;

int n, m, x, y, cnt, mn, mni, c[100005], djs[100005], sz[100005];
bitset<100005> v;
vector<int> G[100005];
bool DFS(int);

int F(int x) { return djs[x] == x ? x : djs[x] = F(djs[x]); }

void U(int x, int y) {
  x = F(x); y = F(y);
  if (sz[x] > sz[y]) swap(x, y);
  djs[x] = y;
  sz[y] += sz[x];
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n;
  cin >> m;
  mn = INF;
  for (int i = 1; i <= n; ++i) djs[i] = i, sz[i] = 1;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    if (x != y) c[x]++; c[y]++, G[x].push_back(y), G[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    if (c[i] < mn) mn = c[i], mni = i;
  }
  v.reset();
  for (int i = 0; i < G[mni].size(); ++i) v[G[mni][i]] = true;
  for (int i = 1; i <= n; ++i) if (!v[i]) U(mni, i);
  v.reset();
  for (int i = 1; i <= n; ++i) {
    if (F(i) == F(mni)) v[i] = true;
    if (v[i]) continue;
    v.reset();
    v[i] = true;
    if (DFS(i)) U(i, mni);
  }
  v.reset();
  for (int i = 1; i <= n; ++i) {
    if (!v[F(i)]) cnt++, v[F(i)] = true;
  }
  cout << cnt << endl;
  return 0;
}

bool DFS(int x) {
  if (F(mni) == F(x)) return true;
  bitset<100005> vv;
  bool p = false;
  for (int i = 0; i < G[x].size(); ++i) vv[G[x][i]] = true;
  for (int i = 1; i <= n; ++i) {
    if (i == x) continue;
    if (!vv[i] && !v[i]) {
      v[i] = true;
      U(x, i);
      if (DFS(i)) U(x, mni), p = true;
    }
  }
  return p;
}
