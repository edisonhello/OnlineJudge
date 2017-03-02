#include <bits/stdc++.h>
using namespace std;

const int maxn = 16;
int n, dp[1 << maxn], p[maxn], cover[1 << maxn], kase;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n, n) {
    memset(dp, 0, sizeof(dp));
    memset(p, 0, sizeof(p));
    memset(cover, 0, sizeof(cover));
    for (int i = 0; i < n; ++i) {
      int m, x; cin >> m;
      p[i] = (1 << i);
      while (m--) cin >> x, p[i] |= (1 << x);
    }
    for (int s = 0; s < (1 << n); ++s) {
      for (int i = 0; i < n; ++i) if (s & (1 << i)) cover[s] |= p[i];
    }
    for (int s = 1; s < (1 << n); ++s) {
      for (int sub = s; sub; sub = (sub - 1) & s) {
        if (cover[sub] == (1 << n) - 1) dp[s] = max(dp[s], dp[s ^ sub] + 1);
      }
    }
    cout << "Case " << ++kase << ": " << dp[(1 << n) - 1] << '\n';
  }
  return 0;
}
