#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
pair<double, double> p[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; double w, v, u; cin >> n >> w >> v >> u;
    for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
    vector<pair<double, double>> vec;
    for (int i = 0; i < n; ++i) {
        double ct = p[i].first / v;
        vec.push_back(make_pair(ct, p[i].second));
    }
    sort(vec.begin(), vec.end());
    double now = 0, ct = 0;
    for (auto i : vec) {
        cout << "pos: " << i.second << ' ' << i.first << endl;
        double dis = i.second - now;
        if (i.first == ct) continue;
        if (dis <= 0.0) continue;
        double vnow = min(u, dis / (i.first - ct));
        cout << "speed = " << vnow << endl;
        now += vnow * (i.first - ct);
        ct = i.first;
        cout << "time now = " << ct << endl;
    }
    ct += (w - now) / u;
    cout << fixed << setprecision(20) << ct << endl;
    return 0;
}
