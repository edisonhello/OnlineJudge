#include <bits/stdc++.h>
using namespace std;

const int maxn = 300 + 5, inf = 1e9 + 1;
int w[maxn], m, t, r;

int doo();

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> m >> t >> r;
    for (int i = 0; i < m; ++i) cin >> w[i];
    cout << doo() << endl;;
    return 0;
}

int doo() {
    multiset<int> lit;
    int used = 0, last = 0;
    for (int i = 0; i < m; ++i) {
        int cnt = 0;
        for (int j : lit) {
            if (j >= w[i]) ++cnt;
            else lit.erase(lit.find(j));
        }
        if (w[i] - r + cnt + 1 <= last) return -1;
        for (int j = w[i] - r + cnt + 1; j <= w[i]; ++j) {
            if (j + t < w[i]) return -1;
            lit.insert(j + t); ++used;
        }
    }
    return used;
}
