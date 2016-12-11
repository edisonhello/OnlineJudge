#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

struct D {
  int w, h;
} d[1000005];

const int MOD = 1000000009;
int N;
int dq(int, int);

signed main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> d[i].w >> d[i].h;
  sort(d, d + N, [](const D& a, const D& b) -> bool {
    return a.h < b.h;
  });
  cout << dq(0, N) << '\n';
  return 0;
}

int dq(int L, int R) {
  if (L == R - 1) return 0;
  int M = (L + R) >> 1;
  int ans1 = dq(L, M) % MOD, ans2 = dq(M, R) % MOD;
  auto cmp = [](const D& a, const D& b) -> bool {
    return a.w < b.w;
  };
  sort(d + L, d + M, cmp); sort(d + M, d + R, cmp);
  int ans = 0, prefix = 0, len = 0;;
  for (int i = L, j = M; i < M && j < R; ++i) {
    if (d[j].w < d[i].w) ans += len * d[j].w * d[j].h - prefix, ans %= MOD, ++j;
    len++;
    prefix += d[i].w * d[i].h; prefix %= MOD;
  }
  return (ans + ans1 + ans2) % MOD;
}
