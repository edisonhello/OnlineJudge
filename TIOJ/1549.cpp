#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e6 + 10, inf = 1e9 + 1;
int a[maxn], b[maxn];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    stack<int> s;
    fill(b, b + maxn, inf);
    for (int i = 1; i <= n; ++i) {
        while (s.size() && a[s.top()] > a[i]) {
            b[s.top()] = min(b[s.top()], a[s.top()] - a[i]);
            s.pop();
        }
        s.push(i);
    }
    while (s.size()) s.pop();
    for (int i = n; i > 0; --i) {
        while (s.size() && a[s.top()] > a[i]) {
            b[s.top()] = min(b[s.top()], a[s.top()] - a[i]);
            s.pop();
        }
        s.push(i);
    } 
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (b[i] == inf) continue;
        ans += b[i] * b[i];
    }
    cout << ans << endl;
    return 0;
}
