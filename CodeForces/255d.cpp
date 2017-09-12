#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 20;
int n, x, y, c;

bool check(int t) {
    cout << "t = " << t << endl;
    long long s = 1 + 4 * t * (t + 1) / 2;
    cout << "s = " << s << endl;
    if (x - 1 < t) {
        int len = 2 * (t - x + 1) - 1;
        s -= (1 + len) * (len + 1) / 4;
    }
    if (n - x < t) {
        int len = 2 * (t - n + x) - 1;
        s -= (1 + len) * (len + 1) / 4;
    }
    if (y - 1 < t) {
        int len = 2 * (t - y + 1) - 1;
        s -= (1 + len) * (len + 1) / 4;
    }
    if (n - y < t) {
        int len = 2 * (t - n + y) - 1;
        s -= (1 + len) * (len + 1) / 4;
    }
    cout << "s = " << s << endl;
    return s >= c;
}

int32_t main() {
    cin >> n >> x >> y >> c;
    int d = 1, ans = inf; while (d < inf) d <<= 1;
    // while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    for (int i = 1; i < inf; ++i) check(i);
    cout << ans << endl;
    return 0;
}
