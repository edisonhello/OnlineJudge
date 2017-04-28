#include <bits/stdc++.h>
using namespace std;

inline int gtx() {
  const int N = 1048576;
  static char buffer[N];
  static char *p = buffer, *end = buffer;
  if (p == end) {
    if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
    p = buffer;
  }
  return *p++;
}
template <typename T>
inline bool rit(T& x) {
  char __c = 0; bool flag = false;
  while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
  while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}
template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }


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
        if (t->lc) clear(t->lc);
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
    void ins(T val) {
        Node *a, *b;
        split(root, val, a, b);
        root = merge(merge(a, new Node(val)), b);
    }
    void del(T val) {
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
    Treap<int> t;
    while (true) {
        int tp; cin >> tp;
        if (tp == 1) {
            int n; cin >> n;
            t.ins(n);
        } else if (tp == 2) {
            int n; cin >> n;
            t.del(n);
        } else {
            int n; cin >> n;
            cout << t.find(n) << '\n';
        }
    }
    return 0;
}
