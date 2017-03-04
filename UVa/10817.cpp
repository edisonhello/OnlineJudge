#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5, maxs = 8, INF = 100000000;
int s, m, n, _dp[maxn][1 << (maxs << 1)], c[maxn], t[maxn];

int dp(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while (cin >> s >> m >> n, s) {
    string _; getline(cin, _);
    memset(_dp, -1, sizeof(_dp));
    memset(t, 0, sizeof(t));
    int tot = 0, init = 0;
    for (int i = 0; i < m; ++i) {
      int osas, cost;
      string s; getline(cin, s); stringstream ss(s);
      ss >> cost; tot += cost;
      while (ss >> osas) {
        --osas;
        if (init & (1 << (2 * osas))) init |= (1 << (2 * osas + 1));
        else init |= (1 << (2 * osas));
      }
    }
    for (int i = 0; i < n; ++i) {
      int osas;
      string s; getline(cin, s); stringstream ss(s);
      ss >> c[i];
      while (ss >> osas) t[i] += (1 << (osas - 1));
    }
    cout << tot + dp(n - 1, init) << '\n';
  }
  return 0;
}

int dp(int n, int st) {
  if (st == ((1 << (s * 2)) - 1)) return 0;
  if (n < 0) return INF;
  if (_dp[n][st] != -1) return _dp[n][st];
  _dp[n][st] = dp(n - 1, st);
  int ns = st;
  for (int i = 0; i < s; ++i) if (t[n] & (1 << i)) {
    if (ns & (1 << (2 * i)) && ns & (1 << (2 * i + 1))) continue;
    if (ns & (1 << (2 * i))) ns |= (1 << (2 * i + 1));
    else ns |= (1 << (2 * i));
  }
  _dp[n][st] = min(_dp[n][st], dp(n - 1, ns) + c[n]);
  return _dp[n][st];
}
