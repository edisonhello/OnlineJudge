#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 5, MOD = 1000000007;
int dp[maxn], n, d, t;

int main() {
  cin >> d >> t;
  dp[0] = 1;
  for (int i = 1; i < maxn; ++i) for (int j = i; j < maxn; ++j) dp[j] += dp[j - i], dp[j] %= MOD;
  while (t--) {
    cin >> n;
    cout << dp[n] << '\n';
  }
  return 0;
}
