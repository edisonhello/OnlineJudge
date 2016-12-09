#include <iostream>
#include <algorithm>
#define int long long
#define abs(x) (x < 0) ? -(x) : (x)
int tot, N, m[1000005], c[1000005], mid, ans, avg;

signed main() {
  std::cin.tie(0); std::ios_base::sync_with_stdio(false);
  while (std::cin >> N) {
    tot = 0; ans = 0;
    for (int i = 0; i < N; ++i) std::cin >> m[i], tot += m[i];
    avg = tot / N;
    for (int i = 0; i < N; ++i) c[i] = c[i - 1] + m[i] - avg;
    std::nth_element(c, c + N / 2, c + N);
    mid = c[N / 2];
    for (int i = 0; i < N; ++i) ans += abs(c[i] - mid);
    std::cout << ans << '\n';
  }
  return 0;
}
