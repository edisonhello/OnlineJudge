#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
vector<int> G[maxn];
bool v[maxn], ok[maxn];

void dfs(int now) {
    v[now] = true;
    for (int u : G[now]) if (ok[u] && !v[u]) dfs(u);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n, n) {
        int edge = 0;
        fill(G, G + maxn, vector<int>());
        memset(v, false, sizeof(v));
        memset(ok, false, sizeof(ok));
        string s; getline(cin, s); getline(cin, s);
        stringstream ss(s);
        int node = 0;
        int a, b; while (ss >> a >> b) {
            ++edge;
            G[a].push_back(b); G[b].push_back(a);
            if (!ok[a]) ++node;
            if (!ok[b]) ++node;
            ok[a] = ok[b] = true;
        }
        int cc = 0;
        if (edge != node - 1) { cout << "n" << endl; continue; }
        for (int i = 1; i < maxn; ++i) if (ok[i] && !v[i]) {
            ++cc; dfs(i);
        }
        if (cc == 1) cout << "y" << endl;
        else cout << "n" << endl;
    }
}
