#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
const double pi = acos(-1);
double mem[maxn][maxn];
int n, k;

struct Cake { double r, h; } c[maxn];
double dp(int, int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ": ";
        cin >> n >> k;
        memset(mem, 0, sizeof(mem));
        for (int i = 0; i < n; ++i) cin >> c[i].r >> c[i].h;
        sort(c, c + n, [](const Cake& a, const Cake& b) {
            return a.r > b.r;
        });
        double ans = 0.0;
        for (int i = 0; i < n; ++i) ans = max(ans, dp(i, k, -1));
        cout << fixed << setprecision(9) << ans << '\n';
    }
    return 0;
}

double dp(int id, int k, int p) {
    if (n - id < k) return INT_MIN;
    if (id <= n && k == 0) {
        return pi * c[p].r * c[p].r;
    }
    if (id == n) return INT_MIN;
    if (mem[id][k]) return mem[id][k];
    mem[id][k] = 0.0;
    for (int j = id + 1; j <= n; ++j) {
        if (k == 1) mem[id][k] = max(mem[id][k], dp(j, k - 1, id));
        else mem[id][k] = max(mem[id][k], dp(j, k - 1, id) + pi * c[id].r * c[id].r - pi * c[j].r * c[j].r);
    }
    mem[id][k] += 2 * pi * c[id].r * c[id].h;
    return mem[id][k];
}
