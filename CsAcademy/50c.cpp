#include <bits/stdc++.h>
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

double cross(const pt& o, const pt& a, const pt& b) {
    return (a - o) ^ (b - o);
}

int rsd;

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

int main() {
    int t; cin >> t; while (t--) {
        vector<pt> p(4);
        for (int i = 0; i < 4; ++i) cin >> p[i].x >> p[i].y;
        vector<pt> ch = convex_hull(p);
        bool ans = true;
        for (int i = 0; i < 4; ++i) {
            if ((ch[(i + 1) % 4] - ch[i]) * (ch[(i + 2) % 4] - ch[(i + 1) % 4]) != 0) ans = false;
        }
        if (ans) cout << "1" << endl;
        else cout << "0" << endl;
    }
    return 0;
}
