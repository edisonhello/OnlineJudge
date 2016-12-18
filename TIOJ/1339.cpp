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
  cout << dq(0, N) % MOD << '\n';
  return 0;
}

int dq(int L, int R) {
  if (L == R - 1) { /*cout << "L: " << L << " R: " << R << " ret: "; cout << "0\n"; */return 0; }
  int M = (L + R) >> 1;
  int ans1 = dq(L, M) % MOD, ans2 = dq(M, R) % MOD;
  auto cmp = [](const D& a, const D& b) -> bool {
    return a.w < b.w;
  };
  sort(d + L, d + M, cmp); sort(d + M, d + R, cmp);
  // cout << "left: ";
  // for (int i = L; i < M; ++i) cout << d[i].w << ' ' << d[i].h << '\n';
  // cout << "right: ";
  // for (int i = M; i < R; ++i) cout << d[i].w << ' ' << d[i].h << '\n';
  int ans = 0, prefix = 0, len = 0;;
  int i = L, j = M;
  while (i < M && j < R) {
    // cout << "i: " << i << " j: " << j << '\n';
    // cout << "d[i]: " << d[i].w << ' ' << d[i].h << '\n';
    if (d[i].w <= d[j].w) {}
    else {
      ans += (len * d[j].w * d[j].h - prefix);
      ans %= MOD;
      j++;
    }
    prefix += (d[i].w * d[i].h); len++; i++;
    prefix %= MOD;
  }
  // cout << "prefix: " << prefix << '\n';
  while (j < R) {
    ans += (len * d[j].w * d[j].h - prefix);
    ans %= MOD;
    j++;
  }
  int ret = (ans + ans1 + ans2) % MOD;
  // cout << "L: " << L << " R: " << R << " ret: ";
  // cout << ret << '\n';
  return ret;
}
