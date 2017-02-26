#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int T, z[maxn << 1], _dp[maxn];
string s, t;

int dp(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    cin >> s;
    t = ".";
    for (int i = 0; i < s.length(); ++i) t += s[i], t += '.';
    memset(z, 0, sizeof(z));
    memset(_dp, -1, sizeof(_dp));
    int L = 0, R = 0;
    for (int i = 1; i < t.length(); ++i) {
      z[i] = (R > i) ? min(z[2 * L - i], R - i) : 1;
      while (i + z[i] < t.length() && i - z[i] >= 0 && t[i + z[i]] == t[i - z[i]]) ++z[i];
      if (i + z[i] > R) R = i + z[i], L = i;
    }
    cout << dp(s.length() - 1) << '\n';
  }
  return 0;
}

int dp(int n) {
  if (n < 0) return 0;
  if (_dp[n] != -1) return _dp[n];
  _dp[n] = s.length() + 1;
  for (int i = n; i >= 0; --i) {
    int pal = (z[i * 2 + 1] - 2) >> 1;
    if (i + pal >= n) _dp[n] = min(_dp[n], dp(i - (n - i) - 1) + 1);
    if (!i) continue;
    pal = (z[i * 2] - 1) >> 1;
    if (i + pal - 1 >= n) _dp[n] = min(_dp[n], dp(i - (n + 1 - i) - 1) + 1);
  }
  return _dp[n];
}
