#include <iostream>
#include <cstring>
#define max(x,y) (x>y)?x:y
#define int long long
using namespace std;

int dp[100000], v, n, w[100005], p[100005];

signed main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> v) {
    cin >> n; for (int i = 0; i < n; ++i) cin >> w[i] >> p[i];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
      for (int j = w[i]; j <= v; ++j) {
        dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
      }
    }
    cout << dp[v] << '\n';
  }
  return 0;
}
