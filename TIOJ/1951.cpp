#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, ans;

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n;
  for (int x = n + 1; x <= 3 * n; ++x) {
    for (int y = x; y <= (2 * n * x) / (x - n); ++y) {
      if (x * y - n * y - n * x <= 0) continue;
      if ((n * x * y) % (x * y - n * y - n * x) != 0) continue;
      int z = (n * x * y) / (x * y - n * y - n * x);
      if (z >= y) ans += x + y;
    }
  }
  cout << ans << '\n';
  return 0;
}
