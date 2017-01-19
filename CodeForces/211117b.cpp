#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, a, b, ans;

signed main() {
  cin >> n;
  a = 1; b = 2;
  while (a + b < n) {
    int t = a + b;
    a = b; b = t;
    ans++;
  }
  if (n == 1) cout << 1 << '\n';
  else if (n == 2) cout << 2 << '\n';
  else cout << ans + 3 << '\n';
  return 0;
}
