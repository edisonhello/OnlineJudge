#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
int a[maxn], n, dp[maxn];
long long tot;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  fill(dp, dp + n + 1, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    if (tot + a[i] >= 0) dp[i] = dp[i - 1];
    else {

    }
  }
  return 0;
}
