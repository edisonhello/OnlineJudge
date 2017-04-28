#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, x, y; cin >> n >> m;
    int maxx = INT_MIN, minx = INT_MAX;
    for (int i = 0; i < m; ++i) {
        cin >> x;
        maxx = max(maxx, x);
        minx = min(minx, x);
    }
    int maxy = INT_MIN, miny = INT_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> y;
        maxy = max(maxy, y);
        miny = min(miny, y);
    }
    int lenx = (maxx - minx) % mod, leny = (maxy - miny) % mod;
    int mul = (long long)(n - 1) * (long long)(m - 1) % mod;
    cout << ((long long)lenx * (long long)leny % mod * (long long)mul) % mod << '\n';
    return 0;
}
