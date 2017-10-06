#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
long long dp[maxn];

struct mac {
    int d, p, r, g;
    bool operator<(const mac& rhs) const {
        return d < rhs.d;
    }
    friend istream& operator>>(istream& in, mac& mc) {
        in >> mc.d >> mc.p >> mc.r >> mc.g;
        return in;
    }
} m[maxn];

struct line {
    long long a, b;
    long long operator()(const long long& d) const {
        return a * d + b;
    }
    bool operator<(const line& rhs) const {
        return a == rhs.a ? b > rhs.b : a < rhs.a;
    }
};

bool intersect(const line& l1, const line& l2, const line& l3, bool larger = false) {
    if (larger) return (__int128)(l3.a - l2.a) * (__int128)(l1.b - l2.b) >= (__int128)(l2.a - l1.a) * (l2.b - l3.b);
    return (__int128)(l3.a - l2.a) * (__int128)(l1.b - l2.b) <= (__int128)(l2.a - l1.a) * (l2.b - l3.b);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, c, d; cin >> n >> c >> d;
    for (int i = 1; i <= n; ++i) cin >> m[i];
    sort(m + 1, m + n + 1); m[0] = (mac){ 0, 0, 0, 0 }; m[n + 1] = (mac){ d + 1, 0, 0, 0 };
    dp[0] = c;
    set<line> st; st.insert((line){ 0, c });
    for (int i = 1; i <= n + 1; ++i) {
        // cout << "check i = " << i << endl;
        // for (auto it = st.begin(); it != st.end(); ++it) cout << "a = " << it->a << " b = " << it->b << endl;
        while (st.size() >= 2) {
            // cout << "size = " << st.size() << endl;
            auto it = st.begin(); ++it;
            if ((*st.begin())(m[i].d) <= (*it)(m[i].d)) st.erase(st.begin());
            else break;
        }
        // cout << "i = " << i << endl;
        // cout << "after i = " << i << endl;
        // for (auto it = st.begin(); it != st.end(); ++it) cout << "a = " << it->a << " b = " << it->b << endl;
        assert(st.size() > 0);
        line tr = *st.begin();
        dp[i] = tr(m[i].d);
        // cout << "dp[" << i << "] = " << dp[i] << endl;
        if (dp[i] < m[i].p) continue;
        line nl = (line){ m[i].g, -m[i].g * (m[i].d + 1) + m[i].r - m[i].p + dp[i] };
        // cout << "new line: a = " << nl.a << " b = " << nl.b << endl;
        auto it = st.lower_bound(nl);
        while (it != st.end()) {
            auto itt = it; ++itt;
            if (itt == st.end()) break;
            if (intersect(nl, *it, *itt, true)) st.erase(it), it = itt;
            else break;
        }
        // cout << "ok" << endl;
        it = st.lower_bound(nl); 
        if (it == st.begin()) {
            st.insert(nl);
            continue;

        }
        if (it == st.end() || it->a > nl.a) --it;
        while (it != st.begin()) {
            auto itt = it; --itt;
            if (intersect(nl, *it, *itt)) st.erase(it), it = itt;
            else break;
        }
        // cout << "okk" << endl;
        st.insert(nl);
    }
    cout << dp[n + 1] << endl;
    return 0;
}
