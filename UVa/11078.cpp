#include <bits/stdc++.h>
using namespace std;

int T, N, Max, ans, x;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T;
  while (T--) {
    Max = -(1<<20); ans = INT_MIN;
    cin >> N;
    for (int i = 0; i < N; ++i) {
      cin >> x;
      ans = max(ans, Max - x);
      Max = max(Max, x);
    }
    cout << ans << '\n';
  }
  return 0;
}
