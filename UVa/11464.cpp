#include <bits/stdc++.h>
using namespace std;

const int maxn = 15 + 5;
int T, n, a[maxn][maxn], b[maxn][maxn], kase;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) cin >> a[i][j];
    int ans = INT_MAX;
    memset(b, 0, sizeof(b));
    for (int one = 0; one <= n; ++one) {
      int c[maxn];
      for (int i = 1; i <= n - one; ++i) c[i] = 0;
      for (int i = n - one + 1; i <= n; ++i) c[i] = 1;
      do {
        for (int i = 1; i <= n; ++i) b[1][i] = c[i];
        for (int i = 1; i <= n; ++i) {
          for (int j = 1; j <= n; ++j) {
            if ((b[i - 1][j] + b[i][j - 1] + b[i][j + 1]) & 1) b[i + 1][j] = 1;
            else b[i + 1][j] = 0;
          }
        }
        bool pos = true;
        int chg = 0;
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
          if (a[i][j] == 0 && b[i][j] == 1) ++chg;
          if (a[i][j] == 1 && b[i][j] == 0) pos = false;
        }
        if (pos) ans = min(ans, chg);
      } while (next_permutation(c + 1, c + n + 1));
    }
    if (ans == INT_MAX) ans = -1;
    cout << "Case " << ++kase << ": " << ans << '\n';
  }
  return 0;
}
