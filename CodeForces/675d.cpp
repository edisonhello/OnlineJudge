#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;
int a[maxn], ans[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    int val = inf;
    SegmentTree *lc, *rc;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    void pull() {
        val = min(lc->val, rc->val);
    }
    void modify(int L, int R, int x, int v) {
        if (L == R) {
            val = v;
            return;
        }
        if (x <= M) lc->modify(L, M, x, v);
        else rc->modify(M + 1, R, x, v);
        pull();
    }
    int query(int L, int R, int l, int r) {
        if (L > r || l > R) return inf;
        if (L >= l && R <= r) return val;
        return min(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
#undef M
} *l, *r;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; ++i) cin >> a[i], vec.push_back(a[i]);
    sort(vec.begin(), vec.end()); vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    l = new SegmentTree(0, n - 1); r = new SegmentTree(0, n - 1);
    ans[0] = -1;
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin();
        if (!ans[i]) {
            int q1 = l->query(0, n - 1, pos, n - 1), q2 = r->query(0, n - 1, 0, pos);
            cout << i << ' ' << q1 << ' ' << q2 << endl;
            if (q1 < q2) {
                ans[i] = q1;
                l->modify(0, n - 1, lower_bound(vec.begin(), vec.end(), a[q1]) - vec.begin(), inf);
            } else {
                ans[i] = q2;
                r->modify(0, n - 1, lower_bound(vec.begin(), vec.end(), a[q2]) - vec.begin(), inf);
            }
        }
        l->modify(0, n - 1, pos, i);
        r->modify(0, n - 1, pos, i);
    }
    for (int i = 1; i < n; ++i) cout << a[ans[i]] << ' '; cout << endl;
    return 0;
}
