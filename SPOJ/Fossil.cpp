#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

struct pt {
    double x, y;
    pt(): x(0.0), y(0.0) {}
    pt(double x, double y): x(x), y(y) {}
    pt operator+(const pt& a) const { return pt(x + a.x, y + a.y); }
    pt operator-(const pt& a) const { return pt(x - a.x, y - a.y); }
    double operator*(const pt& a) const { return x * a.x + y * a.y; }
    double operator^(const pt& a) const { return x * a.y - y * a.x; }
    bool operator<(const pt& a) const { return x == a.x ? y < a.y : x < a.x; }
};

int rsd;

double cross(const pt& o, const pt& a, const pt& b) {
    return (a - o) ^ (b - o);
}

vector<pt> convex_hull(vector<pt> p) {
    sort(p.begin(), p.end());
    int m = 0;
    vector<pt> ret(2 * p.size());
    for (int i = 0; i < p.size(); ++i) {
        while (m >= 2 && cross(ret[m - 2], ret[m - 1], p[i]) < 0) --m;
        ret[m++] = p[i];
    }
    rsd = m - 1;
    for (int i = p.size() - 2, t = m + 1; i >= 0; --i) {
        while (m >= t && cross(ret[m - 2], ret[m - 1], p[i]) < 0) --m;
        ret[m++] = p[i];
    }
    ret.resize(m - 1);
    return ret;
}

int dist(const pt& a, const pt& b) {
    return (a - b).x * (a - b).x + (a - b).y * (a - b).y;
}

void rotating_caliper(vector<pt> p) {
    vector<pt> ch = convex_hull(p);
    int tbz = ch.size();
    int lpr = 0, rpr = rsd;
    // ch[lpr], ch[rpr]
    int ans = 0;
    ans = max(ans, dist(ch[lpr], ch[rpr]));
    while (lpr < rsd || rpr < tbz - 1) {
        if (lpr < rsd && rpr < tbz - 1) {
            pt rvt = ch[rpr + 1] - ch[rpr];
            pt lvt = ch[lpr + 1] - ch[lpr];
            if ((lvt ^ rvt) < 0) ++lpr;
            else ++rpr;
        }
        else if (lpr == rsd) ++rpr;
        else ++lpr;
        ans = max(ans, dist(ch[lpr], ch[rpr]));
        // ch[lpr], ch[rpr]
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<pt> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
        rotating_caliper(p);
    }
}
