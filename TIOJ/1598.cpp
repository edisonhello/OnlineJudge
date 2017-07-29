#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 1e6 + 1;
int p[maxn], n, b;

bool check(int);
int cal(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> b;
    int tmax = 0;
    for (int i = 0; i < n; ++i) cin >> p[i], tmax = max(tmax, p[i]);
    // sort(p, p + n);
    int d = 1, ans = tmax;
    while (d <= tmax) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    cout << ans << endl;
    return 0;
}

bool check(int t) {
    // cout << "check: t = " << t << endl;
    int tot = 0;
    for (int i = 0; i < n; ++i) tot += cal(p[i], t);
    return tot <= b;
}

int cal(int p, int t) {
    if (t == 0) return p ? inf : 0;
    if (log2(p) > t) return inf;
    if (log2(p) == t && p > (1 << (t - 1))) return inf;
    if (p <= t) return 0;
    p -= t;
    int k;
    for (int i = 0; i < 20; ++i) {
        if ((t - i) * (1 << i) > t + p) {
            k = i - 1; break;
        }
    }
    return ((p + t - (1 << (k + 1))) + t - k - 3) / (t - k - 2) - 1;
}
