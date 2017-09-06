#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

namespace Treap {
    struct treap {
        treap *lc, *rc;
        int pri, val, sz;
        treap(int v): v(val) {
            s = 1;
            lc = rc = nullptr;
            pri = rand();
        }
        void pull() {
            sz = size(lc) + size(rc) + 1;
        }
    };
    inline int size(treap* t) { return t ? t->sz : 0; }
    treap* merge(treap* a, treap* b) {
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
    void split(treap* t, int k, treap*& a, treap*& b) {
        if (!t) { a = b = nullptr; return; }
        if (t->val <= k) {
            a = t;
            split(t->rc, k, a->rc, b);
            a->pull();
        } else {
            b = t;
            split(t->lc, k, a, b->lc);
            b->pull();
        }
    }
}

int main() {

}
