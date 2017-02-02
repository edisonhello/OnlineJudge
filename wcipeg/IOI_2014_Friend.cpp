#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int dp[2][maxn], N, _con[maxn], _hos[maxn], _pro[maxn];

int findSample(int n, int confidence[], int host[], int protocal[]) {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; ++i) dp[0][i] = confidence[i];
  for (int i = n - 1; i > 0; --i) {
    int fa = host[i];
    if (protocal[i] == 0) {
      dp[0][fa] += dp[1][i];
      dp[1][fa] += max(dp[0][i], dp[1][i]);
    }
    if (protocal[i] == 1) {
      dp[0][fa] = max(dp[0][fa] + max(dp[0][i], dp[1][i]), dp[1][fa] + dp[0][i]);
      dp[1][fa] += dp[1][i];
    }
    if (protocal[i] == 2) {
      dp[0][fa] = max(dp[0][fa] + dp[1][i], dp[1][fa] + dp[0][i]);
      dp[1][fa] += dp[1][i];
    }
  }
  return max(dp[0][0], dp[1][0]);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> _con[i];
  for (int i = 1; i < N; ++i) cin >> _hos[i] >> _pro[i];
  cout << findSample(N, _con, _hos, _pro) << '\n';
  return 0;
}
