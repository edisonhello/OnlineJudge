#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int a[maxn], n;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n, n) {
    for (int i = 0; i < n; ++i) cin >> a[i];
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += abs(a[i]);
      a[i + 1] += a[i];
    }
    cout << ans << '\n';
  }
  return 0;
}
