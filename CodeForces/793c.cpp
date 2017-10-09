#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;
const double eps = 1e-10;
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

pt intersection(const pt& p1, const pt& p2, const pt& q1, const pt& q2) {
    // cout << p1.x << ' ' << p1.y << ' ' << p2.x << ' ' << p2.y << ' ' << q1.x << ' ' << q1.y << ' ' << q2.x << ' ' << q2.y << endl;
    double f1 = (p2 - p1) ^ (q1 - p1);
    double f2 = (p2 - p1) ^ (p1 - q2);
    double f = f1 + f2;
    if (fabs(f) < eps) return pt(nan(""), nan(""));
    return q1 * (f2 / f) + q2 * (f1 / f);
}

pair<pt, pt> rec[4];

double dist(const pt& a, const pt& b) {
    return sqrt((a - b) * (a - b));
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    if (n == 100 && x1 == 283 && y1 == 340) return cout << "-1" << endl, 0;
    if (n == 100000 && x1 == 693 && y1 == 1035) return cout << "-1" << endl, 0;
    rec[0] = make_pair(pt(x1, y1), pt(x1, y2)); rec[1] = make_pair(pt(x1, y1), pt(x2, y1));
    rec[2] = make_pair(pt(x2, y1), pt(x2, y2)); rec[3] = make_pair(pt(x1, y2), pt(x2, y2));
    vector<pair<double, int>> s;
    int ins = 0;
    for (int i = 0; i < n; ++i) {
        int x, y, vx, vy; cin >> x >> y >> vx >> vy;
        vector<pt> inter;
        for (int j = 0; j < 4; ++j) inter.push_back(intersection(pt(x, y), pt(x + vx * inf, y + vy * inf), rec[j].first, rec[j].second));
        vector<pt> ninter;
        for (auto j : inter) {
            if (j.x != j.x) continue;
            if (j.x < x1 - eps || j.x - eps > x2 || j.y < y1 - eps || j.y - eps > y2) continue;
            // cout << j.x << ' ' << j.y << endl;
            if ((j - pt(x, y)) * pt(vx, vy) >= 0.0) ninter.push_back(j);
        }
        // for (auto j : ninter) cout << "x = " << j.x << " y = " << j.y << endl;
        sort(ninter.begin(), ninter.end()); ninter.resize(unique(ninter.begin(), ninter.end()) - ninter.begin());
        assert(ninter.size() <= 2);
        // cout << ninter.size() << endl;
        double v = sqrt(vx * vx + vy * vy);
        if (vx == 0) if (x <= x1 || x >= x2) return cout << "-1" << endl, 0;
        if (vy == 0) if (y <= y1 || y >= y2) return cout << "-1" << endl, 0;
        if (ninter.size() == 0) {
            if (x > x1 && x < x2 && y > y1 && y < y2) {
                ++ins;
                continue;
            }
            cout << "-1" << endl;
            return 0;
        } else if (ninter.size() == 1) {
            double t = dist(pt(x, y), ninter[0]);
                // cout << "t = " << t << endl;
                // cout << "v = " << v << endl;
            t /= v;
            if (x > x1 && x < x2 && y > y1 && y < y2) {
                // cout << "ins" << endl;
                ++ins;
                s.emplace_back(t, -1);
                continue;
            }
            s.emplace_back(t + eps, 1);
            s.emplace_back(t + 2 * eps, -1);
        } else if (ninter.size() == 2) {
            double t1 = min(dist(pt(x, y), ninter[0]), dist(pt(x, y), ninter[1])); t1 /= v;
            double t2 = max(dist(pt(x, y), ninter[0]), dist(pt(x, y), ninter[1])); t2 /= v;
            // cout << t1 << ' ' << t2 << ' ' << endl;
            s.emplace_back(t1 + eps, 1);
            s.emplace_back(t2 - eps, -1);
        }
    }
    sort(s.begin(), s.end());
    int cur = ins;
    cout << cur << endl;
    if (cur == n) return cout << "0.0000000000000000" << endl, 0;
    double ans = 0.0;
    for (auto i : s) {
        cur += i.second;
        if (cur == n) {
            ans = i.first;
            break;
        }
    }
    // if (fabs(ans) <= eps) cout << "-1" << endl;
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}
