#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
int T, N, ans, cnt[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> N;
    memset(cnt, 0, sizeof(cnt));
    ans = 0;
    for (int i = 1; i <= N; ++i) {
      if (N / i - 1 > cnt[i]) for (int j = i; j <= N; j += i) cnt[j]++;
      else ans += cnt[i];
    }
    cout << ans << '\n';
  }
  return 0;
}
