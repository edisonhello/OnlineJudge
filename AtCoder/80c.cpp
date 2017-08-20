#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, inf = 1e9 + 1;
int p[maxn], pos[maxn], q[maxn], fr[maxn], ba[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    int val;
    SegmentTree *lc, *rc;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        val = inf;
        if (L == R) {
            val = p[L];
            return;
        }
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
        pull();
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
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i], pos[p[i]] = i;
    // for (int i = 1; i <= n; ++i) cout << pos[i] << ' '; cout << endl;
    for (int i = 1; i <= n; ++i) ba[p[i]] = p[i + 1];
    st = new SegmentTree(1, n);
    int ind = n;
    set<int> s;
    for (int i = 1; i <= n; ++i) s.insert(i);
    for (int i = 0; i < n / 2; ++i) {
        auto it = s.end(); --it; --it; --it; --it;
        int r = *it;
        // cout << "r = " << r << endl;
        if (s.size() <= 2) {
            int a = st->query(1, n, 1, n);
            st->modify(1, n, pos[a], inf);
            int b = st->query(1, n, 1, n);
            st->modify(1, n, pos[b], inf);
            if (pos[a] > pos[b]) swap(a, b);
            // cout << a << ' ' << b << endl;
            q[1] = a; q[2] = b;
            break;
        }
        int v = st->query(1, n, 1, r);
        q[ind - 1] = ba[v]; q[ind] = ba[ba[v]];
        // cout << ba[v] << ' ' << ba[ba[v]] << endl;
        ind -= 2;
        st->modify(1, n, pos[ba[v]], inf); st->modify(1, n, pos[ba[ba[v]]], inf);
        s.erase(pos[ba[v]]); s.erase(pos[ba[ba[v]]]);
        ba[v] = ba[ba[ba[v]]];
    }
    for (int i = 1; i <= n; ++i) cout << q[i] << ' '; cout << endl;
    return 0;
}
