#include <bits/stdc++.h>
using namespace std;

const int maxn = 20000 + 5, maxv = 100000 + 5;
int T, N, v[maxn], c[maxn];

struct BIT {
  int bit[maxv];
  void init() {
    memset(bit, 0, sizeof(bit));
  }
  #define lowbit(x) (x & -x)
  void add(int x, int v) {
    for (int i = x; i < maxv; i += lowbit(i)) bit[i] += v;
  }
  int sum(int x) {
    int ret = 0;
    for (int i = x; i; i -= lowbit(i)) ret += bit[i];
    return ret;
  }
  #undef lowbit
} bit;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T; while (T--) {
    bit.init();
    cin >> N;
    int Max = 0;
    for (int i = 1; i <= N; ++i) cin >> v[i], Max = max(Max, v[i]);
    long long ans = 0;
    for (int i = 1; i <= N; ++i) {
      c[i] = bit.sum(v[i] - 1);
      bit.add(v[i], 1);
    }
    cout << ans << '\n';
  }
  return 0;
}
