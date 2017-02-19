#include <bits/stdc++.h>
using namespace std;

const int maxn = 15;
int _dp[maxn][1 << maxn], T, adj[maxn][maxn], n;
bool v[maxn][1 << maxn];
struct Point { int x, y; } p[maxn];

int dp(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T;
  while (T--) {
    int ind = 0;
    int _, __; cin >> _ >> __;
    int x, y; cin >> p[0].x >> p[0].y;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i].x >> p[i].y;
    for (int i = 0; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        adj[i][j] = adj[j][i] = abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y);
      }
    }
    memset(_dp, 0, sizeof(_dp));
    memset(v, false, sizeof(v));
    cout << "The shortest path has length " << dp(0, (1 << (n + 1)) - 1) << '\n';
  }
  return 0;
}

int dp(int x, int s) {
  if (s == 0) return adj[x][0];
  if (v[x][s]) return _dp[x][s];
  _dp[x][s] = INT_MAX;
  for (int i = 0; i <= n; ++i) if (s & (1 << i)) {
    _dp[x][s] = min(_dp[x][s], dp(i, s ^ (1 << i)) + adj[x][i]);
  }
  v[x][s] = true;
  return _dp[x][s];
}
