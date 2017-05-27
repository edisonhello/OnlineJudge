#include <bits/stdc++.h>
using namespace std;
template <class T>
class Treap {
    private:
        struct Node {
#define Size(t) (t ? t->sz : 0)
            T val;
            int pri, sz;
            Node *lc, *rc;
            Node(const T& _val): val(_val) {
                lc = NULL;
                rc = NULL;
                pri = rand();
                sz = 1;
            }
            void pull() {
                sz = 1 + Size(lc) + Size(rc);
            }
            T kth(int k) {
                if (Size(lc) + 1 == k) return val;
                if (Size(lc) + 1 < k) return rc->kth(k - Size(lc) - 1);
                return lc->kth(k);
            }
#undef Size
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
        void split(Node *t, T k, Node *&a, Node *&b) {
            if (!t) { a = b = NULL; return; }
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
        void clear(Node *& t) {
            if (!t) return;
            if (t->rc) clear(t->rc);
            delete t;
            t = NULL;
        }
    public:
        Treap(unsigned seed = time(NULL)) {
            srand(seed);
            root = NULL;
        }
        ~Treap() {
            clear(root);
            root = NULL;
        }
        void insert(T val) {
            Node *a, *b;
            split(root, val, a, b);
            root = merge(merge(a, new Node(val)), b);
        }
        void remove(T val) {
            Node *a, *b, *c, *d;
            split(root, val - 1, a, b);
            split(b, val, c, d);
            Node *tmp = c;
            c = merge(c->lc, c->rc);
            delete tmp;
            root = merge(merge(a, c), d);
        }
        T find(int k) {
            return root->kth(k);
        }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string a, b; cin >> a >> b;
    int n = (int)a.size();
    deque<char> c1, c2;
    for (int i = 0; i < n; ++i) c1.push_back(a[i]);
    for (int i = 0; i < n; ++i) c2.push_back(b[i]);
    sort(c1.begin(), c1.end()); sort(c2.begin(), c2.end());
    vector<char> ans(n);
    // set<int> s;
    Treap<int> s;
    for (int i = 0; i < n; ++i) s.insert(i);
    int l1, l2;
    if (n & 1) l1 = n / 2 + 1, l2 = n / 2;
    else l1 = n / 2, l2 = n / 2;
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            char c = c2.back(); int pos;
            if (c1.front() > c) pos = s.find(l1 + 1);
            else pos = s.find(1);
            ans[pos] = c; c2.pop_back(); l2--;
            s.remove(pos);
        } else {
            char c = c1.front(); int pos;
            if (c2.back() < c) pos = s.find(l2 + 1);
            else pos = s.find(1);
            ans[pos] = c; c1.pop_front(); l1--;
            s.remove(pos);
        }
    }
    for (int i = 0; i < n; ++i) cout << ans[i];
    return 0;
}
