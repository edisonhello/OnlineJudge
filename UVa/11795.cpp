#include <bits/stdc++.h>
using namespace std;

const int maxn = 16;
int T, n, w[maxn], kase;
long long _dp[1 << maxn];

long long dp(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    cin >> n;
    memset(_dp, -1, sizeof(_dp)); memset(w, 0, sizeof(w));
    string s; cin >> s;
    int init = 0;
    for (int i = 0; i < s.length(); ++i) if (s[i] == '1') init += (1 << i);
    for (int i = 0; i < n; ++i) {
      cin >> s;
      for (int j = 0; j < s.length(); ++j) if (s[j] == '1') w[i] += (1 << j);
    }
    cout << "Case " << ++kase << ": " << dp((1 << n) - 1, init) << '\n';
  }
  return 0;
}

long long dp(int s, int t) {
  if (s == 0) return 1LL;
  if (_dp[s] != -1) return _dp[s];
  _dp[s] = 0;
  for (int i = 0; i < n; ++i) if (s & (1 << i)) {
    if (t & (1 << i)) _dp[s] += dp(s ^ (1 << i), t | w[i]);
  }
  return _dp[s];
}
