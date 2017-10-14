#define tsize(t) (t ? t->size : 0)

struct treap {
    treap *lc, *rc;
    int val, pri, sz;
    treap(int v): val(v) {
        lc = rc = nullptr;
        pri = rand();
        sz = 1;
    }
    void pull() {
        sz = tsize(lc) + tsize(rc) + 1;
    }
};

treap *merge(treap *a, treap *b) {
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

void split_by_val(treap *t, int k, treap *&a, treap *&b) {
    if (!t) {
        a = b = nullptr;
        return;
    }
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

void split_by_size(treap *t, int k, treap *&a, treap *&b) {
    if (!t) {
        a = b = nullptr;
        return;
    }
    if (tsize(t->lc) + 1 <= k) {
        a = t;
        split(t->rc, k - tsize(t->lc) - 1, a->rc, b);
        a->pull();
    } else {
        b = t;
        split(t->lc, k, a, b->lc);
        b->pull();
    }
}
