#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 5, MAX = 1000000 + 5;
int n, a[maxn], cnt[MAX];
bool osas;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n, n) {
    if (osas) cout << '\n';
    osas = true;
    memset(cnt, 0, sizeof(cnt));
    int ans = 0;
    for (int i = 0; i < n; ++i) cin >> a[i], ans = max(ans, ++cnt[a[i]]);
    sort(a, a + n);
    cout << ans << '\n';
    for (int i = 0; i < ans; ++i) {
      cout << a[i];
      for (int j = 1; j * ans + i < n; ++j) cout << ' ' << a[j * ans + i];
      cout << '\n';
    }
  }
  return 0;
}
