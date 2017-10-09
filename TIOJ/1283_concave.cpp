#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
int dp[maxn];

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

struct segment {
    int i, l, r;
};

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
    deque<segment> deq; deq.push_back((segment){ 0, 1, n });
    for (int i = 1; i < ln.size(); ++i) {
        dp[i] = f(deq.front().i, i);
        while (deq.size() && deq.front().r < i + 1) deq.pop_front();
        while (deq.size() && f(i, deq.back().l) > f(deq.back().i, deq.back().l)) deq.pop_back();
        deq.front().l = i + 1;
        segment seg = (segment){ i, i + 1, n };
        if (deq.size()) {
            int d = 1048576, c = deq.back().l;
            while (d >>= 1) if (c + d <= deq.back().r) {
                if (f(i, c + d) < f(deq.back().i, c + d)) c += d;
            }
            deq.back().r = c; seg.l = c + 1;
        }
        if (seg.l <= m) deq.push_back(seg);
    }
    int ans = 0;
    for (int i = 1; i < ln.size(); ++i) ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
