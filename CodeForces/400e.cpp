#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, lg = 20;
int a[maxn], c[lg][maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    static SegmentTree mem[1000000];
    static SegmentTree *ptr;
    int val[lg], tag[lg];
    SegmentTree *lc, *rc;
    SegmentTree() {}
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        memset(val, 0, sizeof(val)); memset(tag, 0, sizeof(tag));
        if (L == R) {
            for (int i = 0; i < lg; ++i) val[i] = c[i][L];
            return;
        }
        lc = new (ptr++) SegmentTree(L, M); rc = new (ptr++) SegmentTree(M + 1, R);
        pull();
    }
    void pull() {
        for (int i = 0; i < lg; ++i) val[i] = lc->val[i] + rc->val[i];
    }
    void push(int L, int R) {
        if (!lc) return;
        for (int i = 0; i < lg; ++i) if (tag[i]) {
            lc->val[i] += (M - L + 1) * tag[i]; lc->tag[i] += tag[i];
            rc->val[i] += (R - M) * tag[i]; rc->tag[i] += tag[i];
            tag[i] = 0;
        }
    }
    void modify(int L, int R, int l, int r, int b, int v) {
        if (l > r) return;
        push(L, R);
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            val[b] += (R - L + 1) * v; tag[b] += v;
            return;
        }
        lc->modify(L, M, l, r, b, v); rc->modify(M + 1, R, l, r, b, v);
        pull();
    }
    int query(int L, int R, int l, int r, int b) {
        push(L, R);
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return val[b];
        return lc->query(L, M, l, r, b) + rc->query(M + 1, R, l, r, b);
    }
} *st, SegmentTree::mem[1000000], *SegmentTree::ptr = mem;

set<int> z[lg];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int b = 0; b < lg; ++b) c[b][i] = n - i + 1;
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int b = 0; b < lg; ++b) {
        int pv = 0, now = 1;
        while (now <= n) {
            while (now <= n && a[now] & (1 << b)) ++now;
            c[b][now] = 0;
            if (now > n) break;
            for (int k = now - 1, j = 1; k > pv; --k, ++j) c[b][k] = min(c[b][k], j);
            z[b].insert(now);
            pv = now;
            ++now;
        }
    }
    // for (int b = 0; b < lg; ++b) {
        // cout << "b = " << b << endl;
        // for (auto it = z[b].begin(); it != z[b].end(); ++it) cout << *it << ' ';
        // cout << endl;
    // }
    st = new (SegmentTree::ptr++) SegmentTree(1, n);
    while (m--) {
        int p, v; cin >> p >> v;
        for (int b = 0; b < lg; ++b) {
            if ((v & (1 << b)) == (a[p] & (1 << b))) continue;
            if (v & (1 << b)) {
                if (z[b].size() == 1) {
                    st->modify(1, n, 1, p, b, n - p + 1);
                    z[b].erase(p);
                    continue;
                }
                assert(z[b].find(p) != z[b].end());
                auto it = z[b].lower_bound(p);
                int pos = (it == z[b].begin() ? 0 : *(--it));
                int k = st->query(1, n, p + 1, p + 1, b);
                st->modify(1, n, pos + 1, p, b, k + 1);
                z[b].erase(p);
            } else {
                if (z[b].size() == 0) {
                    int k = st->query(1, n, p, p, b);
                    st->modify(1, n, 1, p, b, -k);
                    z[b].insert(p);
                    continue;
                }
                assert(z[b].find(p) == z[b].end());
                auto it = z[b].lower_bound(p); 
                int pos = (it == z[b].begin() ? 0 : *(--it));
                int k = st->query(1, n, p, p, b);
                // cout << k << endl;
                st->modify(1, n, pos + 1, p, b, -k);
                z[b].insert(p);
            }
        }
        // for (int b = 0; b < lg; ++b) {
            // cout << "b = " << b << endl;
            // for (auto it = z[b].begin(); it != z[b].end(); ++it) cout << *it << ' ';
            // cout << endl;
        // }
        a[p] = v;
        // for (int b = 0; b < lg; ++b) {
            // cout << "b = " << b << endl;
            // for (int i = 1; i <= n; ++i) cout << st->query(1, n, i, i, b) << ' ';
            // cout << endl;
        // }
        // for(int b = 0; b < lg; ++b) cout << st->query(1, n, 1, n, b) << endl;
        long long ans = 0;
        for  (int b = 0; b < lg; ++b) ans += st->query(1, n, 1, n, b) * 1ll * (1 << b);
        cout << ans << '\n';
    }
    return 0;
}
