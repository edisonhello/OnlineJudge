#include <iostream>
#include <algorithm>
#define INF (1<<30)
using namespace std;

int f[27], N, K, dp[1<<30];

void fib() {
  f[1] = 1;
  f[2] = 1;
  for (int i = 3; i <= 26; ++i) f[i] = f[i - 2] + f[i - 1];
}

void dpdp() {
  for (int i = 0; i <= 1<<30; ++i) dp[i] = INF;
  dp[0] = 0;
  for (int i = 1; i <= 26; ++i) {
    for (int j = 1<<30; j >= f[i]; --j) {
      dp[j] = min(dp[j], dp[j - f[i]] + 1);
    }
  }
}

int main() {
  fib(); dpdp();
  // for (int i = 1; i <= 26; ++i) cout << i << ": " << f[i] << endl;
  cin >> N;
  while (N--) {
    cin >> K;
    cout << dp[K] << endl;
  }
  return 0;
}
