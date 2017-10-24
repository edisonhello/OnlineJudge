#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set<pair<int, int>> s;
const int maxn = 1000;

template <typename T = long long> T rnd(T l, T r) {
    return rand() * 1ll * rand() % (r - l + 1) + l;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(nullptr));
    freopen("in.txt", "w", stdout);
    cout << maxn << ' ' << maxn << ' ' << maxn << endl;
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            int t = rnd(1, 2);
            if (t == 1) cout << '.';
            else cout << '#';
        }
        cout << endl;
    }
    cout << rnd(1, maxn) << ' ' << rnd(1, maxn) << ' ' << rnd(1, maxn) << ' ' << rnd(1, maxn) << endl;
    return 0;
}
