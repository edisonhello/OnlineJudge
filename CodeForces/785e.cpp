#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
int n, m, a[maxn], pos[maxn];

struct Seg {
    int cnt;
    Seg *lc, *rc;
    Seg(): cnt(0), lc(NULL), rc(NULL) {}
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
} mem[45000000], *top;


Seg* modify(Seg* t, int L, int R, int x, int v) {
    Seg* ret = new(top++) Seg(t);
    if (L == R) { ret->cnt += v; return ret; }
    int M = (L + R) >> 1;
    if (x <= M) ret->lc = modify(t->lc, L, M, x, v);
    else ret->rc = modify(t->rc, M + 1, R, x, v);
    ret->pull();
    return ret;
}
int query(Seg* t, int L, int R, int l, int r) {
    if (L > r || l > R) return 0;
    if (L >= l && R <= r) return t->cnt;
    int M = (L + R) >> 1;
    return query(t->lc, L, M, l, r) + query(t->rc, M + 1, R, l, r);
}
void build(Seg*& t, int L, int R) {
    t = new(top++) Seg();
    t->cnt = 0;
    if (L == R) return;
    int M = (L + R) >> 1;
    build(t->lc, L, M); build(t->rc, M + 1, R);
}
struct BIT {
    #define lowbit(x) (x & -x)
    Seg* seg[maxn];
    void init() {
        build(seg[0], 1, n);
        for (int i = 1; i <= n; ++i) seg[i] = seg[0];
    }
    void add(int id, int x, int v) {
        for (int i = id; i <= n; i += lowbit(i)) seg[i] = modify(seg[i], 1, n, x, v);
    }
    vector<Seg*> sum(int id) {
        vector<Seg*> ret;
        Seg *t; build(t, 1, n);
        ret.push_back(t);
        for (int i = id; i; i -= lowbit(i)) ret.push_back(seg[i]);
        return ret;
    }
    #undef lowbit
} bit;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    top = mem;
    for (int i = 1; i <= n; ++i) a[i] = i;
    bit.init();
    for (int i = 1; i <= n; ++i) bit.add(i, a[i], 1);
    int inv = 0;
    while (m--) {
        int l, r; cin >> l >> r;
        if (l > r) swap(l, r);
        if (l == r) {  cout << inv << '\n'; continue; }
        int ans = 0;
        bit.add(l, a[l], -1), bit.add(r, a[r], -1);
        vector<Seg*> res1 = bit.sum(l), res2 = bit.sum(n);
        for (int i = 0; i < res1.size(); ++i) ans += query(res1[i], 1, n, a[l] + 1, n);
        for (int i = 0; i < res2.size(); ++i) ans += query(res2[i], 1, n, 1, a[l] - 1);
        for (int i = 0; i < res1.size(); ++i) ans -= query(res1[i], 1, n, 1, a[l] - 1);
        res1 = bit.sum(r);
        for (int i = 0; i < res1.size(); ++i) ans += query(res1[i], 1, n, a[r] + 1, n);
        for (int i = 0; i < res2.size(); ++i) ans += query(res2[i], 1, n, 1, a[r] - 1);
        for (int i = 0; i < res1.size(); ++i) ans -= query(res1[i], 1, n, 1, a[r] - 1);
        res1 = bit.sum(l);
        for (int i = 0; i < res1.size(); ++i) ans -= query(res1[i], 1, n, a[r] + 1, n);
        for (int i = 0; i < res2.size(); ++i) ans -= query(res2[i], 1, n, 1, a[r] - 1);
        for (int i = 0; i < res1.size(); ++i) ans += query(res1[i], 1, n, 1, a[r] - 1);
        res1 = bit.sum(r);
        for (int i = 0; i < res1.size(); ++i) ans -= query(res1[i], 1, n, a[l] + 1, n);
        for (int i = 0; i < res2.size(); ++i) ans -= query(res2[i], 1, n, 1, a[l] - 1);
        for (int i = 0; i < res1.size(); ++i) ans += query(res1[i], 1, n, 1, a[l] - 1);
        bit.add(l, a[r], 1), bit.add(r, a[l], 1);
        if (a[r] > a[l]) ++inv;
        else --inv;
        swap(a[l], a[r]);
        inv -= ans;
        cout << inv << '\n';
    }
    return 0;
}
