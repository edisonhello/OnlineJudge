#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5, lg = 20;
int a[maxn], b[maxn], n, sta[lg][maxn], stb[lg][maxn];

bool check(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  a[n] = 0;
  for (int i = 0; i < n; ++i) cin >> b[i];
  b[n] = INT_MAX;
  for (int i = 0; i <= n; ++i) sta[0][i] = a[i];
  for (int i = 1; (1 << i) <= n + 1; ++i) {
    for (int j = 0; j + (1 << i) <= n + 1; ++j) {
      sta[i][j] = max(sta[i - 1][j], sta[i - 1][j + (1 << (i - 1))]);
    }
  }
  for (int i = 0; i <= n; ++i) stb[0][i] = b[i];
  for (int i = 1; (1 << i) <= n + 1; ++i) {
    for (int j = 0; j + (1 << i) <= n + 1; ++j) {
      stb[i][j] = min(stb[i - 1][j], stb[i - 1][j + (1 << (i - 1))]);
    }
  }
  int ans = 0;
  for (int l = 0; l < n; ++l) {
    int d = 1, rmin = n - 1, rmax = 0;
    while (d < n) d <<= 1;
    while (d >>= 1) if (rmax + d < n) if (check(l, rmax + d)) rmax += d;
    d = 1;
    while (d < n) d <<= 1;
    while (d >>= 1) if (rmin - d >= 0) if (check(l, rmin - d)) rmin -= d;
    cout << "rmin: " << rmin << "  rmax: " << rmax << '\n';
    if (rmax >= rmin) ans += rmax - rmin + 1;
  }
  cout << ans << '\n';
  return 0;
}

bool check(int l, int r) {
  if (l > r) return false;
  cout << "l: " << l << "  r: " << r << '\n';
  int p = 31 - __builtin_clz(r - l + 1);
  int maxa = max(sta[p][l], sta[p][r - (1 << p) + 1]);
  int minb = min(stb[p][l], stb[p][r - (1 << p) + 1]);
  int osas = maxa - minb;
  cout << "osas: " << osas << ' ';
  ++r;
  p = 31 - __builtin_clz(r - l + 1);
  maxa = max(sta[p][l], sta[p][r - (1 << p) + 1]);
  minb = min(stb[p][l], stb[p][r - (1 << p) + 1]);
  cout << "osas: " << maxa - minb << '\n';
  return osas >= maxa - minb;
}
