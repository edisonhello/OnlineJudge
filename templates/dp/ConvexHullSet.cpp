int dp[maxn], type;

struct line {
    int a, b, l, r;
    int operator()(const int& d) const { return a * d + b; }
    int intersect(const line& rhs) const { return (rhs.b - b) / (a - rhs.a); }
    bool operator<(const line& rhs) const { return type ? r < rhs.l : a < rhs.a; }
};

void solve() {
    set<line> st; st.insert((line){ a[0], b[0], -inf, inf });
    for (int i = 1; i <= n + 1; ++i) {
        dp[i] = (*st.lower_bound((line){ 0, 0, x[i], x[i] }));
        line nl = (line){ a[i], b[i], -inf, inf };
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
}
