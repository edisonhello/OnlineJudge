#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int n, r[maxn];

bool check(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n, n) {
      int Max = 0;
    for (int i = 0; i < n; ++i) cin >> r[i], Max = max(Max, r[i]);
    r[n] = r[0];
    if (n == 1) { cout << r[0] << '\n'; continue; }
    Max *= 3;
    int low = 0;
    for (int i = 0; i < n; ++i) low = max(low, r[i] + r[i + 1]);
    int d = 1, ans = Max;
    while (d <= Max) d <<= 1;
    if (n % 2 == 1) while (d >>= 1) if (ans - d >= low) if (check(ans - d)) ans -= d;
    if (n % 2 == 1) cout << ans << '\n';
    else cout << low << '\n';
  }
  return 0;
}

bool check(int osas) {
  int left[maxn], right[maxn];
  memset(left, 0, sizeof(left)); memset(right, 0, sizeof(right));
  left[0] = r[0];
  int x = r[0], y = osas - r[0];
  for (int i = 1; i < n; ++i) {
    if (i % 2 == 0) {
      right[i] = min(y - right[i - 1], r[i]);
      left[i] = r[i] - right[i];
    } else {
      left[i] = min(x - left[i - 1], r[i]);
      right[i] = r[i] - left[i];
    }
  }
  return left[n - 1] == 0;
}
