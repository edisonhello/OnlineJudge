#include <bits/stdc++.h>
#define int long long
#define tsize(t) (t ? t->sz : 0)
using namespace std;

const int maxn = 1e5 + 10;
pair<int, int> p[maxn];

struct treap {
    treap *lc, *rc;
    int val, tag, pri, sz;
    treap(int v): val(v) {
        tag = 0;
        pri = rand();
        sz = 1;
        lc = rc = nullptr;
    }
    void push() {
        if (tag == 0) return;
        if (lc) lc->val += tag, lc->tag += tag;
        if (rc) rc->val += tag, rc->tag += tag;
        tag = 0;
    }
    void pull() {
        sz = tsize(lc) + tsize(rc) + 1;
    }
} *t;

treap *merge(treap *a, treap *b) {
    if (!a || !b) return a ? a : b;
    a->push(); b->push();
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

void split_by_val(treap *t, int k, treap *&a, treap *&b) {
    if (!t) {
        a = b = nullptr;
        return;
    }
    t->push();
    if (t->val <= k) {
        a = t;
        split_by_val(t->rc, k, a->rc, b);
        a->pull();
    } else {
        b = t;
        split_by_val(t->lc, k, a, b->lc);
        b->pull();
    }
}

void split_by_size(treap *t, int k, treap *&a, treap *&b) {
    if (!t) {
        a = b = nullptr;
        return;
    }
    t->push();
    if (tsize(t->lc) + 1 <= k) {
        a = t;
        split_by_size(t->rc, k - tsize(t->lc) - 1, a->rc, b);
        a->pull();
    } else {
        b = t;
        split_by_size(t->lc, k, a, b->lc);
        b->pull();
    }
}

int findmax(treap *t) {
    t->push();
    if (!t->rc) return t->val;
    return findmax(t->rc);
} 

int go(treap *t) {
    if (!t) return 0;
    t->push();
    return t->val * (t->val - 1) / 2 + go(t->lc) + go(t->rc);
}

void debug(treap *t) {
    if (!t) return;
    t->push();
    debug(t->lc);
    cout << t->val << ' ';
    debug(t->rc);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
    sort(p, p + n);
    for (int i = 0; i < n; ++i) {
        int h = p[i].first, k = p[i].second;
        while (tsize(t) < h) t = merge(new treap(0), t);
        treap *a, *b;
        split_by_size(t, k, a, b);
        int m = findmax(a);
        ++a->tag; ++a->val;
        treap *c, *d, *e, *f;
        split_by_val(a, m, e, f);
        split_by_val(b, m, c, d);
        t = merge(merge(e, c), merge(f, d));
        // debug(t);
        // cout << endl;
    }
    cout << go(t) << endl;
    return 0;
}
