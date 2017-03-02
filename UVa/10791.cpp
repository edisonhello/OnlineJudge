#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 50000 + 5;
vector<int> prime;
int n, kase;

void sieve();

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  while (cin >> n, n) {
    int i = 0, sum = 0, nn = n;
    if (n == 1) { cout << "Case " << ++kase << ": " << 2 << '\n'; continue; }
    while (i < prime.size() && n > 1) {
      int osas = 1;
      while (n % prime[i] == 0) n /= prime[i], osas *= prime[i];
      if (osas != 1) sum += osas;
      ++i;
    }
    if (n > 1) sum += n;
    if (sum == nn) sum++;
    cout << "Case " << ++kase << ": " << sum << '\n';
  }
  return 0;
}

void sieve() {
  bool v[maxn]; memset(v, false, sizeof(v));
  for (int i = 2; i < maxn; ++i) {
    if (!v[i]) prime.push_back(i);
    for (int j = 0; i * prime[j] < maxn; ++j) {
      v[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}
