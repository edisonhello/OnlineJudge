#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 5;
int n, m, k, f[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n >> k >> m, n) {
    f[1] = 0;
    for (int i = 2; i <= n; ++i) f[i] = (f[i - 1] + k) % i;
    int ans = m - k + 1 + f[n];
    ans = (ans % n + n) % n;
    if (ans <= 0) ans += n;
    cout << ans << '\n';
  }
  return 0;
}
