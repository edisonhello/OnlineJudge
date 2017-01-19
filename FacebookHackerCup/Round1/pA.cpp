#include <bits/stdc++.h>
using namespace std;

const int maxn = 300 + 5;
long long dp[maxn][maxn], S[maxn][maxn];
int T, N, M, c[maxn][maxn], kase;
bool v[maxn][maxn];

inline long long cost(int i, int j) { return j == 0 ? 0 : S[i][j - 1] + j * j; }

long long DP(int, int);

int main() {
  freopen("pie_progress.txt", "r", stdin);
  freopen("pAout.txt", "w", stdout);
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> N >> M;
    memset(S, 0, sizeof(S));
    memset(v, false, sizeof(v));
    memset(c, 0, sizeof(c));
    for (int i = 0; i < maxn; ++i) fill(dp[i], dp[i] + maxn, LLONG_MAX);
    for (int i = 1; i <= N; ++i) for (int j = 0; j < M; ++j) cin >> c[i][j];
    for (int i = 1; i <= N; ++i) sort(c[i], c[i] + M);
    for (int i = 1; i <= N; ++i) for (int j = 0; j < M; ++j) S[i][j] = S[i][j - 1] + c[i][j];
    cout << "Case #" << ++kase << ": " << DP(N, N) << '\n';
  }
  return 0;
}

long long DP(int i, int j) {
  if (i == 1) return j <= M ? cost(i, j) : (1LL << 40);
  if (v[i][j]) return dp[i][j];
  for (int k = j; k >= i - 1 && j - k <= M; --k) dp[i][j] = min(dp[i][j], DP(i - 1, k) + cost(i, j - k));
  v[i][j] = true;
  return dp[i][j];
}
