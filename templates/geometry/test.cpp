#include <bits/stdc++.h>
using namespace std;

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
};



vector<pt> circle_intersection(const pt& o1, const double& r1, const pt& o2, const double& r2) {
    double d2 = (o1 - o2) * (o1 - o2);
    double d = sqrt(d2);
    if (d > r1 + r2) return {};
    pt u = (o1 + o2) * 0.5 + (o1 - o2) * ((r2 * r2 - r1 * r1) / (2 * d2));
    double a = sqrt((r1 + r2 + d) * (r1 - r2 + d) * (r1+ r2 - d) * (-r1 + r2 + d));
    pt v = pt(o1.y - o2.y, -o1.x + o2.x) * a / (2 * d2);
    return { u + v, u - v };
}

int main() {
    int t; cin >> t; while (t--) {
        int x1, y1, x2, y2, r1, r2;
        cin >> x1 >> y1 >> x2 >> y2 >> r1 >> r2;
        vector<pt> inter = circle_intersection(pt(x1, y1), r1, pt(x2, y2), r2);
        if (inter.size()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
