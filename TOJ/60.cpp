#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;

int N, M, K, djs[5005], node, ans, cnt;
bool v[5005];

struct Edge {
  int st, ed, w;
  bool operator<(const Edge& ee) const {
    return w < ee.w;
  }
} e[100005];

vector<Edge> MST;

int F(int x) { return x == djs[x] ? x : djs[x] = F(djs[x]); }

void U(int x, int y) {
  x = F(x); y = F(y);
  djs[x] = y;
}

signed main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  for (int i = 0; i < 5005; ++i) djs[i] = i;
  cin >> N >> M >> K;
  if (K == -1) { cout << 0 << '\n'; return 0; }
  for (int i = 0; i < M; ++i) cin >> e[i].st >> e[i].ed >> e[i].w;
  sort(e, e + M);
  node = 1;
  for (int i = 0; i < M && node < N; ++i) {
    if (F(e[i].st) == F(e[i].ed)) continue;
    U(e[i].st, e[i].ed);
    ans += e[i].w; node++;
    MST.push_back(e[i]);
  }
  cnt = 1; node = 0;
  reverse(MST.begin(), MST.end());
  for (int i = 0; i < 5005; ++i) djs[i] = i;
  for (auto i : MST) {
    if (node >= K) break;
    if (F(i.st) == F(i.ed)) continue;
    U(i.st, i.ed);
    if (!v[i.st]) v[i.st] = true, node++;
    if (!v[i.ed]) v[i.ed] = true, node++;
    ans -= i.w;
  }
  cout << ans << '\n';
  return 0;
}
