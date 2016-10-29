#include <iostream>
#include <cstdio>
using namespace std;

int n;
long long dp[45], sm;
void init();

int main() {
  init();
  while (cin >> n) {
    cout << dp[n] << endl;
  }
  return 0;
}

void init() {
  dp[2] = 3; dp[3] = 4;
  for (int i = 4; i <= 41; ++i) {
    if (!(i & 1)) dp[i] = dp[i - 2] + dp[i - 1] * 2;
    else dp[i] = dp[i - 2] + dp[i - 1];
  }
}
