#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int n, m, a[maxn], pos[maxn];

struct Seg {
  int cnt;
  Seg *lc, *rc;
  Seg(): cnt(0), lc(NULL), rc(NULL) {}
  Seg(int L, int R) {
    if (L == R) { cnt = 0; return; }
    int M = (L + R) >> 1;
    lc = new Seg(L, M); rc = new Seg(M + 1, R);
    pull();
  }
  Seg(Seg* t) {
    cnt = t->cnt;
    lc = t->lc;
    rc = t->rc;
  }
  void pull() {
    cnt = 0;
    if (lc) cnt += lc->cnt;
    if (rc) cnt += rc->cnt;
  }
  Seg* modify(int L, int R, int x, int v) {
    Seg* ret = new Seg(this);
    if (L == R) { ret->cnt += v; return ret; }
    int M = (L + R) >> 1;
    if (x <= M) ret->lc = lc->modify(L, M, x, v);
    else ret->rc = rc->modify(M + 1, R, x, v);
    ret->pull();
    return ret;
  }
  int query(int L, int R, int l, int r) {
    if (L > r || l > R) return 0;
    if (L >= l && R <= r) return cnt;
    int M = (L + R) >> 1;
    return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
  }
};

struct BIT {
  #define lowbit(x) (x & -x)
  Seg *seg[maxn];
  void init() {
    seg[0] = new Seg(1, n);
    for (int i = 1; i <= n; ++i) seg[i] = seg[0];
  }
  void add(int id, int x, int v) {
    for (int i = id; i <= n; i += lowbit(i)) seg[i] = seg[i]->modify(1, n, x, v);
  }
  vector<Seg*> sum(int id) {
    vector<Seg*> ret;
    ret.push_back(new Seg(1, n));
    for (int i = id; i; i -= lowbit(i)) ret.push_back(seg[i]);
    return ret;
  }
  #undef lowbit
} bit;

int Inverse();

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i], pos[a[i]] = i;
  bit.init();
  for (int i = 1; i <= n; ++i) bit.add(i, a[i], 1);
  int inv = Inverse();
  while (m--) {
    cout << inv << '\n';
    int d, ans = 0; cin >> d;
    vector<Seg*> res1 = bit.sum(pos[d]), res2 = bit.sum(n);
    for (int i = 0; i < res1.size(); ++i) ans += res1[i]->query(1, n, d + 1, n);
    for (int i = 0; i < res2.size(); ++i) ans += res2[i]->query(1, n, 1, d - 1);
    for (int i = 0; i < res1.size(); ++i) ans -= res1[i]->query(1, n, 1, d - 1);
    inv -= ans;
    bit.add(pos[d], d, -1);
  }
  return 0;
}

int fenwick[maxn];

void add(int x, int v) {
  for (int i = x; i <= n; i += (i & -i)) fenwick[i] += v;
}

int sum(int x) {
  int ret = 0;
  for (int i = x; i; i -= (i & -i)) ret += fenwick[i];
  return ret;
}

int Inverse() {
  int ret = 0;
  memset(fenwick, 0, sizeof(fenwick));
  for (int i = 1; i <= n; ++i) {
    ret += i - 1 - sum(a[i]);
    add(a[i], 1);
  }
  return ret;
}
