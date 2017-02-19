#include <iostream>
#include <vector>
using namespace std;

const int maxn = 20 + 5, maxm = 20;
int dp[maxn][1 << maxm], N, M;
bool v[maxn][1 << maxm];
vector<int> p[maxn];

int DP(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    int x, P; cin >> P;
    while (P--) cin >> x, --x, p[i].push_back(x);
  }
  cout << DP(N, (1 << M) - 1) << '\n';
}

int DP(int n, int s) {
  if (v[n][s]) return dp[n][s];
  dp[n][s] = 0;
  if (n == 1) {
    for (int i = 0; i < p[n].size(); ++i) if (s & (1 << p[n][i])) ++dp[n][s];
    return dp[n][s];
  }
  for (int i = 0; i < p[n].size(); ++i) if (s & (1 << p[n][i])) {
    dp[n][s] += DP(n - 1, s ^ (1 << p[n][i]));
  }
  v[n][s] = true;
  return dp[n][s];
}
