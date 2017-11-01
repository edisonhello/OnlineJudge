#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e7 + 10;
const long long inf = 1e18;
int a[maxn];
long long dpl[maxn], dpr[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, k, l; cin >> n >> k >> l;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        dpl[0] = 0;
        for (int i = 1; i <= n; ++i) dpl[i] = dpl[max(0, i - k)] + 2 * 1ll * a[i];
        dpr[n + 1] = 0;
        for (int i = n; i >= 1; --i) dpr[i] = dpr[min(n + 1, i + k)] + 2 * 1ll * (l - a[i]);
        long long ans = min(dpl[n], dpr[1]);
        for (int i = 1; i <= n; ++i) {
            int to = i + k - 1;
            ans = min(ans, dpl[i - 1] + l + dpr[min(n + 1, to + 1)]);
            ans = min(ans, dpl[i] + dpr[i + 1]);
        }
        cout << ans << endl;
    }
    return 0;
}
