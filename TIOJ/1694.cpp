#include <bits/stdc++.h>
using namespace std;

const int maxn = 23000 + 5, maxq = 2000000 + 5;

struct Query {
  int L, R, block, i;
  bool operator<(const Query& rhs) const {
    return block == rhs.block ? R < rhs.R : block < rhs.block;
  }
} q[maxq];

int N, Q, h[maxn], L, R, ans[maxq], inv;

struct BIT {
  #define lowbit(x) (x & -x)
  int bit[maxn];
  void init() {
    memset(bit, 0, sizeof(bit));
  }
  void add(int x, int v) {
    for (int i = x; i <= N; i += lowbit(i)) bit[i] += v;
  }
  int sum(int x) {
    int ret = 0;
    for (int i = x; i; i -= lowbit(i)) ret += bit[i];
    return ret;
  }
  #undef lowbit
} bit;

void addR(int);
void subR(int);
void addL(int);
void subL(int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> N >> Q;
  for (int i = 1; i <= N; ++i) cin >> h[i];
  int lim = (int)sqrt(N) + 1;
  for (int i = 0; i < Q; ++i) {
    cin >> q[i].L >> q[i].R;
    q[i].block = q[i].L / lim;
    q[i].i = i;
  }
  sort(q, q + Q);
  L = 1, R = 0;
  for (int i = 0; i < Q; ++i) {
    while (R < q[i].R) addR(++R);
    while (R > q[i].R) subR(R--);
    while (L > q[i].L) addL(--L);
    while (L < q[i].L) subL(L++);
    ans[q[i].i] = inv;
  }
  for (int i = 0; i < Q; ++i) cout << ans[i] << '\n';
  return 0;
}

void addR(int s) {
  inv += bit.sum(N) - bit.sum(h[s]);
  bit.add(h[s], 1);
}

void subR(int s) {
  inv -= bit.sum(N) - bit.sum(h[s]);
  bit.add(h[s], -1);
}

void addL(int s) {
  inv += bit.sum(h[s] - 1);
  bit.add(h[s], 1);
}

void subL(int s) {
  inv -= bit.sum(h[s] - 1);
  bit.add(h[s], -1);
}
