#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 10, inf = 1e9 + 1;
int h[maxn], n, k, d;

bool check(int);

main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k >> d;
    for (int i = 0; i < n; ++i) cin >> h[i];
    sort(h, h + n); 
    int dd = 1, ans = inf; while (dd < inf) dd <<= 1;
    while (dd >>= 1) if (ans - dd >= 0) if (check(ans - dd)) ans -= dd;
    cout << ans << endl;
}

bool check(int x) {
    if (x < h[0] && x < d) return false;
    int cur = 0, cnt = 0;
    if (x >= d) return true;
    for (int i = 0; i < n && cnt < k; ++i) {
        if (cur + x >= d) return true;
        if (h[i] > cur && h[i - 1] > cur && h[i] - cur > x) ++cnt, cur = h[i - 1];
    } 
    if (cnt < k && cur + x >= h[n - 1]) cur = h[n - 1];
    cur += x;
    return cur >= d;
}
