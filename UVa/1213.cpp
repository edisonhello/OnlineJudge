#include <bits/stdc++.h>
using namespace std;

const int maxn = 1200, maxk = 20, maxm = 200;
int n, k, _dp[maxk][maxm][maxn];
vector<int> prime;

void sieve();
int dp(int, int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  while (cin >> n >> k, (n || k)) {
    memset(_dp, -1, sizeof(_dp));
    cout << dp(k, prime.size(), n) << '\n';
  }
  return 0;
}

void sieve() {
  bool v[maxn];
  memset(v, false, sizeof(v));
  for (int i = 2; i < maxn; ++i) {
    if (!v[i]) prime.push_back(i);
    for (int j = 0; prime[j] * i < maxn; ++j) {
      v[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}

int dp(int os, int as, int hao) {
  if (hao < 0) return 0;
  if (os == 0) return hao == 0;
  if (as == 0) return 0;
  if (_dp[os][as][hao] != -1) return _dp[os][as][hao];
  return _dp[os][as][hao] = dp(os - 1, as - 1, hao - prime[as - 1]) + dp(os, as - 1, hao);
}
