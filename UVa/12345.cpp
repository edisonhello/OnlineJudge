#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10, maxv = 1e6 + 10;
int a[maxn], ans[maxn], cur, upd[maxn], l, r, cnt[maxv];
vector<pair<int, int>> mod;

struct query {
    int l, r, t, block, id;
    bool operator<(const query& rhs) const {
        return block == rhs.block ? r == rhs.r ? t < rhs.t : r < rhs.r : block < rhs.block;
    }
};
vector<query> qry;

void addt(int now) {
    // cout << "adding t = " << now << endl;
    int k = a[mod[now].first];
    a[mod[now].first] = mod[now].second;
    mod[now].second = k;
    if (mod[now].first >= l && mod[now].first <= r) {
        --cnt[k];
        if (cnt[k] == 0) --cur;
        if (cnt[a[mod[now].first]] == 0) ++cur;
        ++cnt[a[mod[now].first]];
    }
}

void add(int now) {
    // cout << "adding now = " << now << " a[now] = " << a[now] << endl;
    if (cnt[a[now]] == 0) ++cur;
    ++cnt[a[now]];
}

void sub(int now) {
    // cout << "subing now = " << now << " a[now] = " << a[now] << endl;
    --cnt[a[now]];
    if (cnt[a[now]] == 0) --cur;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; while (cin >> n >> m) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int t = 0, ind = 0;
        mod.clear(); qry.clear();
        int lim = ceil(pow(n, 2.0 / 3.0));
        mod.emplace_back(0, 0);
        while (m--) {
            char c; int x, y; cin >> c >> x >> y;
            ++x;
            if (c == 'M') {
                ++t;
                mod.emplace_back(x, y);
            } else {
                int blk = x / lim;
                qry.push_back((query){ x, y, t, blk, ind++ });
            }
        }
        sort(qry.begin(), qry.end());
        // cout << "bang" << endl;
        int tn = 0; cur = 0; l = 1, r = 0;
        for (auto q : qry) {
            // cout << q.l << ' ' << q.r << ' ' << q.id << ' ' << q.t << endl;
            while (tn < q.t) addt(++tn);
            while (tn > q.t) addt(tn--);
            while (r < q.r) add(++r);
            while (r > q.r) sub(r--);
            while (l > q.l) add(--l);
            while (l < q.l) sub(l++);
            ans[q.id] = cur;
        }
        for (int i = 0; i < ind; ++i) cout << ans[i] << endl;
    }
    return 0;
}
