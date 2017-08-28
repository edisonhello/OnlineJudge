#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, maxt = 1e6;
int t[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    pair<long long, int> t;
    SegmentTree *lc, *rc;
    SegmentTree(int L, int R) {
        t = make_pair(0, 0);
        lc = rc = nullptr;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    SegmentTree(SegmentTree *tc) {
        t = tc->t;
        lc = tc->lc;
        rc = tc->rc;
    }
    pair<long long, int> merge(const pair<long long, int>& a, const pair<long long, int>& b) {
        return make_pair(a.first + b.first, a.second + b.second);
    }
    void pull() {
        t = merge(lc->t, rc->t);
    }
    SegmentTree *modify(int L, int R, int x, int v) {
        SegmentTree *ret = new SegmentTree(this);
        if (L == R) {
            ret->t.first += v;
            ret->t.second++;
            return ret;
        }
        if (x <= M) ret->lc = lc->modify(L, M, x, v);
        else ret->rc = rc->modify(M + 1, R, x, v);
        ret->pull();
        return ret;
    }
    pair<long long, int> query(int L, int R, int l, int r) {
        if (L > r || l > R) return make_pair(0, 0);
        if (L >= l && R <= r) return t;
        return merge(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
#undef M
} *st[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    st[0] = new SegmentTree(0, maxt);
    for (int i = 1; i <= m; ++i) {
        cin >> t[i];
        st[i] = st[i - 1]->modify(0, maxt, t[i], t[i]);
    }
    while (n--) {
        int d, r; cin >> d >> r;
        int bit = 1, ans = m + 1; while (bit <= m) bit <<= 1;
        while (bit >>= 1) if (ans - bit >= 0) {
            pair<long long, int> p = st[ans - bit]->query(0, maxt, d, maxt);
            if (p.first - (long long)d * p.second >= r) ans -= bit;
        }
        cout << (ans == m + 1 ? 0 : ans) << ' ';
    } cout << endl;
    return 0;
}
