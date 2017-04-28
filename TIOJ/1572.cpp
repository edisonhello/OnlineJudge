#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int maxn = 1000000 + 5;
int n, m, s, t, d[maxn], dp[maxn];
bool v[maxn];

struct Edge { int a, b, w; };
struct Heap {
    int id, w;
    bool operator>(const Heap& h) const {
        return w == h.w ? id > h.id : w > h.w;
    }
};
vector<Edge> G[maxn];
vector<int> path;

void back(int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> s >> t;
    while (m--) {
        int a, b, w; cin >> a >> b;
        G[a].push_back((Edge){ a, b, 1  });
        G[b].push_back((Edge){ b, a, 1  });
    }
    priority_queue<Heap, vector<Heap>, greater<Heap>> pq;
    fill(d, d + maxn, INT_MAX);
    d[s] = 0;
    dp[s] = s;
    pq.push((Heap){ s, 0 });
    while (pq.size()) {
        Heap h = pq.top(); pq.pop();
        if (v[h.id]) continue;
        v[h.id] = true;
        for (auto e : G[h.id]) {
            if (e.w + h.w < d[e.b]) d[e.b] = e.w + h.w, pq.push((Heap){ e.b, d[e.b] }), dp[e.b] = h.id;
        }
    }
    cout << d[t] - 1 << '\n';
    back(t);
    for (int i = path.size() - 1; i >= 1; --i) cout << path[i] << "-";
    cout << path[0] << '\n';
    return 0;
}

void back(int x) {
    path.push_back(x);
    if (x == dp[x]) return;
    back(dp[x]);
}
