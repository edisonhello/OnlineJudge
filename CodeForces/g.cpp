#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set<pair<int, int>> s;
const int maxn = 20;

template <typename T = long long> T rnd(T l, T r) {
    return rand() * 1ll * rand() % (r - l + 1) + l;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(nullptr));
    freopen("in.txt", "w", stdout);
    cout << maxn << ' ' << rnd(1, maxn) << endl;
    for (int i = 0; i < maxn; ++i) cout << rnd<long long>(1, 1000000000) << ' '; cout << endl;
    return 0;
}
