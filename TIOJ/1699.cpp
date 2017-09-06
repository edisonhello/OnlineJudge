#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10, maxq = 1e5 + 10;

struct query {
    int l, r, k, id, block;
    bool operator<(const query& rhs) const {
        return block == rhs.block ? r < rhs.r : block < rhs.block;
    }
} qry[maxq];

int a[maxn], cnt[maxn], has[maxn], bst;
bool ans[maxq];

void add(int now) {
    --has[cnt[a[now]]];
    ++cnt[a[now]];
    ++has[cnt[a[now]]];
    while (has[bst + 1]) ++bst;
}

void sub(int now) {
    --has[cnt[a[now]]];
    --cnt[a[now]];
    ++has[cnt[a[now]]];
    while (!has[bst]) --bst;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> vec;
    for (int i = 1; i <= n; ++i) cin >> a[i], vec.push_back(a[i]);
    sort(vec.begin(), vec.end()); vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    for (int i = 1; i <= n; ++i) a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin() + 1;
    int lim = 1 + (int)sqrt(n);
    for (int i = 0; i < q; ++i) {
        int k;
        cin >> qry[i].l >> qry[i].r >> k;
        qry[i].k = (qry[i].r - qry[i].l + 1) / k;
        if ((qry[i].r - qry[i].l + 1) % k) ++qry[i].k;
        qry[i].id = i;
        qry[i].block = qry[i].l / lim;
    }
    sort(qry, qry + q);
    for (int i = 0, l = 1, r = 0; i < q; ++i) {
        while (r < qry[i].r) add(++r);
        while (r > qry[i].r) sub(r--);
        while (l > qry[i].l) add(--l);
        while (l < qry[i].l) sub(l++);
        ans[qry[i].id] = (bst >= qry[i].k);
    }
    for (int i = 0; i < q; ++i) cout << (ans[i] ? "Yes" : "No") << endl;
    return 0;
}
