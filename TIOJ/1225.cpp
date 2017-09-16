#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int ans = 0;
    int p; cin >> p;
    for (int i = 2; i <= n; ++i) {
        int a; cin >> a;
        ans += max(a, p);
        p = a;
    }
    cout << ans << endl;
}
