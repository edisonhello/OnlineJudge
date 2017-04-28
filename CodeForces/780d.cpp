#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
vector<int> G[maxn << 1];
string name[maxn][2];
bool v[maxn << 1];
int c, s[maxn << 1], ans[maxn];

bool dfs(int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> name[i][0] >> name[i][1];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) if (i != j) {
            if (name[j][0].substr(0, 3) == name[i][0].substr(0, 3)) {
                G[i << 1].push_back(j << 1 | 1);
                G[i << 1 | 1].push_back(j << 1 | 1);
            }
            if (name[j][0].substr(0, 2) + name[j][1].substr(0, 1) == name[i][0].substr(0, 3)) G[i << 1].push_back(j << 1);
            if (name[j][0].substr(0, 3) == name[i][0].substr(0, 2) + name[i][1].substr(0, 1)) G[i << 1 | 1].push_back(j << 1 | 1);
            if (name[j][0].substr(0, 2) + name[j][1].substr(0, 1) == name[i][0].substr(0, 2) + name[i][1].substr(0, 1)) G[i << 1 | 1].push_back(j << 1);
        }
    }
    for (int i = 0; i < n << 1; i += 2) {
        if (!v[i] && !v[i + 1]) {
            c = 0;
            if (!dfs(i)) {
                while (c) v[s[--c]] = false;
                if (!dfs(i + 1)) return cout << "NO\n", 0;
                ans[i] = 2;
            } else ans[i] = 1;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        if (ans[i] == 1) cout << name[i][0].substr(0, 3) << '\n';
        else cout << name[i][0].substr(0, 2) + name[i][1].substr(0, 1) << '\n';
    }
    return 0;
}

bool dfs(int x) {
    if (v[x ^ 1]) return false;
    if (v[x]) return true;
    v[x] = true;
    s[c++] = x;
    for (int u : G[x]) if (!dfs(u)) return false;
    return true;
}
