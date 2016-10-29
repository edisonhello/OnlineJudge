#include <iostream>
#include <cstring>
using namespace std;

int M, N, A[105], dp[50005], sm;

int main() {
  cin >> M >> N;
  while (M--) {
    sm = 0;
    for (int i = 0; i < N; ++i) cin >> A[i], sm += A[i];
    if (sm % 2) { cout << "No\n"; continue; }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
      for (int j = sm / 2; j >= A[i]; --j) {
        dp[j] += dp[j - A[i]];
      }
    }
    if (dp[sm / 2]) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}
