#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e4 + 10;
const double eps = 1e-7;
pair<double, double> p[maxn];
int n;

double bs(double, double);
bool check(double);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> p[i].first;
    for (int i = 0; i < n; ++i) cin >> p[i].second;
    cout << fixed << setprecision(6) << bs(0, 1e6 + 1) << '\n';
}

double bs(double l, double r) {
    if (r - l < eps) return l;
    double m = (l + r) / 2;
    if (check(m)) return bs(l, m);
    return bs(m, r);
}


bool check(double t) {
    vector<pair<double, int>> vec;
    for (int i = 0; i < n; ++i) vec.push_back(make_pair(p[i].first - p[i].second * t, 1)), vec.push_back(make_pair(p[i].first + p[i].second * t, -1));
    sort(vec.begin(), vec.end());
    int cnt = 0, Max = 0;
    for (auto i : vec) {
        cnt += i.second;
        Max = max(Max, cnt);
    }
    return Max == n;
}
