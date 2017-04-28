#include <bits/stdc++.h>
using namespace std;

struct Seg {
    Seg *lc, *rc;
    vector<pair<int, int>> G;
    Seg(int L, int R) {
        G.clear();
        if (L == R) return;
        int M = (L + R) >> 1;
        lc = new Seg(L, M); rc = new Seg(M + 1, R);
    }
    void modify(int L, int R, int l, int r, vector<pair<int, int>> v) {
        push(L, R);
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            for (auto i : v) G.push_back(i);
            return;
        }
        int M = (L + R) >> 1;
        lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
    }
    vector<pair<int, int>> query(int L, int R, int x) {
        push(L, R);
        if (L == R) return G;
        int M = (L + R) >> 1;
        if (x <= M) return lc->query(L, M, x);
        else return rc->query(M + 1, R, x);
    }
    void push(int L, int R) {
        if (L == R) return;
        if (G.empty()) return;
        for (auto i : G) lc->G.push_back(i);
        for (auto i : G) rc->G.push_back(i);
        G.clear();
    }
} *st;

const int maxn = 100000 + 5;
long long dis[maxn];
bool v[maxn];

struct Heap {
    int id;
    long long dis;
    bool operator>(const Heap& rhs) const {
        return dis > rhs.dis;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q, s; cin >> n >> q >> s;
    st = new Seg(1, n);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int v, u, w; cin >> v >> u >> w;
            vector<pair<int, int>> mod; mod.push_back(make_pair(u, w));
            st->modify(1, n, v, v, mod);
        }
        if (t == 2) {
            int v, l, r, w; cin >> v >> l >> r >> w;
            vector<pair<int, int>> mod;
            for (int i = l; i <= r; ++i) mod.push_back(make_pair(i, w));
            st->modify(1, n, v, v, mod);
        }
        if (t == 3) {
            int v, l, r, w; cin >> v >> l >> r >> w;
            vector<pair<int, int>> mod; mod.push_back(make_pair(v, w));
            st->modify(1, n, l, r, mod);
        }
    }
    fill(dis, dis + maxn, LLONG_MAX); dis[s] = 0;
    priority_queue<Heap, vector<Heap>, greater<Heap>> pq; pq.push((Heap){ s, 0 });
    while (pq.size()) {
        Heap h = pq.top(); pq.pop();
        if (v[h.id]) continue;
        v[h.id] = true;
        vector<pair<int, int>> G = st->query(1, n, h.id);
        for (auto i : G) {
            if (i.second + h.dis < dis[i.first]) {
                dis[i.first] = i.second + h.dis;
                pq.push((Heap){ i.first, dis[i.first] });
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << (dis[i] == LLONG_MAX ? -1 : dis[i]) << ' ';
    cout << '\n';
    return 0;
}
