#include <bits/stdc++.h>
using namespace std;

const int maxn = 30000 + 5;
int n, x;
long long ans;
int sieve[maxn];
unordered_map<int, int> n_fac;
void Sieve();
unordered_map<int, int> fac(int);
void solve(const unordered_map<int, int>&, long long, unordered_map<int, int>::iterator);
long long power(long long, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  Sieve();
  cin >> n;
  n_fac = fac(n);
  for (x = n + 1; x <= 3 * n; ++x) {
    unordered_map<int, int> m = fac(x);
    for (auto i : n_fac) m[i.first] += i.second;
    for (auto &i : m) i.second *= 2;
    solve(m, 1LL, m.begin());
  }
  cout << ans << '\n';
  return 0;
}

void Sieve() {
  vector<int> prime;
  for (int i = 2; i < maxn; ++i) {
    if (!sieve[i]) prime.push_back(i), sieve[i] = i;
    for (int j = 0; i * prime[j] < maxn && j < prime.size(); ++j) {
      sieve[i * prime[j]] = min(i, prime[j]);
      if (i % prime[j] == 0) break;
    }
  }
}

unordered_map<int, int> fac(int x) {
  unordered_map<int, int> ret;
  while (x != 1) {
    ret[sieve[x]]++;
    x /= sieve[x];
  }
  return ret;
}

void solve(const unordered_map<int, int>& m, long long val, unordered_map<int, int>::iterator it) {
  if (it == m.end()) {
    long long a = val, b = (long long)x * (long long)x * (long long)n * (long long)n / val;
    if ((a + (long long)x * (long long)n) % (long long)(x - n)) return;
    if ((b + (long long)x * (long long)n) % (long long)(x - n)) return;
    long long y = (a + (long long)x * (long long)n) / (long long)(x - n), z = (b + (long long)x * (long long)n) / (long long)(x - n);
    if (y >= x && z >= y) ans += x + y;
    return;
  }
  for (int i = 0; i <= it->second; ++i) {
    unordered_map<int, int>::iterator j = it; ++j;
    solve(m, val * power(it->first, i), j);
  }
}

long long power(long long a, int n) {
  long long ret = 1LL;
  for (; n; n >>= 1) {
    if (n & 1LL) ret *= a;
    a *= a;
  }
  return ret;
}
