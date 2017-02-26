#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int n, m, k;
vector<int> t[maxn];
struct Seg { int l, r; };
vector<Seg> s[maxn];

bool cmp(const Seg&, const int&);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x; cin >> x;
      t[i].push_back(x);
    }
  }
  for (int i = 0; i < m; ++i) t[n].push_back(0);
  for (int j = 0; j < m; ++j) {
    int i = 0, st = 0;
    while (i < n) {
      if (t[i + 1][j] >= t[i][j]) ++i;
      else s[j].push_back((Seg){ st, i }), ++i, st = i;
    }
  }
  cin >> k;
  while (k--) {
    int l, r; cin >> l >> r; --l, --r;
    bool ans = false;
    for (int j = 0; j < m && !ans; ++j) {
      int id1 = lower_bound(s[j].begin(), s[j].end(), l, cmp) - s[j].begin();
      int id2 = lower_bound(s[j].begin(), s[j].end(), r, cmp) - s[j].begin();
      if (id1 == id2) ans = true, cout << "Yes\n";
    }
    if (!ans) cout << "No\n";
  }
  return 0;
}

bool cmp(const Seg& s, const int& i) {
  return s.r < i;
}
