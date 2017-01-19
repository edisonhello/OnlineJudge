#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
const int K = 50;
int T, N, W[maxn], f, ans, kase;

int main() {
  freopen("lazy_loading.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> W[i];
    sort(W, W + N);
    f = 0;
    ans = 0;
    for (int i = N - 1; i >= f; --i) {
      int num = ceil((double)K / (double)W[i]) - 1;
      if (num < 0) num = 0;
      f += num;
      if (f > i) continue;
      ans++;
    }
    cout << "Case #" << ++kase << ": " << ans << '\n';
  }
  return 0;
}
