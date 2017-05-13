#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int d[maxn], d_[maxn];
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k, a, b; cin >> n >> m >> k >> a >> b;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    fill(d, d + maxn, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    d[k] = 0;
    pq.push(make_pair(0, k));
    while (pq.size()) {
        pair<int, int> p = pq.top(); pq.pop();
        if (v[p.second]) continue;
        v[p.second] = true;
        for (int i = 0; i < G[p.second].size(); ++i) {
            int u = G[p.second][i];
            if (p.first + a < d[u]) {
                d[u] = p.first + a;
                pq.push(make_pair(d[u], u));
            }
        }
    }
    fill(d_, d_ + maxn, INT_MAX);
    memset(v, false, sizeof(v));
    for (int i = 1; i <= n; ++i) pq.push(make_pair(d[i], i));
    while (pq.size()) {
        pair<int, int> p = pq.top(); pq.pop();
        if (v[p.second]) continue;
        v[p.second] = true;
        for (int i = 0; i < G[p.second].size(); ++i) {
            int u = G[p.second][i];
            if (p.first + a < d_[u]) {
                d_[u] = a + p.first;
                pq.push(make_pair(d_[u], u));
            }
            if (d[u] == 2 * a) {
                d_[u] = min(b, min(d_[u], d[u]));
                pq.push(make_pair(d_[u], u));
            }
            if (d[u] < d_[u]) {
                d_[u] = d[u];
                pq.push(make_pair(d_[u], u));
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << d_[i] << '\n'; 
    return 0;
}
