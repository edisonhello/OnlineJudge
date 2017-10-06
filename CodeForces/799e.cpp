#include <bits/stdc++.h>
#define int long long
#define tsum(t) (t ? t->s : 0)
#define tsize(t) (t ? t->sz : 0)
using namespace std;

const int maxn = 2e5 + 10;
const long long inf = 1e18;
int c[maxn], a[maxn], b[maxn];
bool oka[maxn], okb[maxn], useda[maxn], usedb[maxn], usedt[maxn], dela[maxn], delb[maxn];

bool cmp(const int& i, const int& j) {
    return c[i] == c[j] ? i < j : c[i] < c[j];
}

struct treap {
    treap *lc, *rc;
    int val, pri, sz, s;
    treap(int v): val(v) {
        pri = rand();
        sz = 1;
        s = val;
        lc = rc = nullptr;
    }
    void pull() {
        s = tsum(lc) + tsum(rc) + val;
        sz = tsize(lc) + tsize(rc) + 1;
    }
} *tr, *ta, *tb;

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

void split_by_size(treap *t, int k, treap *&a, treap *&b) {
    if (!t) {
        a = b = nullptr;
        return;
    }
    if (tsize(t->lc) + 1 <= k) {
        a = t;
        split_by_size(t->rc, k - tsize(t->lc) - 1, a->rc, b);
        a->pull();
    } else {
        b = t;
        split_by_size(t->lc, k, a, b->lc);
        b->pull();
    }
}

void split_by_val(treap *t, int k, treap *&a, treap *&b) {
    if (!t) {
        a = b = nullptr;
        return;
    }
    if (t->val <= k) {
        a = t;
        split_by_val(t->rc, k, a->rc, b);
        a->pull();
    } else {
        b = t;
        split_by_val(t->lc, k, a, b->lc);
        b->pull();
    }
}

void insert(treap *&tr, int val) {
    treap *a, *b;
    split_by_val(tr, val - 1, a, b);
    tr = merge(merge(a, new treap(val)), b);
}

bool erase(treap *&tr, int val) {
    treap *a, *b, *c, *d;
    split_by_val(tr, val - 1, a, b);
    split_by_val(b, val, c, d);
    bool ret = tsize(c);
    c = merge(c->lc, c->rc);
    tr = merge(a, merge(c, d));
    return ret;
}

long long get(treap* tr, int sz) {
    if (sz < 0) return inf;
    if (sz == 0) return 0;
    if (tsize(tr) < sz) return inf;
    treap *a, *b;
    split_by_size(tr, sz, a, b);
    long long ret = tsum(a);
    tr = merge(a, b);
    return ret;
}

int findmax(treap *tr) {
    if (!tr) return -inf;
    if (tr->rc) return findmax(tr->rc);
    return tr->val;
}

int32_t main() {
    srand(time(nullptr));
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    int x, y; cin >> x;
    for (int i = 1; i <= x; ++i) cin >> a[i], oka[a[i]] = true;
    cin >> y;
    for (int i = 1; i <= y; ++i) cin >> b[i], okb[b[i]] = true;
    vector<int> both, fa, fb, trash;
    for (int i = 1; i <= n; ++i) {
        if (oka[i] && okb[i]) both.push_back(i);
        else if (oka[i]) fa.push_back(i);
        else if (okb[i]) fb.push_back(i);
        else trash.push_back(i);
    }
    sort(both.begin(), both.end(), cmp);
    sort(fa.begin(), fa.end(), cmp);
    sort(fb.begin(), fb.end(), cmp);
    sort(trash.begin(), trash.end(), cmp);
    if (x < k || y < k) return cout << "-1" << endl, 0;
    if (k > m) return cout << "-1" << endl, 0;
    long long sa = 0, sb = 0, st = 0;
    vector<int> na, nb;
    int cnt = 0;
    long long ans = inf, now = 0;
    for (int i : fa) insert(ta, c[i]);
    for (int i : fb) insert(tb, c[i]);
    for (int i : trash) insert(tr, c[i]);
    for (int i : both) insert(tr, c[i]);
    size_t ptr = 0;
    for (int t = 0; t <= k; ++t) {
        ans = min(ans, now + get(tb, k - t) + get(ta, k - t) + get(tr, m - 2 * k + t));
        if (ptr == both.size()) break;
        while (tsize(ta) >= k - t) {
            if (tsize(ta) == 0) break;
            int tmax = findmax(ta);
            erase(ta, tmax); insert(tr, tmax);
        }
        while (tsize(tb) >= k - t) {
            if (tsize(tb) == 0) break;
            int tmax = findmax(tb);
            erase(tb, tmax); insert(tr, tmax);
        }
        now += c[both[ptr]];
        erase(tr, c[both[ptr]]);
        ++ptr;
    }
    cout << (ans == inf ? -1ll : ans) << endl;
    return 0;
}
