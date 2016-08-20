#include <iostream>
#include <algorithm>
using namespace std;

long long int absolute(long long int x) {
  return x > 0 ? x : -x;
}

int main() {
  int n, len;
  long long int dp[1000];
  long long int dis[1000];
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> len;
    for (int j = 0; j < len; ++j) {
      cin >> dis[j];
    }
    dp[0] = 0;
    dp[1] = dis[1] - dis[0];
    for (int j = 2; j < len; ++j) {
      dp[j] = min(dp[j - 1] + absolute(dis[j] - dis[j - 1]), dp[j - 2] + absolute(dis[j] - dis[j - 2]));
    }
    cout << dp[len - 1] << endl;
  }
  return 0;
}
