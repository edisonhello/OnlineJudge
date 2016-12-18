#include <iostream>
#include <algorithm>
using namespace std;


const int MAX = 100000 + 5;
int N, C, D, dp[MAX];

struct S {
  int D, P, R, G;
  bool operator<(const S& rhs) const {
    return D < rhs.D;
  }
} s[MAX];

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N >> C >> D;
  for (int i = 1; i <= N; ++i) cin >> s[i].D >> s[i].P >> s[i].R >> s[i].G;
  sort(s, s + N);
  dp[0] = C;
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j < i; ++j) {
      if (dp[j] >= s[j].P) dp[i] = max(dp[i], s[j].G * (s[i].D - s[j].D - 1) + s[j].R - s[j].P + dp[j]);
      cout << "dp[" << i << "] at j = " << j << " --> " << dp[i] << '\n';
    }
  }
  cout << dp[N] << '\n';
  return 0;
}
