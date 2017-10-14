#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set<pair<int, int>> s;
const int maxn = 100000;

template <typename T> T rnd(T l, T r) {
    return rand() * 1ll * rand() % (r - l) + l;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(nullptr));
    freopen("in.txt", "w", stdout);
    cout << maxn << endl;
    for (int i = 1; i <= maxn; ++i) cout << rnd(1, maxn) << ' '; cout << endl;
    return 0;
}
