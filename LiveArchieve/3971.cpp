#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1000 + 5, Max = 1000000000;
int T, n, b, ind1, ind2;
map<string, int> ids, types;
struct Prod { int type, id, pri, qua; } p[maxn];

bool check(int);

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    cin >> n >> b;
    ids.clear(); types.clear();
    ind1 = 0; ind2 = 0;
    for (int i = 0; i < n; ++i) {
      string osas, hao; cin >> osas >> hao;
      if (types.find(osas) == types.end()) types[osas] = ++ind1;
      if (ids.find(hao) == ids.end()) ids[hao] = ++ind2;
      cin >> p[i].pri >> p[i].qua;
      p[i].type = types[osas], p[i].id = ids[hao];
    }
    sort(p, p + n, [](const Prod& a, const Prod& b) {
      return a.pri < b.pri;
    });
    int d = 1, ans = 0;
    while (d <= Max) d <<= 1;
    while (d >>= 1) if (ans + d <= Max) if (check(ans + d)) ans += d;
    cout << ans << '\n';
  }
  return 0;
}

bool check(int x) {
  bool v[maxn];
  long long tot = 0;
  memset(v, false, sizeof(v));
  for (int i = 0; i < n; ++i) {
    if (p[i].qua < x) continue;
    if (v[p[i].type]) continue;
    tot += p[i].pri;
    v[p[i].type] = true;
  }
  for (int i = 1; i <= ind1; ++i) if (!v[i]) return false;
  return tot <= b;
}
