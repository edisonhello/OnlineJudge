#include <bits/stdc++.h>
#define tsize(t) (t ? t->sz : 0)
using namespace std;

const int maxn = 1e5 + 10;
int p[maxn];
bool v[maxn];

struct treap {
    treap *lc, *rc, *p;
    int pri, sz, val;
    treap(int v): val(v) {
        p = lc = rc = nullptr;
        pri = rand();
        sz = 1;
    }
    void pull() {
        p = nullptr;
        sz = tsize(lc) + tsize(rc) + 1;
        if (lc) lc->p = this;
        if (rc) rc->p = this;
    }
} *tr[maxn];

treap *merge(treap *a, treap *b) {
    if (!a || !b) return a ? a : b;
    if (a->pri > b->pri) {
        a->rc = merge(a->rc, b);
        return a->pull(), a;
    } else {
        b->lc = merge(a, b->lc);
        return b->pull(), b;
    }
}

void split(treap *t, int k, treap *&a, treap *&b) {
    if (!t) return (a = nullptr, b = nullptr), void();
    if (tsize(t->lc) + 1 <= k) a = t, split(t->rc, k - tsize(t->lc) - 1, a->rc, b), a->pull();
    else b = t, split(t->lc, k, a, b->lc), b->pull();
}

treap *root(treap *t) {
    if (!t->p) return t;
    return root(t->p);
}

int getpos(treap *t) {
    if (!t->p) return tsize(t->lc) + 1;
    if (t->p->rc == t) return tsize(t->lc) + 1 + getpos(t->p);
    return getpos(t->p) - 1 - tsize(t->rc);
}

void go(treap *t) {
    if (!t) return;
    go(t->lc);
    cout << t->val << ' ';
    go(t->rc);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> p[i], tr[i] = new treap(i);
    int c = 0;
    for (int i = 1; i <= n; ++i) if (!v[i]) {
        int now = p[i];
        v[i] = true;
        ++c;
        while (!v[now]) {
            tr[i] = merge(tr[i], tr[now]);
            v[now] = true;
            now = p[now];
        }
    }
    cout << n - c << endl;
    while (m--) {
        int a, b; cin >> a >> b;
        if (root(tr[a]) == root(tr[b])) {
            treap *t1, *t2;
            int pa = getpos(tr[a]);
            split(root(tr[a]), pa - 1, t1, t2);
            merge(t2, t1);
            int pb = getpos(tr[b]);
            split(root(tr[b]), pb - 1, t1, t2);
            ++c;
        } else {
            treap *t1, *t2;
            int pa = getpos(tr[a]);
            split(root(tr[a]), pa - 1, t1, t2);
            merge(t2, t1);
            int pb = getpos(tr[b]);
            split(root(tr[b]), pb - 1, t1, t2);
            merge(t2, t1);
            merge(root(tr[a]), root(tr[b]));
            --c;
        }
        cout << n - c << endl;
        // for (int i = 1; i <= n; ++i) if (root(tr[i]) == tr[i]) {
            // cout << "print: ";
            // go(tr[i]);
            // cout << endl;
        // }
    }
    return 0;
}
