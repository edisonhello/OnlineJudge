#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
const double eps = 1e-9;
const double pi = acos(-1);

using type = double;

struct pt {
    type x, y;
    pt(): x(0), y(0) {}
    pt(type x, type y): x(x), y(y) {}
    pt operator+(const pt& a) const { return pt(x + a.x, y + a.y); }
    pt operator-(const pt& a) const { return pt(x - a.x, y - a.y); }
    pt operator*(const type& t) const { return pt(x * t, y * t); }
    pt operator/(const type& t) const { return pt(x / t, y / t); }
    type operator*(const pt& a) const { return x * a.x + y * a.y; }
    type operator^(const pt& a) const { return x * a.y - y * a.x; }
    bool operator<(const pt& a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pt& a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pt& a) const { return x == a.x && y == a.y; }
    bool operator!=(const pt& a) const { return x != a.x || y != a.y; }
    double dist(const pt &p) const { return sqrt((p - *this) * (p - *this)); }
    friend double norm2(const pt &p) { return p * p; }
    friend double norm(const pt &p) { return sqrt(norm2(p)); }
};


struct circle {
    pt o;
    type r;
    circle() {}
    circle(const pt &p, const type &d): o(p), r(d) {}
    circle(const type &x, const type &y, const type &d): o(pt(x, y)), r(d) {}
    double operator()() const { return pi * r * r; }
    bool overlap(const pt &p) const { return p.dist(o) <= r; }
    bool on(const pt &p) const { return p.dist(o) == r; }
};


pt center(const pt &a, const pt &b, const pt &c) {
    pt p0 = b - a, p1 = c - a;
    double c1 = norm2(p0) * 0.5, c2 = norm2(p1) * 0.5;
    double d = p0 ^ p1;
    double x = a.x + (c1 * p1.y - c2 * p0.y) / d;
    double y = a.y + (c2 * p0.x - c1 * p1.x) / d;
    return pt(x, y);
}

type cross(const pt& o, const pt& a, const pt& b) {
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

circle min_enclosing(vector<pt> p) {
    p = convex_hull(p);
    random_shuffle(p.begin(), p.end());
    double r = 0.0;
    pt cent;
    for (int i = 0; i < p.size(); ++i) {
        if (norm2(cent - p[i]) <= r) continue;
        cent = p[i];
        r = 0.0;
        for (int j = 0; j < i; ++j) {
            if (norm2(cent - p[j]) <= r) continue;
            cent = (p[i] + p[j]) / 2;
            r = norm2(p[j] - cent);
            for (int k = 0; k < j; ++k) {
                if (norm2(cent - p[k]) <= r) continue;
                cent = center(p[i], p[j], p[k]);
                r = norm2(p[k] - cent);
            }
        }
    }
    return circle(cent, sqrt(r));
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m; cin >> m;
    vector<pt> p;
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        p.push_back(pt(x, y));
    }
    cout << fixed << setprecision(2) << min_enclosing(p).r * 2.0 << endl;
    return 0;
}
