#include <bits/stdc++.h>
#define Size(t) (t ? t->sz : 0)
using namespace std;

const int maxn = 20000 + 5;
int a[maxn], n, k, tot;

int bs(int, int);
bool check(int);

struct Treap {
    Treap *lc, *rc;
    int pri, val, sz;
    Treap(int v) {
        lc = rc = nullptr;
        pri = rand();
        val = v;
        sz = 1;
    }
    void pull() {
        sz = Size(lc) + Size(rc) + 1;
    }
};

Treap* merge(Treap*, Treap*);
void split(Treap*, int, Treap*&, Treap*&);
void insert(Treap*&, int);
int lower_bound(Treap*, int);
void clear(Treap*);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    while (cin >> n >> k, (n || k)) {
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int ub = INT_MIN, lb = INT_MAX;
        multiset<int> s; s.insert(0);
        int cur = 0;
        for (int i = 1; i <= n; ++i) {
            cur += a[i];
            ub = max(ub, cur - *s.begin());
            lb = min(lb, cur - *s.rbegin());
            s.insert(cur);
        }
        tot = n * (n + 1) / 2;
        cout << bs(lb - 1, ub + 1) << '\n';
    }
    return 0;
}

int bs(int l, int r) {
    if (r - l == 1) return l;
    int m = (l + r) >> 1;
    if (check(m)) return bs(l, m);
    return bs(m, r);
}

bool check(int sum) {
    Treap* s = new Treap(0);
    int cur = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cur += a[i];
        int it = lower_bound(s, cur - sum);
        cnt += s->sz - it;
        insert(s, cur);
    }
    --cnt;
    clear(s);
    return cnt >= tot - k;
}

Treap* merge(Treap* a, Treap* b) {
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

void split(Treap* t, int val, Treap*& a, Treap*& b) {
    if (!t) { a = b = nullptr; return; }
    if (t->val <= val) {
        a = t;
        split(t->rc, val, a->rc, b);
        a->pull();
    } else {
        b = t;
        split(t->lc, val, a, b->lc);
        b->pull();
    }
}

void insert(Treap*& t, int val) {
    Treap *a, *b;
    split(t, val - 1, a, b);
    t = merge(merge(a, new Treap(val)), b);
}

int lower_bound(Treap* t, int val) {
    if (!t) return 0;
    if (t->val > val) return lower_bound(t->lc, val);
    return Size(t->lc) + 1 + lower_bound(t->rc, val);
}

void clear(Treap* t) {
    if (!t) return;
    if (t->lc) clear(t->lc);
    if (t->rc) clear(t->rc);
    delete t;
}
