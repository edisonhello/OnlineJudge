#include <bits/stdc++.h>
#define int long long
#define size(t) (t ? t->sz : 0)
using namespace std;

const int maxn = 1e6 + 10;
int s[maxn];

struct treap {
    treap *lc, *rc;
    int val, pri, sz, tag;
    treap(int v): val(v) {
        pri = rand(); sz = 1;
        lc = rc = nullptr;
        tag = 0;
    }
    void pull() {
        sz = size(lc) + size(rc) + 1;
    }
    void push() {
        if (tag == 0) return;
        if (lc) lc->val += tag, lc->tag += tag;
        if (rc) rc->val += tag, rc->tag += tag;
        tag = 0;
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

void split_by_size(treap *t, int k, treap *&a, treap *&b) {
    if (!t) {
        a = b = nullptr;
        return;
    }
    t->push();
    if (size(t->lc) + 1 <= k) {
        a = t;
        split_by_size(t->rc, k - size(t->lc) - 1, a->rc, b);
        a->pull();
    } else {
        b = t;
        split_by_size(t->lc, k, a, b->lc);
        b->pull();
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

int findmax(treap *t) {
    if (!t) return 0;
    t->push();
    if (t->rc) return findmax(t->rc);
    return t->val;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    while (n--) {
        int a, b; cin >> a >> b;
        ++s[a]; --s[b + 1];
    }
    for (int i = 1; i < maxn; ++i) s[i] += s[i - 1];
    int ans = 0;
    for (int i = 1; i < maxn; ++i) ans = max(ans, s[i]);
    int m; cin >> m;
    vector<pair<int, int>> w(m);
    for (int i = 0; i < m; ++i) cin >> w[i].first >> w[i].second;
    sort(w.begin(), w.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; });
    int ptr = 1;
    for (auto p : w) {
        while (ptr <= p.second) {
            treap *a, *b;
            split_by_val(t, s[ptr], a, b);
            t = merge(merge(a, new treap(s[ptr])), b);
            ++ptr;
        }
        treap *a, *b;
        split_by_size(t, p.first, a, b);
        int nt = findmax(a);
        ++a->tag; ++a->val;
        treap *c, *d, *e, *f;
        split_by_val(a, nt, c, d);
        split_by_val(b, nt, e, f);
        t = merge(merge(c, e), merge(d, f));
    }
    cout << max(ans, findmax(t)) << endl;
    return 0;
}
