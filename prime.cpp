#include <iostream>
#include <bitset>
using namespace std;

bitset<10010> prime;

void build() {
  prime.set();
  prime[1] = false;
  for (int i = 2; i <= 10000; ++i) {
    if (prime[i]) {
      for (int j = i * i; j <= 10000; j += i) prime[j] = false;
    }
  }
}

int n, m;
int dp[10010];
bool p;

void dpdp() {
  dp[1] = 0;
  dp[2] = 2;
  dp[3] = 3;
  for (int i = 3; i <= 10000; ++i) {
    p = true;
    for (int j = i - 1; j > i / 2; --j) {
      if (i != i - j && prime[j] && (dp[i - j] || prime[i - j])) {dp[i] = j; p = false; break;}
    }
    if (p) {
      if (!prime[i]) dp[i] = 0;
      else prime[i] = i;
    }
  }
}

void solve(int m) {
  while (dp[m] > 0 && dp[m] != m) {
    cout << dp[m] << ' ';
    m -= dp[m];
  }
  cout << dp[m] << endl;
}

int main() {
  build();
  dpdp();
  // for (int i = 0; i <= 10000; ++i) cout << dp[i] << ' ';
  cin >> n;
  while (n--) {
    cin >> m;
    if (!prime[m]) cout << 0 << endl;
    else {
      // cout << m << ": " << dp[m] << endl;
      solve(m);
    }
  }
  return 0;
}
