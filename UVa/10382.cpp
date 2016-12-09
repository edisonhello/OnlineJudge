#include <iostream>
#include <algorithm>
using namespace std;

struct Circle {
  int pos, r;
  bool operator<(const Circle& res) const {
    int a, b;
    if (pos - r >= 0) a += r; else a += pos;
    if (pos + r <= L) a += r; else a += L - pos;
    if (res.pos - r >= 0) b += res.r; else b += res.pos;
    if (res.pos + r <= L) b += res.r; else b += L - res.pos;
    return a > b;
  }
} c[10005];

int N, L, W, l, r, ans;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> N >> L >> W) {
    for (int i = 0; i < N; ++i) cin >> c[i].pos >> c[i].r;
    sort(c, c + N);
    l = L; r = 0;
    for (int i = 0; i < N; ++i) {
      if (c[i].pos + )
    }
  }
}
