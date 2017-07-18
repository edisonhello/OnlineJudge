#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const long long inf = 1e18 + 1;
long long s[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, a; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a; s[i] = s[i - 1] + a;
    }
    long long ans = inf;
    for (int i = 1; i < n; ++i) {
        ans = min(ans, abs(s[i] + s[i] - s[n]));
    }
    cout << ans << endl;
    return 0;
}
