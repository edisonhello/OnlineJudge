#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int T, n, s[maxn];
long long k, dp[maxn];

inline long long f(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T; while (T--) {
    cin >> n >> k;
    int x;
    for (int i = 1; i <= n; ++i) cin >> x, s[i] = s[i - 1] + x;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      dp[i] = LLONG_MAX;
      for (int j = 0; j < i; ++j) dp[i] = min(dp[i], f(j, i));
      cout << "dp[" << i << "] = " << dp[i] << '\n';
    }
    cout << dp[n] << '\n';
  }
  return 0;
}

inline long long f(int L, int R) {
  return dp[L] + (long long)(s[R] - s[L]) * (long long)(s[R] - s[L]) * (long long)(s[R] - s[L]) + k;
}
