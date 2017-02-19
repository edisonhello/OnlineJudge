#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int n, m, a[maxn], ans;

bool check(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> n >> m) {
    ans = 0;
    for (int i = 0; i < n; ++i) cin >> a[i], ans += a[i];
    int d = 1;
    while (d <= ans) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    cout << ans << '\n';
  }
  return 0;
}

bool check(int cap) {
  int con = 0, cur = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > cap) return false;
    cur += a[i];
    if (cur > cap) ++con, cur = a[i];
  }
  if (cur) ++con;
  return con <= m;
}
