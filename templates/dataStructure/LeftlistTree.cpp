namespace LeftlistTree {
    struct Node {
        T val;
        int s;
        Node *lc, *rc;
        Node(T v): val(v) {
            lc = rc = nullptr;
            s = 1;
        }
    };
    inline int rank(Node* t) {
        return t ? t->s : 0;
    }
    Node *merge(Node *a, Node *b) {
        if (!a || !b) return a ? a : b;
        if (a->val < b->val) swap(a, b);
        a->rc = merge(a->rc, b);
        if (rank(a->lc) < rank(a->rc)) swap(a->lc, a->rc);
        a->s = rank(a->rc) + 1;
        return a;
    }
    void clear(Node *t) {
        if (!t) return;
        if (t->lc) clear(t->lc);
        if (t->rc) clear(t->rc);
        delete t;
    }
}
