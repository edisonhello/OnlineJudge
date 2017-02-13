#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000000 + 5;
int N, Q, n, sieve[maxn];
long long ans;

void Sieve();

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> Q;
  Sieve();
  while (Q--) {
    ans = 0;
    cin >> n;
    for (int i = 1; i < n; i = n / (n / (i + 1))) ans = max({ ans, n / i + (1LL << (4 * sieve[i])), i + (1LL << (4 * sieve[n / i])) });
    ans = max(ans, 1 + (1LL << (4 * sieve[n])));
    cout << ans << '\n';
  }
  return 0;
}

void Sieve() {
  for (int i = 2; i <= N; ++i) {
    if (sieve[i]) continue;
    for (int j = i; j <= N; j += i) sieve[j]++;
  }
}
