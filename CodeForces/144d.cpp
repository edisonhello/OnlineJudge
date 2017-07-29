#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;
vector<pair<pair<int, int>, int>> G[maxn];
int w[maxn], d[maxn], last[maxn];
bool v[maxn], used[maxn];

typedef pair<int, pair<int, int>> heap;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, s; cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        w[i] = c;
        G[a].push_back(make_pair(make_pair(b, c), i)); G[b].push_back(make_pair(make_pair(a, c), i));
    }
    int l; cin >> l;
    fill(d, d + maxn, inf);
    d[s] = 0;
    priority_queue<heap, vector<heap>, greater<heap>> pq; pq.push(make_pair(0, make_pair(s, -1)));
    while (pq.size()) {
        auto p = pq.top(); pq.pop();
        if (v[p.second.first]) continue;
        v[p.second.first] = true;
        last[p.second.first] = p.second.second;
        for (auto e : G[p.second.first]) {
            if (d[e.first.first] > p.first + e.first.second) {
                d[e.first.first] = p.first + e.first.second;
                pq.push(make_pair(d[e.first.first], make_pair(e.first.first, e.second)));
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (d[i] == l) ++ans;
    }
    for (int i = 1; i <= n; ++i) {
        if (d[i] > l) {
            for (auto e : G[i]) if (!used[e.second]) {
                if (d[i] - e.first.second < l) ++ans, used[e.second] = true;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
