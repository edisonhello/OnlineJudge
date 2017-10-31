#include <bits/stdc++.h>
#define fix(t) (t + 200010)
using namespace std;

const int maxn = 100 + 10, maxk = 4e5 + 100, mod = 1e9 + 7;
const int minp = -2e5, maxp = 2e5;
int dpa[2][maxk], dpb[2][maxk];

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }


int partial(int *dp, int l, int r) {
    l = fix(l); r = fix(r);
    l = max(l, 1); r = min(r, fix(maxp));
    return sub(dp[r], dp[l - 1]);
}

void cal(int dp[2][maxk], int p, int k, int t) {
    for (int i = p; i <= maxp; ++i) dp[0][fix(i)] = 1;
    for (int i = 1; i <= t; ++i) {
        int cur = i & 1;
        memset(dp[cur], 0, sizeof(dp[cur]));
        for (int pt = minp; pt <= maxp; ++pt) {
            dp[cur][fix(pt)] = partial(dp[cur ^ 1], pt - k, pt + k);
            dp[cur][fix(pt)] = add(dp[cur][fix(pt)], dp[cur][fix(pt - 1)]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b, k, t; cin >> a >> b >> k >> t;
    cal(dpa, a, k, t); cal(dpb, b, k, t); 
    int pb = 0, ans = 0;
    for (int i = minp; i <= maxp; ++i) {
        int da = sub(dpa[t & 1][fix(i)], dpa[t & 1][fix(i - 1)]), db = sub(dpb[t & 1][fix(i)], dpb[t & 1][fix(i - 1)]);
        ans = add(ans, mul(pb, da));
        pb = add(pb, db);
    }
    cout << ans << endl;
    return 0;
}
