#include <bits/stdc++.h>
#define int long long
using namespace std;

main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, h; cin >> n >> h;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int cur = h, cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        cur -= v[i];
        if (cur <= 0) return cout << "-1\n", 0;
        if (cur - v[i + 1] <= 0) cur = h, ++cnt;
    }
    cur -= v[n - 1];
    if (cur < 0) cout << "-1\n";
    else cout << cnt << '\n';
    return 0;
}
