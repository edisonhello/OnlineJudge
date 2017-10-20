#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set<pair<int, int>> s;
const int maxn = 1e5;

template <typename T = long long> T rnd(T l, T r) {
    return rand() * 1ll * rand() % (r - l + 1) + l;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(nullptr));
    freopen("in.txt", "w", stdout);
    cout << maxn << ' ' << maxn << endl;
    for (int i = 0; i < maxn; ++i) cout << rnd<long long>(1, 1000000000) << ' '; cout << endl;
    for (int i = 0; i < maxn; ++i) {
        int t = rnd(1, 2), l = rnd(1, maxn), r = rnd(1, maxn);
        cout << t << ' ' << min(l, r) << ' ' << max(l, r);
        if (t == 1) {
            int x = rnd(1, 1000000000);
            cout << ' ' << x;
        }
        cout << endl;
    }
    return 0;
}
