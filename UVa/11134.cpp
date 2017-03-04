#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
int n;
struct Lim { int lx, ly, rx, ry, i; } lim[maxn];
pair<int, int> ans[maxn];
bool v[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n, n) {
    for (int i = 0; i < n; ++i) cin >> lim[i].lx >> lim[i].ly >> lim[i].rx >> lim[i].ry, lim[i].i = i;
    bool pos = true;
    sort(lim, lim + n, [](const Lim& a, const Lim& b) {
      return a.rx < b.rx;
    });
    memset(v, false, sizeof(v));
    for (int i = 0; i < n && pos; ++i) {
      bool place = false;
      for (int j = lim[i].lx; j <= lim[i].rx && !place; ++j) if (!v[j]) place = true, ans[lim[i].i].first = j, v[j] = true;
      if (!place) pos = false;
    }
    sort(lim, lim + n, [](const Lim& a, const Lim& b) {
      return a.ry < b.ry;
    });
    memset(v, false, sizeof(v));
    if (pos) for (int i = 0; i < n && pos; ++i) {
      bool place = false;
      for (int j = lim[i].ly; j <= lim[i].ry && !place; ++j) if (!v[j]) place = true, ans[lim[i].i].second = j, v[j] = true;
      if (!place) pos = false;
    }
    if (pos) for (int i = 0; i < n; ++i) cout << ans[i].first << ' ' << ans[i].second << '\n';
    else cout << "IMPOSSIBLE\n";
  }
  return 0;
}
