#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e7 + 10;
const long long inf = 1e18 + 1;
int a[maxn], n, k, l;
long long dpl[maxn], dpr[maxn];

void solve(long long *dp, const vector<int> &a) {
    dp[0] = 0;
    for (int i = 1; i < a.size(); ++i) {
        dp[i] = dp[max(i - k, 0)] + 2 * abs(a[i] - a[0]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        cin >> n >> k >> l;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int pos = lower_bound(a + 1, a + n + 1, l / 2) - a;
        if (a[pos] > l / 2) --pos;
        // cout << "pos = " << pos << endl;
        vector<int> al, ar;
        al.push_back(0); ar.push_back(l);
        for (int i = 1; i <= pos; ++i) al.push_back(a[i]);
        for (int i = n; i > pos; --i) ar.push_back(a[i]);
        // cout << "al : " << endl;
        // for (int i : al) cout << i << ' '; cout << endl;
        // cout << "ar : " << endl;
        // for (int i : ar) cout << i << ' '; cout << endl;
        solve(dpl, al); solve(dpr, ar);
        // cout << "dpl : " << endl;
        // for (int i = 1; i < al.size(); ++i) cout << dpl[i] << ' '; cout << endl;
        // cout << "dpr : " << endl;
        // for (int i = 1; i < ar.size(); ++i) cout << dpr[i] << ' '; cout << endl;
        long long ans = dpl[al.size() - 1] + dpr[ar.size() - 1];
        for (int i = 1; i <= pos; ++i) {
            if (i + k - 1 <= pos) continue;
            int tid = ar.size() - (i + k - 2 - pos) - 1;
            if (tid <= 0) continue;
            ans = min(ans, dpl[i - 1] + l + dpr[tid - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}
