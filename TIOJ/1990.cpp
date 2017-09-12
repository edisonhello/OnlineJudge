#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
vector<vector<string>> vec;
int r[maxn],c[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vec.resize(n);
    for (int i = 0; i < n; ++i) vec[i].resize(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> vec[i][j];
    }
    for (int i=0;i < n; ++i) r[i] = i;
    for (int i=0;i < m; ++i) c[i] = i;
    int p; cin >> p;
    while (p--) {
        char ch; cin >> ch;
        if (ch == 'S') {
            int a, b, e, f; cin >> a >> b >> e >> f; --a, --b, --e, --f;
            // cout <<vec[r[a]][c[b]]<<' '<<vec[r[e]][c[f]]<<endl;
            swap(vec[r[a]][c[b]], vec[r[e]][c[f]]);
        }
        if (ch == 'R') {
            int a, b; cin >> a >> b; --a; --b;
            swap(r[a], r[b]);
        }
        if (ch == 'C') {
            int a, b; cin >> a >> b; --a; --b;
            swap(c[a], c[b]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << vec[r[i]][c[j]] << ' ';
        cout << '\n';
    }
    return 0;
}
