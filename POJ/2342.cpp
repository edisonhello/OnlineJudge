#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 6000 + 5;
int N, a[maxn], L, K, rt, _dp[2][maxn];
vector<int> G[maxn];
bool root[maxn];

void dp(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> a[i];
  memset(root, true, sizeof(root));
  while (cin >> L >> K, L || K) {
    G[K].push_back(L);
    root[L] = false;
  }
  for (int i = 1; i <= N; ++i) if (root[i]) rt = i;
  dp(rt, -1);
  cout << max(_dp[0][rt], _dp[1][rt]) << '\n';
  return 0;
}

void dp(int x, int fa) {
  _dp[0][x] = a[x];
  _dp[1][x] = 0;
  for (int i = 0; i < G[x].size(); ++i) if (G[x][i] != fa) {
    int u = G[x][i];
    dp(u, x);
    _dp[0][x] = max(_dp[0][x], _dp[0][x] + _dp[1][u]);
    _dp[1][x] = max(_dp[1][x], max(_dp[1][x] + _dp[0][u], _dp[1][x] + _dp[1][u]));
  }
}
