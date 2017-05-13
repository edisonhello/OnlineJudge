#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int n, m, a[maxn];

struct Seg {
    Seg *lc, *rc;
    int sum;
    bool leaf;
    Seg(int L, int R) {
        lc = rc = nullptr;
        sum = 0; leaf = false;
        if (L == R) { leaf = true; return; }
        int M = (L + R) >> 1;
        lc = new Seg(L, M); rc = new Seg(M + 1, R);
    }
    Seg(Seg* t) {
        leaf = t->leaf;
        sum = t->sum;
        lc = t->lc; rc = t->rc;
    }
    Seg* modify(int L, int R, int x, int v) {
        Seg* ret = new Seg(this);
        if (L == R) {
            ret->sum += v;
            return ret;
        }
        int M = (L + R) >> 1;
        if (x <= M) ret->lc = lc->modify(L, M, x, v);
        else ret->rc = rc->modify(M + 1, R, x, v);
        ret->pull();
        return ret;
    }
    void pull() {
        if (lc->leaf) sum = (int)(lc->sum > 0) + (int)(rc->sum > 0);
        else sum = lc->sum + rc->sum;
    }
    int query(int L, int R, int l, int r) {
        if (L > r || l > R) return 0;
        if (L == R) return (int)(sum > 0);
        if (L >= l && R <= r) return sum;
        int M = (L + R) >> 1;
        return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
    }
};

struct BIT {
    Seg *st[maxn];
    void init() {
        st[0] = new Seg(0, maxn - 1);
        for (int i = 1; i <= n; ++i) st[i] = st[0];
    }
#define lowbit(x) (x & -x)
    void add(int x, int p, int v) {
        for (int i = x; i <= n; i += lowbit(i))  st[i] = st[i]->modify(0, maxn - 1, p, v);
    }
    vector<Seg*> sum(int x) {
        vector<Seg*> ret;
        for (int i = x; i; i -= lowbit(i)) ret.push_back(st[i]);
        return ret;
    }
#undef lowbit
} bit;

int cal(const vector<Seg*>&);

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    bit.init();
    for (int i = 1; i <= n; ++i) cin >> a[i], bit.add(i, a[i], 1);
    while (m--) {
        char c; cin >> c;
        if (c == 'M') {
            int x, y; cin >> x >> y; ++x;
            bit.add(x, a[x], -1);
            a[x] = y;
            bit.add(x, a[x], 1);
        } else {
            int l, r; cin >> l >> r; ++l;
            vector<Seg*> R = bit.sum(r), L = bit.sum(l - 1);
            cout << "R: " << cal(R) << "  L: " << cal(L) << endl;
            cout << cal(R) - cal(L) << '\n';
        }
    }
    return 0;
}

int cal(const vector<Seg*>& vec) {
    int ret = 0;
    for (Seg* t : vec) ret += t->query(0, maxn - 1, 0, maxn - 1);
    return ret;
}
