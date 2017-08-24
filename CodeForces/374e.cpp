#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10, inf = 1e9 + 1;
pair<int, int> a[maxn], b[maxn];
int n, m;
vector<int> vec;

struct SegmentTree {
#define M ((L + R) >> 1)
    set<pair<int, int>> s;
    SegmentTree *lc, *rc;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        s.clear();
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    ~SegmentTree {
        if (lc) delete lc;
        if (rc) delete rc;
    }
    set<pair<int, int>> merge(const set<pair<int, int>>& a, const set<pair<int, int>>& b) {
        set<pair<int, int>> ret;
        for (pair<int, int> d : a) ret.insert(d);
        for (pair<int, int> d : b) ret.insert(d);
        return ret;
    }
    void pull() {
        s = merge(lc->s, rc->s);
    }
    void modify(int L, int R, int x, pair<int, int> v) {
        if (L == R) {
            s.insert(v);
            return;
        }
        if (x <= M) lc->modify(L, M, x, v);
        else rc->modify(M + 1, R, x, v);
        pull();
    } 
    set<pair<int, int>> query(int L, int R, int l, int r) {
        if (L > r || l > R) return set<pair<int, int>>();
        if (L >= l && R <= r) return s;
        return merge(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
};

int get(const pair<int, int>& p) {
    return p.second - p.first;
}

bool check(int t) {
    SegmentTree *st1 = new SegmentTree(0, vec.size() - 1), *st2 = new SegmentTree(0, vec.size() - 1);
    for (int i = 0; i < m; ++i) {
        st1->modify(0, vec.size() - 1, lower_bound(vec.begin(), vec.end(), get(b[i])), make_pair(b[i].first - t, b[i].second - t));
        st2->modify(0, vec.size() - 1, lower_bound(vec.begin(), vec.end(), get(b[i])), make_pair(b[i].first + t, b[i].second + t));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            pair<int, int> l, r;
            if (a[i].first - t > a[j].first - t) l = make_pair(a[i].first - t, a[i].second + t);
            else l = make_pair(a[j].first - t, a[j].second + t);
            if (a[i].first + t < a[i].first + t) r = make_pair(a[i].first + t, a[j].second - t);
            else r = make_pair(a[j].first + t, a[j].second - t);
            int ll = lower_bound(vec.begin(), vec.end(), get(l)) - vec.begin(), rr = lower_bound(vec.begin(), vec.end(), get(r)) - vec.begin();
            set<int> s1 = st1->query(0, vec.size(), ll, rr), s2 = st2->query(0, vec.size(), ll, rr);
            int cnt = 0;
            while (s1.size()) {
                if (cnt >= 2) break;
                auto it = s1.begin();
                if (it->second <= l.second) ++
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    for (int i = 0; i < m; ++i) cin >> b[i].first >> b[i].second, vec.push_back(get(b[i]));
    sort(vec.begin(), vec.end()); vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    int d = 1, ans = inf; while (d < inf) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    cout << ans << endl;
    return 0;
}
