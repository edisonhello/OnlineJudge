#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000 + 5;
int T, n, a[maxn], p[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    memset(p, 0, sizeof(p));
    int cur = 0, Max = 0;
    for (int i = 1; i <= n; ++i) {
      if (p[a[i]] >= cur) Max = max(Max, i - cur), cur = p[a[i]];
      p[a[i]] = i;
    }
    Max = max(Max, n + 1 - cur);
    cout << Max - 1 << '\n';
  }
  return 0;
}
