#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int T, n, k, a[maxn];
vector<int> pos[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    for (int i = 0; i < maxn; ++i) pos[i].clear();
    cin >> n >> k;
    bool ans = false;
    for (int i = 1; i <= n; ++i) cin >> a[i], pos[a[i]].push_back(i);
    for (int i = 0; i < maxn && !ans; ++i) if (pos[i].size()) {
      for (int j = 1; j < pos[i].size() && !ans; ++j) {
        if (pos[i][j] - pos[i][j - 1] <= k) ans = true, cout << "No\n";
      }
    }
    if (!ans) cout << "Yes\n";
  }
  return 0;
}
