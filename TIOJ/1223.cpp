#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;
pair<int, int> p[maxn], qry[maxn], ans[maxn];
int rm[maxn];

pair<int, int> cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first != b.first) return a.first > b.first ? a : b;
    return a.second < b.second ? a : b;
}

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    pair<int, int> sum;
    SegmentTree(int L, int R) {
        lc = rc = nullptr; sum = make_pair(0, L);
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    ~SegmentTree() {
        if (lc) delete lc;
        if (rc) delete rc;
    }
    void pull() {
        sum = cmp(lc->sum, rc->sum);
    }
    void modify(int L, int R, int x, int v) {
        if (L == R) { sum.first += v; return; }
        if (x <= M) lc->modify(L, M, x, v);
        else rc->modify(M + 1, R, x, v);
        pull();
    }
    pair<int, int> query(int L, int R, int l, int r) {
        if (L > r || l > R) return make_pair(-inf, 0);
        if (L >= l && R <= r) return sum;
        return cmp(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
#undef M
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, t; while (cin >> n >> t, n || t) {
        int m; cin >> m;
        vector<int> vec;
        for (int i = 0; i < m; ++i) {
            cin >> rm[i] >> p[i].first >> p[i].second;
            vec.push_back(p[i].first); vec.push_back(p[i].second);
        }
        int q; cin >> q;
        for (int i = 0; i < q; ++i) {
            cin >> qry[i].first; vec.push_back(qry[i].first);
            qry[i].second = i;
        }
        sort(vec.begin(), vec.end()); vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
        vector<pair<pair<int, int>, pair<int, int>>> sw;
        st = new SegmentTree(1, n);
        for (int i = 0; i < m; ++i) {
            int l = lower_bound(vec.begin(), vec.end(), p[i].first) - vec.begin(), r = lower_bound(vec.begin(), vec.end(), p[i].second) - vec.begin();
            sw.push_back(make_pair(make_pair(l, r), make_pair(rm[i], p[i].second - p[i].first)));
            st->modify(1, n, rm[i], p[i].first - p[i].second);
        }
        sort(sw.begin(), sw.end(), [](const pair<pair<int, int>, pair<int, int>>& a, const pair<pair<int, int>, pair<int, int>> & b) { 
            return a.first.second < b.first.second ;
        });
        sort(qry, qry + q);
        int ind = 0;
        for (int i = 0; i < q; ++i) {
            int pos = lower_bound(vec.begin(), vec.end(), qry[i].first) - vec.begin();
            while (ind < sw.size() && sw[ind].first.second <= pos) {
                st->modify(1, n, sw[ind].second.first, sw[ind].second.second);
                ++ind;
            }
            auto res = st->query(1, n, 1, n);
            if (t - qry[i].first + res.first > 0) ans[qry[i].second] = make_pair(res.second, t - qry[i].first + res.first);
            else ans[qry[i].second] = make_pair(-1, -1);
        }
        for (int i = 0; i < q; ++i) {
            if (ans[i] == make_pair(-1, -1)) cout << "Oh, no!" << endl;
            else cout << ans[i].first << ' ' << ans[i].second << endl;
        }
        delete st;
    }
    return 0;
}
