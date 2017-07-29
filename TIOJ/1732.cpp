#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        for (int i = 0; i < n; ++i) cin >> a[i];
        nth_element(a, a + n / 2, a + n);
        int ans = 0;
        for (int i = 0; i < n; ++i) ans += abs(a[i] - a[n / 2]);
        cout << ans << '\n';
    }
    return 0;
}
