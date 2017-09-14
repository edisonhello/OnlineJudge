#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

struct SegmentTree {
    #define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    int cnt;
    SegmentTree(int L, int R) {
        cnt = 0;
        lc = rc = nullptr;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
        pull();
    }
    SegmentTree(SegmentTree *t) {
        cnt = t->cnt;
        lc = t->lc; rc = t->rc;
    }
    void pull() {
        cnt = lc->cnt + rc->cnt;
    }
    SegmentTree* modify(int L, int R, int x, int v) {
        SegmentTree *ret = new SegmentTree(this);
        if (L == R) {
            ret->cnt += v;
            return ret;
        }
        if (x <= M) ret->lc = lc->modify(L, M, x, v);
        else ret->rc = rc->modify(M + 1, R, x, v);
        ret->pull();
        return ret;
    }
    int query(int L, int R, int l, int r) {
        if (l > r) return 0;
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return cnt;
        return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
    }
} *st[maxn];

int a[maxn];

int main() {
    // freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> vec;
    for (int i = 1; i <= n; ++i) cin >> a[i], vec.push_back(a[i]);
    sort(vec.begin(), vec.end()); vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    for (int i = 1; i <= n; ++i) a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin() + 1;
    st[0] = new SegmentTree(1, vec.size());
    for (int i = 1; i <= n; ++i) st[i] = st[i - 1]->modify(1, vec.size(), a[i], 1);
    for (int k = 1; k < n; ++k) {
        long long ans = 0;
        int ind = 2;
        for (int i = 1; i <= n && ind <= n; ++i) {
            int to = min(n, ind + k - 1);
            ans += st[to]->query(1, vec.size(), 1, a[i] - 1) - st[ind - 1]->query(1, vec.size(), 1, a[i] - 1);
            ind += k;
        }
        cout << ans << ' ';
    }
    cout << endl;
    // cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    return 0;
}
