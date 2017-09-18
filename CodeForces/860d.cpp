#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int deg[maxn];

struct cmp {
    bool operator()(const int& a, const int& b) {
        return deg[a] > deg[b];
    }
};

set<int, cmp> G[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].insert(b); G[b].insert(a);
        ++deg[a]; ++deg[b];
    }
    set<int, cmp> nd;
    for (int i = 1; i <= n; ++i) nd.insert(i);
    vector<pair<pair<int, int>, int>> vec;
    while (true) {
        int now = *nd.rbegin();
        if (G[now].size() < 2) break;
        auto it = G[now].rbegin();
        int a = *it; --it; int b = *it;
        vec.push_back(make_pair(make_pair(a, now), b));
        deg[now] -= 2; --deg[a]; --deg[b];
        nd.erase(now); nd.erase(a); nd.erase(b);
        G[now].erase(a); G[now].erase(b);
        if (deg[now]) nd.insert(now);
        if (deg[a]) nd.insert(a), G[now].insert(a);
        if (deg[b]) nd.insert(b), G[now].insert(b);
    }
    cout << vec.size() << endl;
    for (auto i : vec) cout << i.first.first << ' ' << i.first.second << ' ' << i.second << endl;
    return 0;
}
