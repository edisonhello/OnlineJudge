#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

struct Seg {
    Seg *lc, *rc;
    int sum, tag;
    Seg(int L, int R) {
        lc = rc = NULL;
        sum = 0, tag = 0;
        if (L == R) return;
        int M = (L + R) >> 1;
        lc = new Seg(L, M); rc = new Seg(M + 1, R);
        pull();
    }
    Seg(Seg* t) {
        lc = t->lc; rc = t->rc;
        sum = t->sum; tag = t->tag;
    }
    void pull() {
        sum = lc->sum + rc->sum;
    }
    void push(int L, int R) {
        if (L == R) return;
        int M = (L + R) >> 1;
        if (lc) lc->sum += (M - L + 1) * tag, lc->tag += tag;
        if (rc) rc->sum += (R - M) * tag, rc->tag += tag;
        tag = 0;
    }
    int query(int L, int R, int x) {
        push(L, R);
        if (L == R) return sum;
        int M = (L + R) >> 1;
        if (x <= M) return lc->query(L, M, x);
        return rc->query(M + 1, R, x);
    }
} *st[maxn];

int a[maxn], v[maxn], n, m, q;
vector<int> job[maxn];

Seg* modify(Seg*, int, int, int, int, int);
int bs(int, int, int);
bool check(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; ++i) cin >> a[i], job[a[i]].push_back(i);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    st[0] = new Seg(1, m);
    cerr << "jizz\n";
    for (int i = 1; i <= q; ++i) {
        int l, r, c; cin >> l >> r >> c;
        st[i] = modify(st[i - 1], 1, m, l, r, c);
    }
    for (int i = 1; i <= n; ++i) {
        int ans = bs(i, 0, q + 1);
        cout << ans << '\n';
    }
    return 0;
}

Seg* modify(Seg* t, int L, int R, int l, int r, int v) {
    cerr << "modify: L = " << L << " R = " << R << '\n';
    t->push(L, R);
    Seg* ret = new Seg(t);
    if (L > r || l > R) return ret;
    if (L >= l && R <= r) {
        ret->sum += (R - L + 1) * v;
        ret->tag += v;
        return ret;
    }
    int M = (L + R) >> 1;
    ret->lc = modify(t->lc, L, M, l, r, v);
    ret->rc = modify(t->rc, M + 1, R, l, r, v);
    ret->pull();
    return ret;
}

int bs(int id, int l, int r) {
    if (r - l == 1) return l;
    int m = (l + r) >> 1;
    if (check(id, m)) return bs(id, l, m);
    return bs(id, m, r);
}

bool check(int id, int x) {
    cerr << "id: " << id << " x: " << x << '\n';
    int tot = 0;
    for (int i : job[id]) tot += st[x]->query(1, m, i);
    cerr << "tot: " << tot << '\n';
    return tot >= v[id];
}
