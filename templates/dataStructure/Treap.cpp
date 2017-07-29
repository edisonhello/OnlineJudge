template <typename T> class Treap {
    private:
#define size(t) (t ? t->sz : 0)
        struct Node {
            T val;
            int pri, sz;
            Node *lc, *rc;
            Node(T v): pri(rand()), val(v) {
                lc = rc = nullptr;
                sz = 1;
            }
            void pull() {
                sz = size(lc) + size(rc) + 1;
            }
        } *root;
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
        T kth(Node *t, int k) {
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
#undef size
    public:
        Treap(unsigned seed=time(nullptr)) {
            srand(seed);
            root = nullptr;
        }
        ~Treap() {
            clear(root);
            root = nullptr;
        }
        void insert(T val) {
            Node *a, *b;
            split(root, val - 1, a, b);
            root = merge(merge(a, new Node(val)), b);
        }
        void erase(T val) {
            Node *a, *b, *c, *d;
            split(root, val - 1, a, b);
            split(b, val, c, d);
            c = merge(c->lc, c->rc);
            root = merge(a, merge(c, d));
        }
        T find(int k) {
            return kth(root, k);
        }
};
