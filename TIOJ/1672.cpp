#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e4 + 10;

struct dsu {
    int p[maxn], sz[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i) {
            p[i] = i; sz[i] = 1;
        }
    }
    int find(int x) {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (sz[x] > sz[y]) swap(x, y);
        sz[y] += sz[x]; p[x] = y;
    }
} dsu;

unordered_map<int, int> mp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; while (cin >> n >> m, n || m) {
        dsu.init(); mp.clear();
        bool ans = false;
        for (int i = 0; i < m; ++i) {
            int l, r, c; cin >> l >> r >> c;
            if (l > r) swap(l, r);
            if (mp.find(l - 1) == mp.end()) mp[l - 1] = mp.size() + 1;
            if (mp.find(r) == mp.end()) mp[r] = mp.size() + 1;
            l = mp[l - 1]; r = mp[r];
            if (ans) continue;
            if (c == 1) {
                if (dsu.find(l << 1) == dsu.find(r << 1) || dsu.find(l << 1 | 1) == dsu.find(r << 1 | 1)) {
                    cout << i + 1 << endl;
                    ans = true;
                }
                dsu.merge(l << 1, r << 1 | 1); dsu.merge(l << 1 | 1, r << 1);
            } else {
                if (dsu.find(l << 1 | 1) == dsu.find(r << 1) || dsu.find(l << 1) == dsu.find(r << 1 | 1)) {
                    cout << i + 1 << endl;
                    ans = true;
                }
                dsu.merge(l << 1, r << 1); dsu.merge(l << 1 | 1, r << 1 | 1);
            }
        }
        if (!ans) cout << "He didn't lie." << endl;
    }
    return 0;
}
