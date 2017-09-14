#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10, inf = 1e9;
int a[maxn];

int main() {
    int n; cin >> n;
    int low = inf;
    for (int i = 1; i <= n; ++i) {
        int t, x; cin >> t >> x;
        if (t == 0) a[i] = a[i - 1] + x;
        else a[i] = a[i - 1] - x;
        low = min(low, a[i]);
    }
    int ans = -inf;
    for (int i = 0; i <= n; ++i) a[i] -= low, ans = max(ans, a[i]);
    cout << ans << endl;
    return 0;
}
