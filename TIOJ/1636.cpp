#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1000000 + 5;
int A[maxn], N, K, tot, ans;

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N >> K;
  for (int i = 1; i <= N; ++i) cin >> A[i];
  for (int i = 1; i <= N && K + 1 >= i; ++i) {
    tot += A[i];
    if (i == 1) { ans = A[i]; continue; }
    ans = max(ans, tot + (K - i + 1) / 2 * A[i] + (K - i + 2) / 2 * A[i + 1]);
  }
  if (N == 1) cout << (K + 1) / 2 * A[1] << '\n';
  else cout << ans << '\n';
  return 0;
}
