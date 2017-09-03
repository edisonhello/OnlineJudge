#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10, inf = 2e9 + 1;
int a[maxn], b[maxn], n, m;
long long sa, sb;

bool check(int v) {

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i], sa += a[i];
    for (int i = 0; i < m; ++i) cin >> b[i], sb += b[i];
    int d = 1, ans = inf; while (d < inf) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    cout << ans << endl;
    return 0;
}
