#include <bits/stdc++.h>
using namespace std;

const int maxn = 50000 + 5;
vector<int> prime;
int p;

void sieve();

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  while (cin >> p, p) {
    bool osas = p > 0;
    p = abs(p);
    int i = 0;
    int ans = 0;
    while (i < prime.size() && p > 1) {
      int power = 0;
      while (p % prime[i] == 0) ++power, p /= prime[i];
      if (power) ans = ans ? __gcd(ans, power) : power;
      ++i;
    }
    if (p > 1) ans = 1;
    if (!osas) while (ans % 2 == 0) ans /= 2;
    cout << ans << '\n';
  }
  return 0;
}

void sieve() {
  bool v[maxn];
  memset(v, false, sizeof(v));
  for (int i = 2; i < maxn; ++i) {
    if (!v[i]) prime.push_back(i);
    for (int j = 0; i * prime[j] < maxn; ++j) {
      v[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}
