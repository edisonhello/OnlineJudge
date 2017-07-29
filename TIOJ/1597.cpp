#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

const int maxn = 4e4 + 10;
const long long inf = LLONG_MAX;
int a, b;
long long dis[maxn], ans;
bool v[maxn];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

struct Edge {
    int a, b;
    long long c, p;
}; vector<Edge> G[maxn];

int ts(int, int);
bool check(int);
long long dijkstra(int, int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, d; cin >> n >> m >> a >> b >> d;
    while (m--) {
        int n1, n2; long long c1, p1, c2, p2; cin >> n1 >> n2 >> c1 >> p1 >> c2 >> p2;
        G[n1].push_back((Edge){ n1, n2, c1, p1 });
        G[n2].push_back((Edge){ n2, n1, c2, p2 });
    }
    ans = min(dijkstra(a, b, 0), dijkstra(a, b, d - 1));
    int q = ts(0, d);
    cout << dijkstra(a, b, q) - ans << endl;
    return 0;
}

int ts(int l, int r) {
    if (r - l == 1) return l;
    int m = (l + r) >> 1;
    if (check(m)) return ts(l, m);
    return ts(m, r);
}

bool check(int m) {
    long long d1 = dijkstra(a, b, m), d2 = dijkstra(a, b, m - 1);
    if (d1 == d2) {
        cout << d1 - ans << endl;
        exit(0);
    }
    return d1 < d2;
}

long long dijkstra(int s, int t, int d) {
    long long ret = 0;
    memset(v, false, sizeof(v));
    fill(dis, dis + maxn, inf);
    while (pq.size()) pq.pop();
    dis[s] = 0; pq.push(make_pair(0, s));
    while (pq.size()) {
        pair<long long, int> p = pq.top(); pq.pop();
        if (p.second == t) break;
        if (v[p.second]) continue;
        v[p.second] = true;
        for (Edge e : G[p.second]) {
            if (e.c + (long long)d * e.p + p.first < dis[e.b]) {
                dis[e.b] = p.first + e.c + (long long)d * e.p;
                pq.push(make_pair(dis[e.b], e.b));
            }
        }
    }
    ret += dis[t];
    memset(v, false, sizeof(v));
    fill(dis, dis + maxn, inf);
    while (pq.size()) pq.pop();
    dis[t] = 0; pq.push(make_pair(0, t));
    while (pq.size()) {
        pair<long long, int> p = pq.top(); pq.pop();
        if (p.second == s) break;
        if (v[p.second]) continue;
        v[p.second] = true;
        for (Edge e : G[p.second]) {
            if (e.c + (long long)d * (long long)e.p + p.first < dis[e.b]) {
                dis[e.b] = p.first + e.c + (long long)d * e.p;
                pq.push(make_pair(dis[e.b], e.b));
            }
        }
    }
    return ret + dis[s];
}
