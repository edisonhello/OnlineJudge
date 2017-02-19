#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int T, n, r[maxn];

bool check(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T;
  for (int kase = 1; kase <= T; ++kase) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> r[i];
    r[0] = 0;
    int d = 1, ans = r[n];
    while (d <= ans) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    cout << "Case " << kase << ": " << ans << '\n';
  }
  return 0;
}

bool check(int k) {
  for (int i = 0; i < n; ++i) {
    if (r[i + 1] - r[i] > k) return false;
    if (r[i + 1] - r[i] == k) --k;
  }
  return true;
}
