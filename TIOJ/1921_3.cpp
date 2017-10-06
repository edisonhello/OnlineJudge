#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;
long long dp[maxn];

struct mac {
    int d, p, r, g;
    bool operator<(const mac& rhs) const {
        return d < rhs.d;
    }
    friend istream& operator>>(istream& in, mac& ma) {
        in >> ma.d >> ma.p >> ma.r >> ma.g;
        return in;
    }
} m[maxn];

struct line {
    long long a, b, l, r;
    long long operator()(const int& d) const {
        return a * 1ll * d + b;
    }
    long long intersect(const line& rhs) const {
        return (rhs.b - b) / (a - rhs.a);
    }
    bool operator<(const line& rhs) const {
        return a < rhs.a;
    }
    bool operator>(const line& rhs) const {
        return a == rhs.a ? b > rhs.b : a > rhs.a;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, c, d; cin >> n >> c >> d;
    for (int i = 1; i <= n; ++i) cin >> m[i];
    m[0] = (mac){ 0, 0, 0, 0 }; m[n + 1] = (mac){ d + 1, 0, 0, 0 };
    sort(m, m + n + 2);
    set<line> st; st.insert((line){ 0, c, 0, inf });
    for (int i = 1; i <= n + 1; ++i) {
        while (st.size() >= 2) {
            auto it = st.begin(); ++it;
            if (st.begin()->r < m[i].d) st.erase(st.begin());
            else if (it != st.end() && (*it)(m[i].d) >= (*st.begin())(m[i].d)) st.erase(st.begin());
            else break;
        } 
        dp[i] = (*st.begin())(m[i].d);
        if (dp[i] < m[i].p) continue;
        line nl = (line){ m[i].g, -m[i].g * (m[i].d + 1) + m[i].r - m[i].p + dp[i], 0, inf };
        auto it = st.lower_bound(nl);
        bool ins = true;
        while (it != st.end()) {
            if ((*it)(it->l) > nl(it->l) && (*it)(it->r) > nl(it->r)) {
                ins = false;
                break;
            }
            if ((*it)(it->l) <= nl(it->l) && (*it)(it->r) <= nl(it->r)) it = st.erase(it);
            else break;
        }
        if (!ins) continue;
        while (it != st.begin()) {
            --it;
            if ((*it)(it->l) <= nl(it->l) && (*it)(it->r) <= nl(it->r)) it = st.erase(it);
            else { ++it; break; }
        }
        if (it != st.begin()) {
            --it;
            line tmp = *it; it = st.erase(it);
            long long t = nl.intersect(tmp);
            tmp.r = t; nl.l = t + 1;
            st.insert(tmp);
        }
        if (it != st.end()) {
            line tmp = *it; it = st.erase(it);
            long long t = nl.intersect(tmp);
            tmp.l = t + 1; nl.r = t;
            st.insert(tmp);
        }
        st.insert(nl);
    }
    cout << dp[n + 1] << endl;
    return 0;
}
