#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
vector<int> G[maxn];
vector<vector<int>> cnt[26];
int d[maxn], tin[maxn], tout[maxn], t, md;

void dfs(int now, int dep) {
    md = max(md, dep);
    d[now] = dep;
    tin[now] = ++t;
    for (int u : G[now]) dfs(u, dep + 1);
    tout[now] = t;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        G[p].emplace_back(i);
    }
    string s; cin >> s;
    dfs(1, 0);
#define nd G
    for (int i = 1; i <= n; ++i) G[i].clear();
    for (int i = 1; i <= n; ++i) G[d[i]].emplace_back(i);
    for (int i = 0; i < maxn; ++i) if (nd[i].size()) {
        sort(nd[i].begin(), nd[i].end(), [&](const int& a, const int& b) { return tin[a] < tin[b]; });
    } 
    for (int i = 0; i < 26; ++i) cnt[i].resize(md + 1);
    for (int i = 0; i <= md; ++i) if (nd[i].size()) {
        for (int j = 0; j < 26; ++j) cnt[j][i].resize(nd[i].size());
        ++cnt[s[nd[i][0] - 1] - 'a'][i][0];
        for (int j = 1; j < nd[i].size(); ++j) {
            for (int k = 0; k < 26; ++k) cnt[k][i][j] = cnt[k][i][j - 1];
            ++cnt[s[nd[i][j] - 1] - 'a'][i][j];
        }
    }    
    while (m--) {
        int v, h; cin >> v >> h; --h;
        auto itl = lower_bound(nd[h].begin(), nd[h].end(), tin[v], [&](const int& a, const int& b) { return tin[a] < b; });
        auto itr = lower_bound(nd[h].begin(), nd[h].end(), tout[v], [&](const int& a, const int& b) { return tin[a] < b; });
        if (itr != nd[h].end() && tin[*itr] > tout[v]) --itr;
        if (itr == nd[h].end()) --itr;
        auto kk = nd[h].begin(); --kk;
        if (kk == itr) { cout << "Yes\n"; continue; }
        auto b = nd[h].begin();
        vector<int> c(26);
        for (int i = 0; i < 26; ++i) c[i] = cnt[i][h][itr - b] - (itl - b == 0 ? 0 : cnt[i][h][itl - b - 1]);
        int o = 0, e = 0;
        for (int i = 0; i < 26; ++i) {
            if (c[i] & 1) ++o;
            else ++e;
        }
        // cout << "o = " << o << " e = " << e << endl;
        if (o <= 1) cout << "Yes\n";
        else cout << "No\n";
    }
#undef nd
    return 0;
}
