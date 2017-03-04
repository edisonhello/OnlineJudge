#include <bits/stdc++.h>
using namespace std;

const int maxn = 20 + 5;
int a, b, c, T;
long long s[maxn][maxn][maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    cin >> a >> b >> c;
    for (int i = 1; i <= a; ++i) for (int j = 1; j <= b; ++j) for (int k = 1; k <= c; ++k) {
      long long x; cin >> x;
      s[i][j][k] = s[i - 1][j][k] + s[i][j - 1][k] + s[i][j][k - 1] + x;
      s[i][j][k] -= s[i - 1][j - 1][k] + s[i - 1][j][k - 1] + s[i][j - 1][k - 1];
      s[i][j][k] += s[i - 1][j - 1][k - 1];
    }
    long long ans = LLONG_MIN;
    for (int low = 1; low <= a; ++low) for (int high = low; high <= a; ++high) {
      for (int left = 1; left <= b; ++left) for (int right = left; right <= b; ++right) {
        for (int i = 1; i <= c; ++i) for (int j = i; j <= c; ++j) {
          long long v = s[high][right][j] - s[low - 1][right][j] - s[high][left - 1][j] - s[high][right][i - 1];
          v += s[low - 1][left - 1][j] + s[low - 1][right][i - 1] + s[high][left - 1][i - 1];
          v -= s[low - 1][left - 1][i - 1];
          ans = max(ans, v);
        }
      }
    }
    cout << ans << '\n';
    if (T) cout << '\n';
  }
  return 0;
}
