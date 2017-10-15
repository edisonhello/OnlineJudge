#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set<pair<int, int>> s;
const int maxn = 1e5;

template <typename T> T rnd(T l, T r) {
    return rand() * 1ll * rand() % (r - l + 1) + l;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(nullptr));
    freopen("in.txt", "w", stdout);
    // cout << maxn << endl;
    // for (int i = 1; i <= maxn; ++i) cout << rnd(1, maxn) << ' '; cout << endl;
    cout << maxn << ' ' << maxn << endl;
    for (int i = 0; i < maxn; ++i) cout << rnd(1, maxn) << ' '; cout << endl;
    for (int i = 0; i < maxn; ++i) {
        int t = rnd(0, 1); cout << t << ' ';
        if (t == 0) cout << rnd(1, maxn) << ' ' << rnd(1, maxn) << endl;
        else cout << rnd(1, maxn) << endl;
    }
    return 0;
}
