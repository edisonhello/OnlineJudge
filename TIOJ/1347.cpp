#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
const long long inf = 2e18 + 1;
long long sa[maxn], sl[maxn], dp[maxn], lim;
int n, k, p;

struct segment {
    int i, l, r;
    segment() {}
    segment(int a, int b, int c): i(a), l(b), r(c) {}
    friend ostream& operator<<(ostream& out, const segment& s) {
        out << "i = " << s.i << " l = " << s.l << " r = " << s.r;
        return out;
    }
};

inline long long fpow(long long a, int n) {
    if (a > lim) return inf;
    long long ret = 1ll;
    for (; n; n >>= 1) {
        if (n & 1) ret *= a;
        a *= a;
    } 
    return ret;
}

inline long double dfpow(long double a, int n) {
    long double ret = 1.0;
    for (; n; n >>= 1) {
        if (n & 1) ret *= a;
        a *= a;
    }
    return ret;
}

inline long long f(int l, int r) {
    long long m = sa[r] - sa[l] + sl[r - 1] - sl[l] - k;
    if (m < 0) m = -m;
    long long ret = dp[l] + fpow(m, p);
    if (ret > inf) return inf;
    return dp[l] + fpow(m, p);
}

inline long double df(int l, int r) {
    long double m = sa[r] - sa[l] + sl[r - 1] - sl[l] - k;
    if (m < 0) m = -m;
    return (long double)dp[l] + dfpow(m, p);
}

void debug(const deque<segment>& deq) {
    for (auto i : deq) cout << i << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k >> p; lim = pow(inf, 1.0 / (double)p);
    for (int i = 1; i <= n; ++i) {
        long long a; cin >> a;
        sa[i] = sa[i - 1] + a;
    }
    for (int i = 1; i <= n - 1; ++i) {
        long long l; cin >> l;
        sl[i] = sl[i - 1] + l;
    }
    dp[0] = 0ll;
    deque<segment> deq; deq.push_back(segment(0, 1, n));
    for (int i = 1; i <= n; ++i) {
        dp[i] = f(deq.front().i, i);
        if (i == n) return cout << dp[n] << endl, 0;
        while (deq.size() && deq.front().r < i + 1) deq.pop_front();
        deq.front().l = i + 1;
        segment seg = segment(i, i + 1, n);
        while (deq.size() && df(i, deq.back().l) < df(deq.back().i, deq.back().l)) deq.pop_back();
        if (deq.size()) {
            int d = 1048576, c = deq.back().l;
            while (d >>= 1) if (c + d <= deq.back().r) {
                if (df(i, c + d) > df(deq.back().i, c + d)) c += d;
            }
            deq.back().r = c; seg.l = c + 1;
        }
        if (seg.l <= n) deq.push_back(seg);
    }
    return 0;
}
