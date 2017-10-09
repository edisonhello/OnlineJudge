#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10, mod = 1e9 + 7;
long long x[maxn], y[maxn];

struct data {
    long double lg;
    long long mul;
    data(long double a, long long b): lg(a), mul(b) {}
    data() {}
    data operator+(const data& rhs) const {
        return data(lg + rhs.lg, mul * rhs.mul % mod);
    }
    bool operator>(const data& rhs) const {
        return lg > rhs.lg;
    }
    bool operator<(const data& rhs) const {
        return lg < rhs.lg;
    }
};

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    data val, sum;
    static SegmentTree mem[3000000];
    static SegmentTree* ptr;
    SegmentTree() {}
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        if (L == R) {
            sum = data(log(x[L]), x[L]);
            val = data(log(x[L]) + log(y[L]), x[L] * y[L] % mod);
            return;
        }
        lc = new (ptr++) SegmentTree(L, M); rc = new (ptr++) SegmentTree(M + 1, R);
        pull();
    } 
    void pull() {
        sum = lc->sum + rc->sum;
        val = max(lc->val, lc->sum + rc->val);
    }
    void modify(int L, int R, int pos, int v, int tp) {
        if (L == R) {
            if (tp == 1) x[L] = v;
            else y[L] = v;
            sum = data(log(x[L]), x[L]);
            val = data(log(x[L]) + log(y[L]), x[L] * y[L] % mod);
            return;
        }
        if (pos <= M) lc->modify(L, M, pos, v, tp);
        else rc->modify(M + 1, R, pos, v, tp);
        pull();
    }
} *st, SegmentTree::mem[3000000], *SegmentTree::ptr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) cin >> x[i];
        for (int i = 0; i < n; ++i) cin >> y[i];
        SegmentTree::ptr = SegmentTree::mem; st = new (SegmentTree::ptr++) SegmentTree(0, n - 1);
        cout << st->val.mul << endl;
        int m; cin >> m; while (m--) {
            int k, p, v; cin >> k >> p >> v;
            st->modify(0, n - 1, p, v, k);
            cout << st->val.mul << endl;
        }
    }
    return 0;
}
