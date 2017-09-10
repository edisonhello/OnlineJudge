namespace Treap {
    struct Node {
        int val, pri, sz;
        Node *lc, *rc;
        Node(T v): pri(rand()), val(v) {
            lc = rc = nullptr;
            sz = 1;
        }
        void pull() {
            sz = size(lc) + size(rc) + 1;
        }
    };
    inline int size(Node* t) {
        return t ? t->sz : 0;
    }
    Node *merge(Node *a, Node *b) {
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
    void split(Node *t, int k, Node *&a, Node *&b) {
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
    int kth(Node *t, int k) {
        if (size(t->lc) + 1 == k) return t->val;
        if (size(t->lc) + 1 > k) return kth(t->lc, k);
        return kth(t->rc, k - size(t->lc) - 1);
    }
    void clear(Node *t) {
        if (!t) return;
        if (t->lc) clear(t->lc);
        if (t->rc) clear(t->rc);
        delete t;
    }
}
