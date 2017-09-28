#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
map<vector<int>, int> sg;

int go(vector<int>& v) {
    // cout << "go: " << v[0] << ' ' << v[1] << ' ' << cur << endl;
    sort(v.begin(), v.end());
    if (sg.count(v)) return sg[v];
    if (*max_element(v.begin(), v.end()) == 0) return 0;
    vector<int> g = vector<int>(v.begin(), v.end());
    bitset<maxn> vis;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 1; j <= v[i]; ++j) {
            g[i] = v[i] - j;
            int k = go(g);
            if (k < maxn) vis[k] = true;
            g[i] = v[i];
        }
    }
    for (int i = 1; i <= *min_element(v.begin(), v.end()); ++i) {
        for (int j = 0; j < v.size(); ++j) g[j] = v[j] - i;
        int k = go(g);
        if (k < maxn) vis[k] = true;
    }
    for (int i = 0; ; ++i) {
        if (!vis[i]) return sg[v] = i;
    }
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int s = go(a);
    if (s) cout << "BitLGM" << endl;
    else cout << "BitAryo" << endl;
    return 0;
}
