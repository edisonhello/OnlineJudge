#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;

struct line {
    int pos, l, r;
    bool operator<(const line& rhs) const {
        return pos < rhs.pos;
    }
    friend ostream& operator<<(ostream& out, const line& l) {
        out << "pos = " << l.pos << " l = " << l.l << " r = " << l.r;
        return out;
    }
};

vector<line> ln;

int f(int a, int b) {
    int l = ln[b].l, r = ln[a].r;
    return max(0ll, (r - l) * abs(ln[a].pos - ln[b].pos));
}

void go(int l, int r, int tl, int tr, int& ans) {
    if (l > r) return;
    int m = (l + r) >> 1;
    int t = -1, now = -1;
    for (int i = tl; i <= min(m - 1, tr); ++i) {
        int tmp = f(i, m);
        if (tmp > now) {
            now = tmp;
            t = i;
        }
    }
    // cout << "m = " << m << " dp[m] = " << now << endl;
    ans = max(ans, now);
    if (t == -1) return;
    go(l, m - 1, tl, t, ans); go(m + 1, r, t, tr, ans);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int pa = 0, pb = 0;
    for (int i = 1; i <= n / 2; ++i) {
        int a, b; cin >> a >> b;
        ln.push_back((line){ pb, pa, pa + a });
        pb += b; pa += a;
    }
    int m; cin >> m;
    pa = 0; pb = 0;
    for (int i = 1; i <= m / 2; ++i) {
        int a, b; cin >> a >> b;
        ln.push_back((line){ pa + a, pb, pb + b });
        pa += a; pb += b;
    }
    sort(ln.begin(), ln.end());
    // for (auto l : ln) cout << l << endl;
    int ans = 0;
    go(1, ln.size() - 1, 0, ln.size() - 2, ans);
    cout << ans << endl;
    return 0;
}
