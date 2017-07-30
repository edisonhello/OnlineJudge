#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10;
vector<int> G[maxn];
vector<int> ans;

void dfs(int now, int st, vector<int> p) {
    p.push_back(now);
    if (p.size() > 3) return;
    for (int u : G[now]) {
        if (p.size() == 3 && u == st) {
            ans = p;
            return;
        }
        dfs(u, st, p);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < n; ++j) if (s[j] == '1') {
            G[i].push_back(j);
        }
    }
    for (int i = 0; i < n; ++i) {
        dfs(i, i, vector<int>());
        if (ans.size()) {
            for (int j : ans) cout << j + 1 << ' '; cout << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}
