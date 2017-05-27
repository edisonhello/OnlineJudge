#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int sum = 0, p = 0, ans = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt = (cnt + i + 1 % mod);
        sum = (sum + p + a[i]) % mod;
        ans = (ans + a[i] * cnt % mod - sum - a[i]) % mod;
        p = sum;
    } 
    cout << ans << '\n';
    return 0;
}
