#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 5, maxk = 100 + 5, MOD = (int)1e9 + 9;

struct S {
  long long a, b;
  double c;
} dp[maxk][maxn][maxn], jizz[maxn][maxn];

int N, K;
typedef double db;

long long GCD(long long a, long long b) {
  if (!a) return b;
  if (!b) return a;
  return __gcd(a, b);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
    cin >> jizz[i][j].a >> jizz[i][j].b;
    jizz[i][j].c = (db)jizz[i][j].a / (db)jizz[i][j].b;
  }
  cin >> K;
  dp[1][0][0] = jizz[0][0];
  for (int k = 1; k <= K; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (!dp[k][i][j].c) dp[k][i][j].c = -1;
        if (i + j < k) dp[k][i][j].c = -1000000;
        if (i) {
          if (dp[k][i - 1][j].c > dp[k][i][j].c) {
            dp[k][i][j] = dp[k][i - 1][j];
          }
          if (dp[k - 1][i - 1][j].c * jizz[i][j].c > dp[k][i][j].c) {
            dp[k][i][j].c = dp[k - 1][i - 1][j].c * jizz[i][j].c;
            dp[k][i][j].a = dp[k - 1][i - 1][j].a * jizz[i][j].a;
            dp[k][i][j].b = dp[k - 1][i - 1][j].b * jizz[i][j].b;
          }
        }
        if (j) {
          if (dp[k][i][j - 1].c > dp[k][i][j].c) {
            dp[k][i][j] = dp[k][i - 1][j];
          }
          if (dp[k - 1][i][j - 1].c * jizz[i][j].c > dp[k][i][j].c) {
            dp[k][i][j].c = dp[k - 1][i][j - 1].c * jizz[i][j].c;
            dp[k][i][j].a = dp[k - 1][i][j - 1].a * jizz[i][j].a;
            dp[k][i][j].b = dp[k - 1][i][j - 1].b * jizz[i][j].b;
          }
        }
        if (dp[k][i][j].c == -1000000) continue;
        long long d = GCD(dp[k][i][j].a, dp[k][i][j].b);
        dp[k][i][j].a /= d; dp[k][i][j].b /= d;
        cout << "k: " << k << " i: " << i << " j: " << j << ": ";
        cout << dp[k][i][j].a << ' ' << dp[k][i][j].b << '\n';
      }
    }
  }
  cout << dp[K][N - 1][N - 1].a % MOD << ' ' << dp[K][N - 1][N - 1].b % MOD << '\n';
  return 0;
}
