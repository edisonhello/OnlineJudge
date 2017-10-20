#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC diagnostic ignored "-Wunused-function"
#include <cstdio>
#include <algorithm>
#include <ctime>
#define getchar gtx
#define tsize(t) (t ? t->sz : 0)
#define tgcd(t) (t ? t->g : 0)
using namespace std;

const int maxn = 1e9 + 10;
int r, c, n;

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

struct treap {
    treap *lc, *rc;
    static treap mem[800000];
    static treap *ptr;
    int pri, sz, col;
    long long val, g;
    treap() {}
    treap(long long v, int c): val(v), col(c) {
        g = v;
        pri = rand();
        sz = 1;
        lc = rc = nullptr;
    }
    inline void pull() {
        sz = tsize(lc) + tsize(rc) + 1;
        g = __gcd(tgcd(lc), tgcd(rc));
        g = __gcd(g, val);
    }
} treap::mem[800000], *treap::ptr = mem;

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

void split(treap *t, int k, treap *&a, treap *&b) {
    if (!t) return (a = nullptr, b = nullptr), void();
    if (t->col <= k) {
        a = t;
        split(t->rc, k, a->rc, b);
        a->pull();
    } else {
        b = t;
        split(t->lc, k, a, b->lc);
        b->pull();
    }
}

struct SegmentTree {
#define M ((L + R) >> 1)
    static SegmentTree mem[800000];
    static SegmentTree *ptr;
    SegmentTree *lc, *rc;
    treap *tr;
    SegmentTree() {
        lc = rc = nullptr;
        tr = nullptr;
    }
    void modify(int L, int R, int row, int col, long long v) {
        if (L == R) {
            treap *a, *b, *c, *d;
            split(tr, col - 1, a, b);
            split(b, col, c, d);
            if (c) c->val = c->g = v;
            else c = new (treap::ptr++) treap(v, col);
            tr = merge(merge(a, c), d);
            return;
        }
        if (row <= M) {
            if (!lc) lc = new (ptr++) SegmentTree();
            lc->modify(L, M, row, col, v);
        } else {
            if (!rc) rc = new (ptr++) SegmentTree();
            rc->modify(M + 1, R, row, col, v);
        }
        pull(col);
    }
    long long query(int L, int R, int rl, int rr, int cl, int cr) {
        if (L > rr || rl > R) return 0ll;
        if (L >= rl && R <= rr) {
            treap *a, *b, *c, *d;
            split(tr, cl - 1, a, b);
            split(b, cr, c, d);
            long long ret = c ? c->g : 0ll;
            tr = merge(merge(a, c), d);
            return ret;
        }
        long long lq = lc ? lc->query(L, M, rl, rr, cl, cr) : 0ll;
        long long rq = rc ? rc->query(M + 1, R, rl, rr, cl, cr) : 0ll;
        return __gcd(lq, rq);
    }
    inline void pull(int col) {
        long long lval = 0, rval = 0;
        if (lc) {
            treap *a, *b, *c, *d;
            split(lc->tr, col - 1, a, b);
            split(b, col, c, d);
            lval = c ? c->g : 0;
            lc->tr = merge(merge(a, c), d);
        }
        if (rc) {
            treap *a, *b, *c, *d;
            split(rc->tr, col - 1, a, b);
            split(b, col, c, d);
            rval = c ? c->g : 0;
            rc->tr = merge(merge(a, c), d);
        }
        treap *a, *b, *c, *d;
        split(tr, col - 1, a, b);
        split(b, col, c, d);
        if (c) c->val = c->g = __gcd(lval, rval);
        else c = new (treap::ptr++) treap(__gcd(lval, rval), col);
        tr = merge(merge(a, c), d);
    }
#undef M
} *st, SegmentTree::mem[800000], *SegmentTree::ptr = mem;

int main() {
    srand(time(nullptr));
    rit(r, c, n);
    st = new (SegmentTree::ptr++) SegmentTree();
    while (n--) {
        int t; rit(t);
        if (t == 1) {
            int p, q; long long k;
            rit(p, q); rit(k);
            ++p; ++q;
            st->modify(1, r, p, q, k);
        } else {
            int p, q, u, v;
            rit(p, q, u, v);
            ++p; ++q; ++u; ++v;
            printf("%lld\n", st->query(1, r, p, u, q, v));
        }
    }
    return 0;
}
