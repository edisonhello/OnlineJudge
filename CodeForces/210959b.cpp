#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1000000 + 5;
int n, k, q[maxn], s[maxn], dp[maxn];

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> q[i], s[i] = s[i - 1] + q[i];
  for (int i = 1; i <= n; ++i) {
    if (i >= k) dp[i] = max({ dp[i - k], s[i], dp[i - 1] + q[i] });
    else dp[i] = s[i];
    // cout << "dp[" << i << "] = " << dp[i] << '\n';
  }
  cout << dp[n] << '\n';
  return 0;
}
