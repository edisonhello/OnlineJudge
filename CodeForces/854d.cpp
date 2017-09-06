#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, maxt = 1e6 + 10;
const long long inf = 1e18 + 1;

struct flight {
    int d, f, t, c, tp;
    bool operator<(const flight& rhs) const {
        return d < rhs.d;
    }
};

struct cmp {
    bool operator()(const flight& a, const flight& b) {
        return a.c < b.c;
    }
};

set<flight, cmp> go[maxn], to[maxn];
set<int> ok1, ok2;
multiset<int> ar, de;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<flight> f;
    for (int i = 0; i < m; ++i) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        f.push_back((flight){ a, b, c, d, 1 });
        f.push_back((flight){ 2 * maxt - a, b, c, d, -1 });
    }
    long long ans = inf, tot = 0;
    sort(f.begin(), f.end());
    for (auto i : f) {
        cout << i.d << ' ' << i.f << ' ' << i.t << ' ' << i.c << ' ' << i.tp << endl;
        if (i.tp == 1) {
            if (i.t != 0) {
                if (to[i.t].size()) tot -= to[i.t].begin()->c;
                to[i.t].insert(i), ar.insert(i.d), ok1.insert(i.t);
                tot += to[i.t].begin()->c;
            }
            else {
                if (go[i.f].size()) tot -= go[i.f].begin()->c;
                go[i.f].insert(i), de.insert(i.d), ok2.insert(i.f);
                tot += go[i.f].begin()->c;
            }
        } else {
            if (i.t != 0) {
                tot -= to[i.t].begin()->c;
                to[i.t].erase(to[i.t].lower_bound(i));
                ar.erase(i.d);
                if (to[i.t].size() == 0) ok1.erase(i.t);
                else tot += to[i.t].begin()->c;
            }
            else {
                tot -= go[i.f].begin()->c;
                go[i.f].erase(go[i.f].lower_bound(i));
                de.erase(i.d);
                if (go[i.f].size() == 0) ok2.erase(i.f);
                else tot += go[i.f].begin()->c;
            }
        }
        cout << "tot = " << tot << endl;
        if (ok1.size() == n && ok2.size() == n) {
            if (de.size() && ar.size()) cout << "bang: " << *ar.begin() << ' ' << *de.rbegin() << endl;
            if (*ar.begin() - *de.rbegin() > k) {
                ans = min(ans, tot);
            }
        }
    }
    if (ans == inf) ans = -1;
    cout << ans << endl;
    return 0;
}
