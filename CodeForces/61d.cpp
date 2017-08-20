#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<pair<int, int>> G[maxn];
int w[maxn];

long long dfs(int now, int fa) {
    sort(G[now].begin(), G[now].end(), [&](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second });
    long long ret = 0;
    for (auto u : G[now]) if (u.first != fa) {
        
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c; cin >> a >> b >> c;
        G[a].push_back(make_pair(b, c)); G[b].push_back(make_pair(a, c));
    }
    cout << dfs(1, 0) << endl;
    return 0;
}
