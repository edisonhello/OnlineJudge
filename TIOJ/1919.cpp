#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;
int a[maxn], v[maxn], n, m, q, ans[maxn], tmp[maxn], rb[maxn];

struct photo {
    int l, r, c, t;
    bool operator<(const photo& rhs) const {
        return l < rhs.l;
    }
};

vector<int> ai[maxn];

struct fenwick {
    int data[maxn];
    void init() {
        memset(data, 0, sizeof(data));
    }
    void add(int x, int v) {
        for (int i = x; i < maxn; i += i & -i) data[i] += v;
    }
    int qry(int x) {
        int ret = 0;
        for (int i = x; i; i -= i & -i) ret += data[i];
        return ret;
    }
} bit;

void bs(const vector<int>& po, const vector<int>& land, const vector<photo>& ph, int l, int r) {
    if (po.size() == 0) return;
    if (l == r) {
        for (int i : po) ans[i] = l;
        return;
    }
    int mid = (l + r) >> 1;
    size_t ptr = 0;
    for (int ld : land) {
        while (ptr < ph.size() && ph[ptr].l <= ld) {
            if (ph[ptr].t <= mid) bit.add(ph[ptr].r, ph[ptr].c);
            ++ptr;
        }
        tmp[a[ld]] += bit.qry(rb[ld]) - bit.qry(ld - 1);
    }
    size_t pptr = 0;
    for (; pptr < ptr; ++pptr) if (ph[pptr].t <= mid) bit.add(ph[pptr].r, -ph[pptr].c);
    vector<int> pl, pr, ll, lr;
    vector<photo> phl, phr;
    for (auto i : ph) {
        if (i.t <= mid) phl.push_back(i);
        else phr.push_back(i);
    }
    for (int i : land) {
        if (tmp[a[i]] < v[a[i]]) lr.push_back(i);
        else ll.push_back(i);
    }
    for (int i : po) {
        if (tmp[i] < v[i]) {
            v[i] -= tmp[i];
            pr.push_back(i);
        } else {
            pl.push_back(i);
        }
        tmp[i] = 0;
    }
    bs(pl, ll, phl, l, mid); bs(pr, lr, phr, mid + 1, r);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
        ai[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        for (size_t j = 0; j < ai[i].size(); ++j) {
            if (j + 1 == ai[i].size()) rb[ai[i][j]] = m;
            else rb[ai[i][j]] = ai[i][j + 1] - 1;
        }
    }
    vector<photo> ph;
    for (int i = 1; i <= n; ++i) cin >> v[i];
    for (int i = 0; i < q; ++i) {
        int l, r, c; cin >> l >> r >> c;
        ph.push_back((photo){ l, r, c, i });
    }
    ph.push_back((photo){ 1, m, inf, q });
    sort(ph.begin(), ph.end());
    vector<int> vec, land;
    for (int i = 1; i <= n; ++i) vec.push_back(i);
    for (int i = 1; i <= m; ++i) land.push_back(i);
    bit.init();
    bs(vec, land, ph, 0, q);
    for (int i = 1; i <= n; ++i) cout << (ans[i] == q ? -1 : ans[i] + 1) << endl;
    return 0;
}
