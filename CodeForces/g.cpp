#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set<pair<int, int>> s;
const int maxn = 3e5;

template <typename T = long long> T rnd(T l, T r) {
    return rand() * 1ll * rand() % (r - l + 1) + l;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(nullptr));
    freopen("in.txt", "w", stdout);
    cout << maxn << endl;
    for (int i = 1; i <= maxn; ++i) cout << rnd(0, 1000000000) << ' '; cout << endl;
    for (int i = 1; i <= maxn; ++i) cout << (char)('a' + rnd(0, 25)); cout << endl;
    vector<int> vec;
    for (int i = 1; i <= maxn; ++i) vec.push_back(i);
    random_shuffle(vec.begin(), vec.end());
    for (int i = 1; i < maxn; ++i) {
        int p = rnd(0, i - 1);
        cout << vec[p] << ' ' << vec[i] << endl;
    }
    return 0;
}
