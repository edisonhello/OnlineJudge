#include <bits/stdc++.h>
using namespace std;

const int SQ = 1000000 + 5;
long long N, ans;
bool prime[SQ];

void sieve();

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  sieve();
  for (long long i = 2; i <= sqrt(N); ++i) {
    if (!prime[i]) continue;
    ans += N / (i * i);
  }
  cout << ans << '\n';
}

void sieve() {
  memset(prime, true, sizeof(prime));
  prime[1] = false;
  for (int i = 2; i <= sqrt(SQ); ++i) {
    if (prime[i]) for (int j = i * i; j <= SQ; j += i) prime[j] = false;
  }
}
