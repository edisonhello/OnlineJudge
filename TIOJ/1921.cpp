#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;

struct Mac {
  int G, D, P, R;
  bool operator<(const Mac& rhs) const {
    return D < rhs.D;
  }
} mac[maxn];

long long dp[maxn];
int N, C, D;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> C >> D;
  for (int i = 1; i <= N; ++i) cin >> mac[i].D >> mac[i].P >> mac[i].R >> mac[i].G;
  sort(mac + 1, mac + N + 1);
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j < i; ++j) if (dp[j] + mac[j].G * (mac[i].D - mac[j].D) >= mac[i].P) {
      dp[i] = max(dp[i], dp[j] + mac[j].G * (mac[i].D - mac[j].D) - mac[i].P + mac[i].R);
    }
  }
  cout << dp[N] << '\n';
  return 0;
}
