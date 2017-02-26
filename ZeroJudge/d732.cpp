#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int n, k, a[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  while (k--) {
    int x; cin >> x;
    if (upper_bound(a + 1, a + n + 1, x) - lower_bound(a + 1, a + n + 1, x)) cout << lower_bound(a + 1, a + n + 1, x) - a << '\n';
    else cout << 0 << '\n';
  }
  return 0;
}
