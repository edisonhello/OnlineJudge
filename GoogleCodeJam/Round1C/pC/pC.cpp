#include <bits/stdc++.h>
using namespace std;

const int maxn = 50 + 5;
const double eps = 1e-7;
double p[maxn], u, mem[maxn][maxn];
int n, k;

double bs(double, double);
bool check(double);
double dp(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ": ";
        cin >> n >> k >> u;
        memset(mem, 0, sizeof(mem));
        for (int i = 1; i <= n; ++i) cin >> p[i];
        double ans = bs(0, 1.0);
        for (int i = 1; i <= n; ++i) {
            if (p[i] < ans) p[i] = ans;
        }
        cout << fixed << setprecision(9) << dp(n, k) << '\n';
    }
    return 0;
}

double bs(double l, double r) {
    if (r - l < eps) return l;
    double m = (l + r) / 2;
    if (check(m)) return bs(m, r);
    return bs(l, m);
}

bool check(double x) {
    double use = 0.0;
    for (int i = 1; i <= n; ++i) {
        if (p[i] < x) use += x - p[i]; 
    }
    return use <= u;
}

double dp(int n, int k) {
    if (n < 0) return 0.0;
    if (k < 0) return 1.0;
    if (mem[n][k]) return mem[n][k];
    return mem[n][k] = dp(n - 1, k - 1) * p[n] + dp(n - 1, k);
}
