#include <iostream>
#include <algorithm>
#define INF 1000000
using namespace std;

int dp[20010][100], L;
int dpdp(int, int);

int main() {
  for (int i = 0; i < 20010; ++i) for (int j = 0; j < 100; ++j) dp[i][j] = INF;
  while (cin >> L) {
    cout << dpdp(L, 1) << endl;
  }
}

int dpdp(int len, int step) {
  if (len == step) return dp[len][step] = 1;
  if (dp[len][step] < INF) return dp[len][step];
  int mn = INF;
  if (len - step >= 0) mn = min(mn, dpdp(len - step, step + 1) + 1);
  if (step - 1 > 0) mn = min(mn, dpdp(len - step, step - 1) + 1);
  // cout << min(mn, dp[len][step]) << endl;;
  return dp[len][step] = min(mn, dp[len][step]);
}
