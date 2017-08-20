#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10;
const double inf = 1e9 + 1;
const double eps = 1e-6;
pair<double, double> p[maxn];
int n;
double ansx;

bool check(double y) {
    double lb = 0, ub = inf;
    for (int i = 0; i < n; ++i) {
        double x = (y - p[i].second) / p[i].first;
        if (p[i].first < 0) lb = max(lb, x);
	 	else ub = min(ub, x);
    }
    if (ub >= lb) ansx = ub;
    return ub >= lb;
}

double bs(double l, double r) {
	if (r - l < eps) return l;
	double m = (l + r) / 2;
	if (check(m)) return bs(l, m);
	return bs(m, r);
}


int main() {
	while (cin >> n, n) {
		for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
		double ans = bs(-1, inf);
		if (ans < 0) cout << "0" << endl;
		else cout << fixed << setprecision(3) << ans << ' ' << ansx << endl;
	}
	return 0;
}
