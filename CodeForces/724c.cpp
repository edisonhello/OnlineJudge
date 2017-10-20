#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 1;
int x, y, n, m;

template <typename T> tuple<T, T, T> extgcd(T a, T b) {
    if (!b) return make_tuple(a, 1, 0);
    T d, x, y;
    tie(d, x, y) = extgcd(b, a % b);
    return make_tuple(d, y, x - (a / b) * y);
}

void solve(int diff, int& ans) {
    int g = __gcd(n, m) * 2;
    if (diff % g) return;
    int a, b, d; tie(d, a, b) = extgcd<int>(2 * m, -2 * n);
    cout << "pa = " << a << " pb = " << b << endl;
    // a *= diff / g; b *= diff / g;
    cout << "a = " << a << " b = " << b << endl;
    cout << "x = " << x + 2 * m * a << " y = " << y + 2 * n * b << endl;
    int k = ceil((double)(-x - 2 * m * a) / (double)(2 * m * n));
    cout << "k = " << k << endl;
    int nx = x + 2 * m * (a + n * k), ny = y + 2 * n * (b + m * k);
    cout << "nx = " << nx << " ny = " << ny << endl;
    assert(nx == ny);
    ans = min(ans, nx);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int k; cin >> n >> m >> k;
    while (k--) {
        cin >> x >> y;
        if (x == y) {
            cout << x << endl;
            continue;
        }
        int ans = inf;
        int g = __gcd(m, n) * 2;
        solve(y - x, ans);
        solve(y + x, ans);
        solve(-y - x, ans);
        solve(x - y, ans);
        cout << (ans == inf ? -1 : ans) << endl;
    }
    return 0;
}
