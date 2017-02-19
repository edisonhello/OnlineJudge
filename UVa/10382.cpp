#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 5;
int n;
double l, w;
vector<pair<double, double>> v;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  while (cin >> n >> l >> w) {
    v.clear();
    for (int i = 0; i < n; ++i) {
      double f, r; cin >> f >> r;
      if (r < w / 2) continue;
      double len = sqrt(r * r - w * w / 4);
      v.push_back(make_pair(f - len, f + len));
    }
    sort(v.begin(), v.end());
    double pos = 0.0; int ans = 0;
    int i, j;
    for (i = 0; i < v.size(); i = j) {
      if (v[i].first > pos) break;
      for (j = i + 1; j < v.size() && v[j].first <= pos; ++j) {
        if (v[j].second > v[i].second) i = j;
      }
      ++ans; pos = v[i].second;
      if (pos >= l) break;
    }
    if (pos < l) cout << "-1\n";
    else cout << ans << '\n';
  }
  return 0;
}
