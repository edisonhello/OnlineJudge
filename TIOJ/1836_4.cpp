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

struct SegmentTree {
#define M ((L + R) >> 1)
    static SegmentTree mem[800000];
    static SegmentTree *ptr;
    struct TreeNode {
        TreeNode *lc, *rc;
        long long g;
        int pos;
        TreeNode() {
            lc = rc = nullptr;
            g = 0; pos = -1;
        }
        void modify(int L, int R, int p, long long v) {
            if (L == R) return g = v, void();
            if (pos == p) return g = v, void();
            if (pos == -1) {
                pos = p;
                g = v;
                return;
            }
            if (pos > 0) {
                if (pos <= M) {
                    if (!lc) lc = new TreeNode();
                    lc->modify(L, M, pos, v);
                } else {
                    if (!rc) rc = new TreeNode();
                    rc->modify(M + 1, R, pos, v);
                }
                pos = 0;
            }
            if (p <= M) {
                if (!lc) lc = new TreeNode();
                lc->modify(L, M, p, v);
            } else {
                if (!rc) rc = new TreeNode();
                rc->modify(M + 1, R, p, v);
            }
            pull();
        }
        void pull() {
            g = 0;
            if (lc) g = __gcd(g, lc->g);
            if (rc) g = __gcd(g, rc->g);
        }
        long long query(int L, int R, int l, int r) {
            if (L > r || l > R) return 0ll;
            if (pos > 0 && pos >= l && pos <= r) return g;
            if (pos > 0) return 0;
            if (L >= l && R <= r) return g;
            long long lq = lc ? lc->query(L, M, l, r) : 0ll;
            long long rq = rc ? rc->query(M + 1, R, l, r) : 0ll;
            return __gcd(lq, rq);
        }
    } *tn;
    SegmentTree *lc, *rc;
    SegmentTree() {
        lc = rc = nullptr;
        tn = new TreeNode();
    }
    void modify(int L, int R, int row, int col, long long v) {
        if (L == R) return tn->modify(1, c, col, v), void();
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
        if (L >= rl && R <= rr) return tn->query(1, c, cl, cr); 
        long long lq = lc ? lc->query(L, M, rl, rr, cl, cr) : 0ll;
        long long rq = rc ? rc->query(M + 1, R, rl, rr, cl, cr) : 0ll;
        return __gcd(lq, rq);
    }
    inline void pull(int col) {
        long long lval = 0, rval = 0;
        if (lc) lval = lc->tn->query(1, c, col, col);
        if (rc) rval = rc->tn->query(1, c, col, col);
        tn->modify(1, c, col, __gcd(lval, rval));
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
