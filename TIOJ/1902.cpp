#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, maxd = 30;
int a[maxn], xo[maxn], XOR, ans[maxn];

struct Query {
    int l, r, id, block;
    bool operator<(const Query& rhs) const {
        return block == rhs.block ? r < rhs.r : block < rhs.block;
    }
} qry[maxn];

struct Trie {
    Trie *ch[2];
    int cnt;
    Trie() {
        ch[0] = ch[1] = nullptr;
        cnt = 0;
    }
    void insert(int x, int dep) {
        // cout << "insert: x = " << x << " dep = " << dep << endl;
        if (dep < -1) return;
        int bit = (x >> dep) & 1;
        if (!ch[bit]) ch[bit] = new Trie();
        ++ch[bit]->cnt;
        ch[bit]->insert(x, dep - 1);
    }
    void remove(int x, int dep) {
        if (dep < -1) return;
        int bit = (x >> dep) & 1;
        --ch[bit]->cnt;
        ch[bit]->remove(x, dep - 1);
    }
    int query(int x, int dep) {
        if (dep < 0) return 0;
        int bit = (x >> dep) & 1;
        if (ch[!bit] && ch[!bit]->cnt > 0) return ch[!bit]->query(x, dep - 1) + (1 << dep);
        return ch[bit]->query(x, dep - 1);
    }
} *t;

void add(int);
void sub(int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    xo[0] = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], xo[i] = xo[i - 1] ^ a[i];
    int lim = 1 + (int)sqrt(n);
    t = new Trie(); t->insert(0, maxd);
    for (int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;
        qry[i] = (Query){  l, r, i, l / lim };
    }
    sort(qry, qry + q);
    for (int i = 0, R = 0, L = 1; i < q; ++i) {
        while (R < qry[i].r) add(++R);
        while (R > qry[i].r) sub(R--);
        while (L > qry[i].l) add(--L);
        while (L < qry[i].l) sub(L++);
        ans[qry[i].id] = XOR;
    }
    for (int i = 0; i < q; ++i) cout << ans[i] << endl;
    return 0;
}

void add(int x) {
    // cout << "add: " << x << endl;
    XOR = max(XOR, t->query(xo[x], maxd));
    t->insert(xo[x], maxd);
}

void sub(int x) {
    // cout << "sub: " << x << endl;
    t->remove(xo[x], maxd);
}
