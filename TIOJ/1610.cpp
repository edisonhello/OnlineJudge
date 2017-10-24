#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e4 + 10;
int w[maxn], l[maxn];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> w[i];
    for (int i = 1; i < n; ++i) cin >> l[i];
    sort(w, w + n); 
    sort(l + 1, l + n); reverse(l + 1, l + n);
    int sum = w[0], len = 0, ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += sum * l[i];
        sum += w[i];
    }
    cout << ans << endl;
    return 0;
}
