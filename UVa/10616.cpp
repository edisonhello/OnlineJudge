#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 5, maxm = 10 + 5, maxd = 20 + 5;
int n, q, a[maxn], d, m, kase;
long long _dp[maxn][maxm][maxd];
bool v[maxn][maxm][maxd];

long long dp(int, int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n >> q, n || q) {
    cout << "SET " << ++kase << ":\n";
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int qq = 1; qq <= q; ++qq) {
      memset(v, false, sizeof(v));
      cin >> d >> m;
      cout << "QUERY " << qq << ": " << dp(0, 0, 0) << '\n';
    }
  }
  return 0;
}

long long dp(int nn, int mm, int vv) {
  if (mm == m) {
    if (vv == 0) return 1;
    return 0;
  }
  if (nn == n) return 0;
  if (v[nn][mm][vv]) return _dp[nn][mm][vv];
  v[nn][mm][vv] = true;
  return _dp[nn][mm][vv] = dp(nn + 1, mm + 1, ((vv + a[nn]) % d + d) % d) + dp(nn + 1, mm, vv);
}
