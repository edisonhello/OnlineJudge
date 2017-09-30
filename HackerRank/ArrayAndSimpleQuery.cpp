#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

struct treap {
    treap *lc, *rc;
    int pri, val, sz;
    treap(int v): val(v) {
        sz = 1;
        lc = rc = nullptr;
        pri = rand();
    }
    void pull() {
        sz = 1 + (lc ? lc->sz : 0) + (rc ? rc->sz : 0);
    }
};

treap *merge(treap* a, treap* b) {
    if (!a || !b) return a ? a : b;
    if (a->pri > b->pri) {
        a->rc = merge(a->rc, b);
        a->pull();
        return a;
    } else {
        b->lc = merge(a, b->lc);
        b->pull();
        return b;
    }
}

void split(treap* t, int k, treap *&a, treap *&b) {
    if (!t) {
        a = b = nullptr;
        return;
    }
    if ((t->lc ? t->lc->sz : 0) + 1 <= k) {
        a = t;
        split(t->rc, k - (t->lc ? t->lc->sz : 0) - 1, a->rc, b);
        a->pull();
    } else {
        b = t;
        split(t->lc, k, a, b->lc);
        b->pull();
    }
}

int a[maxn];

void debug(treap *t, int n) {
    for (int i = 1; i <= n; ++i) {
        treap *a, *b, *c, *d;
        split(t, i - 1, a, b);
        split(b, 1, c, d);
        cout << c->val << ' ';
        t = merge(a, merge(c, d));
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    treap *t = nullptr;
    for (int i = 1; i <= n; ++i) cin >> a[i], t = merge(t, new treap(a[i]));
    while (m--) {
        int tp, l, r; cin >> tp >> l >> r;
        if (tp == 1) {
            treap *a, *b, *c, *d;
            split(t, l - 1, a, b);
            split(b, r - l + 1, c, d);
            t = merge(merge(c, a), d);
        } else {
            treap *a, *b, *c, *d;
            split(t, l - 1, a, b);
            split(b, r - l + 1, c, d);
            t = merge(merge(a, d), c);
        }
        // debug(t, n);
    }
    for (int i = 1; i <= n; ++i) {
        treap *c, *d;
        split(t, 1, c, d);
        a[i] = c->val;
        t = d;
    }
    cout << abs(a[1] - a[n]) << endl;
    for (int i = 1; i <= n; ++i) cout << a[i] << ' '; cout << endl;
    return 0;
}
