#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
int T, n, a[maxn], b[maxn];

bool check(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    int d = 1, ans = 100000;
    while (d <= 100000) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    cout << ans << '\n';
  }
  return 0;
}

bool check(int x) {
  int w = 0, e = 0, osas = 0;
  for (int i = 0; i < n; ++i) {
    w += a[i], e += b[i]; ++osas;
    if (w - 1 > x) osas -= w - 1 - x, w = x + 1;
    if (osas < 0) return false;
    if (e - 1 > x) osas -= e - 1 - x, w = x + 1;
    if (osas < 0) return false;
  }
  return true;
}
