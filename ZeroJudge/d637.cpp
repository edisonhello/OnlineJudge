#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[10000];
int b[10000];
int dp[10000];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; ++i) {
    for (int j = 100; j >= a[i]; --j) {
      if (dp[j - a[i]] + b[i] > dp[j]) {
        dp[j] = dp[j - a[i]] + b[i];
      }
    }
  }
  cout << dp[100] << endl;
  return 0;
}
