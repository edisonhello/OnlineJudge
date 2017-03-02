#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 5;
int n;
vector<int> s, prime;
void sieve();

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  s.push_back(0);
  for (int i : prime) s.push_back(s.back() + i);
  while (cin >> n, n) {
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
      auto ind = lower_bound(s.begin(), s.end(), s[i] - n);
      if (s[i] - *ind == n) ++ans;
    }
    cout << ans << '\n';
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
