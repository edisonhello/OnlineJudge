#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
int v[maxn];
map<int, pair<int, int>> mp[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    // srand(7122);
    while (m--) {
        int t; cin >> t;
        if (t == 0) {
            int a, b; cin >> a >> b;
            if (a > b) swap(a, b);
            if (mp[a].find(b) == mp[a].end()) {
                int r = rand();
                mp[a][b] = make_pair(r, 0); v[a] ^= r;
                v[b] ^= r;
            }
            mp[a][b].second++;
        }
        if (t == 1) {
            int c, d; cin >> c >> d;
            if (c > d) swap(c, d);
            mp[c][d].second--;
            if (mp[c][d].second == 0) {
                v[c] ^= mp[c][d].first;
                v[d] ^= mp[c][d].first;
                mp[c].erase(d);
            }
        }
        if (t == 2) {
            int k, Xor = 0; cin >> k;
            for (int j = 0; j < k; ++j) {
                int a; cin >> a;
                Xor ^= v[a];
            }
            if (Xor == 0) cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}
