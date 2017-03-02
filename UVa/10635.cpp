#include <bits/stdc++.h>
using namespace std;

const int maxn = 62500 + 5;
int T, n, p, q, b[maxn], kase;
pair<int, int> a[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    cin >> n >> p >> q;
    for (int i = 1; i <= p + 1; ++i) cin >> a[i].first, a[i].second = i;
    sort(a + 1, a + p + 2);
    for (int i = 1; i <= q + 1; ++i) cin >> b[i];
    vector<int> osas;
    for (int i = 1; i <= q + 1; ++i) {
      int ind = lower_bound(a + 1, a + p + 2, b[i], [](const pair<int, int>& a, const int& b) {
        return a.first < b;
      }) - a;
      if (a[ind].first == b[i]) osas.push_back(a[ind].second);
    }
    vector<int> LIS; LIS.push_back(osas[0]);
    for (int i = 1; i < osas.size(); ++i) {
      if (osas[i] > LIS.back()) LIS.push_back(osas[i]);
      else *lower_bound(LIS.begin(), LIS.end(), osas[i]) = osas[i];
    }
    cout << "Case " << ++kase << ": " << LIS.size() << '\n';
  }
  return 0;
}
