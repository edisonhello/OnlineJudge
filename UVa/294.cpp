#include <bits/stdc++.h>
using namespace std;

const int maxn = 40000 + 5;
int T;
vector<int> prime;

void sieve();
int fac(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  cin >> T; while (T--) {
    int L, U; cin >> L >> U;
    int Max = 0, ans = -1;
    for (int i = L; i <= U; ++i) {
      int ret = fac(i);
      if (ret > Max) Max = ret, ans = i;
    }
    cout << "Between " << L << " and " << U << ", " << ans << " has a maximum of " << Max << " divisors.\n";
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

int fac(int x) {
  int i = 0;
  vector<int> p;
  while (i < prime.size() && x > 1) {
    int ret = 0;
    while (x % prime[i] == 0) ++ret, x /= prime[i];
    p.push_back(ret);
    ++i;
  }
  int ans = 1;
  for (int i : p) ans *= (i + 1);
  return ans;
}
