#include <iostream>
#include <algorithm>

int c[100005], N, Q, sa[100005], t[2][100005], r[100005], k, h[100005], st[20][100005], L, R;

signed main() {
  std::cin.tie(0); std::ios_base::sync_with_stdio(false);
  std::cin >> N >> Q;
  for (int i = 0; i < N; ++i) std::cin >> c[i];
  int *x = t[0], *y = t[1];
  for (int i = 0; i < N; ++i) sa[i] = i, x[i] = c[i];
  for (int m = 2; m <= N; m <<= 1) {
    auto cmp = [x, m](const int& i, const int& j) -> bool {
      if (x[i] != x[j]) return x[i] < x[j];
      return (i + m / 2 < N ? x[i + m / 2] : -1) < (j + m / 2 < N ? x[j + m / 2] : -1);
    };
    std::sort(sa, sa + N, cmp);
    int R = 0;
    y[sa[0]] = R;
    for (int i = 1; i < N; ++i) {
      if (cmp(sa[i - 1], sa[i])) R++;
      y[sa[i]] = R;
    }
    std::swap(x, y);
    if (R == N - 1) break;
  }
  for (int i = 0; i < N; ++i) r[sa[i]] = i;
  for (int i = 0; i < N; ++i) {
    if (r[i] == 0) { h[0] = 0; continue; }
    if (k) k--;
    while (i + k < N && sa[r[i] - 1] + k < N && c[i + k] == c[sa[r[i] - 1] + k]) k++;
    h[r[i]] = k;
  }
  for (int i = 0; i < N; ++i) st[0][i] = h[i];
  for (int i = 1; (1<<i) <= N; ++i) {
    for (int j = 0; j + (1<<i) <= N; ++j) {
      st[i][j] = std::min(st[i - 1][j], st[i - 1][j + (1<<(i - 1))]);
    }
  }
  while (Q--) {
    std::cin >> L >> R;
    if (L == R) { std::cout << N - L << '\n'; continue; }
    if (r[L] < r[R]) L = r[L] + 1, R = r[R];
    else R = r[R] + 1, L = r[L];
    int d = std::abs(R - L) + 1;
    int p = 31 - __builtin_clz(d);
    std::cout << std::min(st[p][L], st[p][R - (1<<p) + 1]) << '\n';
  }
  return 0;
}
