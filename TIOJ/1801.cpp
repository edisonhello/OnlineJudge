#include <bits/stdc++.h>
using namespace std;

int f[2], T, N, K, cur, kase;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> N >> K; cur = 0;
    f[cur] = 0;
    for (int i = 2; i <= N; ++i) f[cur ^ 1] = (f[cur] + K) % i, cur ^= 1;
    cout << "Case " << ++kase << ": " << f[cur] + 1 << '\n';
  }
  return 0;
}
