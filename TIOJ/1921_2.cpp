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
    friend istream& operator>>(istream& in, mac& mc) {
        in >> mc.d >> mc.p >> mc.r >> mc.g;
        return in;
    }
} m[maxn];

struct line {
    long long a, b, l, r;
    long long operator()(const long long& d) const {
        return a * d + b;
    }
    bool operator<(const line& rhs) const {
        return a == rhs.a ? b < rhs.b : a < rhs.a;
    }
    long long intersect(const line& rhs) const {
        if (a == rhs.a) return inf;
        return (rhs.b - b) / (a - rhs.a);
    }
    friend ostream& operator<<(ostream& out, const line& l) {
        out << "a = " << l.a << " b = " << l.b << " l = " << l.l << " r = " << l.r;
        return out;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, c, d; cin >> n >> c >> d;
    for (int i = 1; i <= n; ++i) cin >> m[i];
    sort(m + 1, m + n + 1); m[0] = (mac){ 0, 0, 0, 0 }; m[n + 1] = (mac){ d + 1, 0, 0, 0 };
    dp[0] = c;
    set<line> st; st.insert((line){ 0, c, 0, inf });
    for (int i = 1; i <= n + 1; ++i) {
        // cout << "check i = " << i << " d[i] = " << m[i].d << endl;
        // for (auto it = st.begin(); it != st.end(); ++it) cout << (*it) << endl;
        while (st.size() >= 2) {
            // cout << "size = " << st.size() << endl;
            auto it = st.begin();
            auto itt = it; ++itt;
            if (st.begin()->r < m[i].d) st.erase(st.begin());
            else if (itt != st.end()) {
                if ((*it)(m[i].d) <= (*itt)(m[i].d)) st.erase(st.begin());
                else break;
            }
            else break;
        }
        // cout << "after i = " << i << endl;
        // for (auto it = st.begin(); it != st.end(); ++it) cout << (*it) << endl;
        assert(st.size() > 0);
        line tr = *st.begin();
        dp[i] = tr(m[i].d);
        // cout << "dp[" << i << "] = " << dp[i] << endl;
        if (dp[i] < m[i].p) continue;
        line nl = (line){ m[i].g, -m[i].g * (m[i].d + 1) + m[i].r - m[i].p + dp[i], 0, inf };
        // cout << "new line: a = " << nl.a << " b = " << nl.b << endl;
        auto it = st.lower_bound(nl);
        while (it != st.end()) {
            auto itt = it; ++itt;
            if (it->a == nl.a) nl = max(nl, *it), st.erase(it), it = itt;
            else break;
        }
        it = st.lower_bound(nl); --it;
        while (true) {
            bool b = false;
            if (it == st.begin()) b = true;
            auto itt = it; --itt;
            if (it->a == nl.a) nl = max(nl, *it), st.erase(it), it = itt;
            else break;
            if (b) break;
        }
        it = st.lower_bound(nl);
        bool ins = true;
        while (it != st.end()) {
            // cout << "bang1: " << *it << endl;
            auto itt = it; ++itt;
            if (it->a == nl.a && (*it)(it->l) > nl(it->l) && (*it)(it->r) > nl(it->r)) {
                ins = false;
                break;
            }
            if ((*it)(it->l) <= nl(it->l) && (*it)(it->r) <= nl(it->r)) st.erase(it), it = itt;
            else break;
        }
        // cout << "ok" << endl;
        if (!ins) continue;
        it = st.lower_bound(nl);
        while (it != st.begin()) {
            --it;
            // cout << "bang: " << *it << endl;
            auto itt = it; --itt;
            if (it->a == nl.a && (*it)(it->l) > nl(it->l) && (*it)(it->r) > nl(it->r)) {
                ins = false;
                break;
            }
            if ((*it)(it->l) <= nl(it->l) && (*it)(it->r) <= nl(it->r)) st.erase(it), it = itt;
            else break;
        } 
        if (!ins) continue;
        // cout << "ok" << endl;
        it = st.lower_bound(nl);
        if (it != st.end()) {
            // cout << "aaa: " << *it << endl;
            // cout << "assert1" << endl;
            assert(it->a != nl.a);
            long long t = nl.intersect(*it);
            line tmp = *it;
            st.erase(it);
            tmp.l = t;
            nl.r = t;
            st.insert(tmp);
        }
        // cout << "ok" << endl;
        it = st.lower_bound(nl);
        if (it != st.begin()) {
            // cout << "assert2" << endl;
            --it;
            assert(it->a != nl.a);
            long long t = nl.intersect(*it);
            line tmp = *it;
            st.erase(it);
            tmp.r = t;
            nl.l = t;
            st.insert(tmp);
        }
        // cout << "ok" << endl;
        // cout << "okk" << endl;
        st.insert(nl);
    }
    cout << dp[n + 1] << endl;
    return 0;
}
