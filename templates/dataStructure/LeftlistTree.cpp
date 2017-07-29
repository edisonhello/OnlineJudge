template <typename T> class LeftlistTree {
    private:
#define rank(t) (t ? t->s : 0)
        struct Node {
            T val;
            int s;
            Node *lc, *rc;
            Node(T v): val(v) {
                lc = rc = nullptr;
                s = 1;
            }
        } *root;
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
    public:
        LeftlistTree() {
            root = nullptr;
        }
        void push(T val) {
            root = merge(root, new Node(val));
        }
        void pop() {
            T ret = root->val;
            Node *tmp = root;
            root = merge(root->lc, root->rc);
            delete tmp;
        }
        T top() {
            return root->val;
        }
        void merge(LeftlistTree t) {
            root = merge(root, t->root);
        }
};
