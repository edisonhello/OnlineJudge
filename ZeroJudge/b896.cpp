#include <bits/stdc++.h>
using namespace std;

int n, m, cnt[2][100001 + 5], a, b, ans;
long long tot;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> n >> m;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; ++i) cin >> a, cnt[0][a]++;
  for (int i = 0; i < m; ++i) cin >> b, cnt[1][b]++;
  int i = 0, j = 0;
  while (i <= 100001 && j <= 100001) {
    while (!cnt[0][i] && i <= 100001) ++i;
    while (!cnt[1][j] && j <= 100001) ++j;
    if (i > 100001 || j > 100001) break;
    if (i >= j) tot += i, --cnt[0][i], --cnt[1][j], ++ans;
    else --cnt[0][i];
  }
  if (ans == m) cout << "YES " << tot << '\n';
  else cout << "NO " << m - ans << '\n';
  return 0;
}
