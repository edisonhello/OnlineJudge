#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e7 + 10;
long long a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    long long s = 0, k = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i] * i;
        k += a[i];
    }
    for (int x = 0; x <= n / 2; ++x) {
        if (s % k == 0 && s / k >= 0 && s / k < n) {
            cout << x << ' ' << s / k << endl;
            return 0;
        }
        s -= a[x] * x; s -= a[n - x - 1] * (n - x - 1);
        s += a[n - x - 1] * x; s += a[x] * (n - x - 1);
    }
    return 0;
}
