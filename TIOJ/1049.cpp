#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
const double eps = 1e-3;
pair<double, double> s[maxn], t[maxn];

bool check(int, int);
bool eq(double a, double b) {
    return fabs(a - b) < eps;
}
bool eql(const pair<double, double>& a, const pair<double, double>& b) {
    return eq(a.first, b.first) && eq(a.second, b.second);
}


vector<pair<double, double>> st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n, n) {
        for (int i = 0; i < n; ++i) cin >> s[i].first >> s[i].second >> t[i].first >> t[i].second;
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            int inter = 0;
            st.clear();
            for (int j = 0; j < i; ++j) {
                check(i, j) ;
            }
            st.push_back(s[i]); st.push_back(t[i]); 
            sort(st.begin(), st.end());
            for (int j = 1; j < st.size(); ++j) {
                if (!eql(st[j], st[j - 1])) ++inter;
            }
            ans += inter;
        }
        cout << ans << endl;
    }
    return 0;
}

bool check(int i, int j) {
    // cout << "check" << endl;
    // cout << s[i].first << ' ' << s[i].second << ' ' << t[i].first << ' ' << t[i].second << endl;
    // cout << s[j].first << ' ' << s[j].second << ' ' << t[j].first << ' ' << t[j].second << endl;
    if (eq(t[i].first, s[i].first)) {
        // cout << "type1" << endl;
        if (eq(t[j].first, s[j].first)) return false;
        double m = (t[j].second - s[j].second) / (t[j].first - s[j].first);
        double k = t[j].second - m * t[j].first;
        double y = m * t[i].first + k;
        bool ret = !eq(y, 0.0) && !eq(y, 1.0) && y > 0.0 && y < 1.0;
        // cout << "m = " << m << " k = " << k << endl;
        // cout << "x = " << t[i].first << " y = " << y << endl;
        // if (st.count(make_pair(t[i].first, y))) return false;
        if (ret) st.push_back(make_pair(t[i].first, y)); return ret;
    } else if (eq(t[j].first, s[j].first)) {
        // cout << "type2" << endl;
        double m = (t[i].second - s[i].second) / (t[i].first - s[i].first);
        double k = t[i].second - m * t[i].first;
        double y = m * t[j].first + k;
        bool ret = !eq(y, 0.0) && !eq(y, 1.0) && y > 0.0 && y < 1.0;
        // cout << "m = " << m << " k = " << k << endl;
        // cout << "x = " << t[j].first << " y = " << y << endl;
        // if (st.count(make_pair(t[j].first, y))) return false;
        if (ret) st.push_back(make_pair(t[j].first, y)); return ret;
    }
    // cout << "type3" << endl;
    double m1 = (t[i].second - s[i].second) / (t[i].first - s[i].first), k1 = t[i].second - m1 * t[i].first;
    double m2 = (t[j].second - s[j].second) / (t[j].first - s[j].first), k2 = t[j].second - m2 * t[j].first;
    if (eq(m1, m2)) return false;
    double x = (k2 - k1) / (m1 - m2);
    double y = m1 * x + k1;
    bool ret = !eq(x, 0.0) && !eq(x, 1.0) && !eq(y, 0.0) && !eq(y, 1.0) && x > 0.0 && x < 1.0 && y > 0.0 && y < 1.0;
    // cout << "x = " << x << " y = " << y << endl;
    // if (st.count(make_pair(x, y))) return false;
    if (ret) st.push_back(make_pair(x, y)); return ret;
}
