#include <bits/stdc++.h>
using namespace std;

const int maxn = 300000 + 5;
vector<int> del;
vector<pair<int, int>> G[maxn];
bool p[maxn], v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k, d, pos; cin >> n >> k >> d;
    for (int i = 0; i < k; ++i) cin >> pos, p[pos] = true;
    for (int i = 1; i <= n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(make_pair(b, i));
        G[b].push_back(make_pair(a, i));
    }
    queue<int> que;
    for (int i = 1; i <= n; ++i) if (p[i]) que.push(i);
    while (que.size()) {
        int cur = que.front(); que.pop();
        if (v[cur]) continue;
        v[cur] = true;
        for (pair<int, int> edge : G[cur]) {
            if (v[edge.first]) del.push_back(edge.second);
            que.push(edge.first);
        }
    }
    cout << del.size() << '\n';
    for (int i : del) cout << i << ' '; cout << '\n';
    return 0;
}
