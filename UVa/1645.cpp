#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5, MOD = 1000000007;
int dp[maxn], n, kase;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  dp[1] = 1;
  for (int i = 2; i < maxn; ++i) {
    for (int j = 1; j < i; ++j) {
      if ((i - 1) % j == 0) dp[i] += dp[(i - 1) / j], dp[i] %= MOD;
    }
  }
  while (cin >> n) cout << "Case " << ++kase << ": " << dp[n] << '\n';
  return 0;
}
