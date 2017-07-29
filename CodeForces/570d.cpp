#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
int cnt[26][maxn], dep[maxn], tin[maxn], tout[maxn], tot;
vector<int> G[maxn], node[maxn];

struct prefix {
    int cnt[26];
    prefix() {
        memset(cnt, 0, sizeof(cnt));
    }
}; vector<prefix> pref[maxn];

void dfs(int now, int d) {
    node[d].push_back(now);
    dep[now] = d;
    tin[now] = ++tot;
    for (int u : G[now]) dfs(u, d + 1);
    tout[now] = tot;
}

bool anc(int a, int b) {
    return tin[a] < tin[b] && tout[b] <= tout[a];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        G[p].push_back(i);
    }
    dfs(1, 1);
    string s; cin >> s;
    for (int i = 1; i < maxn; ++i) if (node[i].size()) {
        sort(node[i].begin(), node[i].end(), [=](const int& a, const int& b) { return tin[a] < tin[b]; });
        pref[i].resize((int)node[i].size()); ++pref[i][0].cnt[s[node[i][0] - 1] - 'a'];
        for (int j = 1; j < node[i].size(); ++j) {
            for (int k = 0; k < 26; ++k) pref[i][j].cnt[k] = pref[i][j - 1].cnt[k];
            ++pref[i][j].cnt[s[node[i][j] - 1] - 'a'];
        }
    }
    int lg = 1; while (lg <= n) lg <<= 1;
    while (m--) {
        int v, h, d; cin >> v >> h;
        if (h < dep[v]) {
            cout << "Yes" << endl;
            continue;
        }
        // int r = 0, l = node[h].size() - 1;
        int l = lower_bound(node[h].begin(), node[h].end(), v, [=](const int& a, const int& b) { return tin[a] < tin[b]; }) - node[h].begin();
        int r = lower_bound(node[h].begin(), node[h].end(), v, [=](const int& a, const int& b) { return tout[a] <= tout[b]; }) - node[h].begin();
        cout << l << ' ' << r << endl;
        /* d = lg; while (d >>= 1) if (l - d >= 0) if (anc(v, node[h][l - d])) l -= d;
        d = lg; while (d >>= 1) if (r + d < node[h].size()) if (anc(v, node[h][r + d])) r += d; */
        int e = 0, o = 0;
        for (int i = 0; i < 26; ++i) {
            int a = pref[h][r].cnt[i], b = (l == 0 ? 0 : pref[h][l - 1].cnt[i]);
            if ((a - b) & 1) ++o;
            else ++e;
        }
        if (o > 1) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}
