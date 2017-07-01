#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10, inf = 1e9 + 1;
pair<int, int> p[maxn];
vector<pair<int, int>> G[maxn];
int d[maxn];
bool v[maxn];

int main() {
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) cin >> p[i].first >> p[i].second;
    // p[k] = make_pair(n, m);
    for (int i = 0; i < k; ++i) for (int j = i + 1; j < k; ++j) {
        int a = abs(p[i].first - p[j].first), b = abs(p[i].second - p[j].second);
        if (a == 0 &&  b == 1 || a == 1 && b == 0) {
            G[i].push_back(make_pair(j, 0)); G[j].push_back(make_pair(i, 0));
        } else if (a <= 1 || b <= 1) {
            G[i].push_back(make_pair(j, 1)); G[j].push_back(make_pair(i, 1));
        }
    }
    for (int i = 0; i < k; ++i) {
        int a = abs(p[i].first - n), b = abs(p[i].second - m);
        if (a == 0 && b == 0) G[i].push_back(make_pair(k, 0));
        if (a <= 1 || b <= 1) G[i].push_back(make_pair(k, 1));
    }
    fill(d, d + maxn, inf);
    d[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 0));
    while (pq.size()) {
        pair<int, int> tmp = pq.top(); pq.pop();
        if (v[tmp.second]) continue;
        v[tmp.second] = true;
        for (auto e : G[tmp.second]) {
            if (d[e.first] > tmp.first + e.second) {
                d[e.first] = tmp.first + e.second;
                pq.push(make_pair(d[e.first], e.first));
            }
        }
    }
    cout << d[3] << endl;
    int ans = d[k] == inf ? -1 : d[k]; cout << ans << endl;
    return 0;
}
