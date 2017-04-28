#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
int d, n;
double k[maxn], s[maxn];

double bs(double, double);
bool check(double);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ": ";
        cin >> d >> n;
        for (int i = 0; i < n; ++i) cin >> k[i] >> s[i];
        double Max = 0.0;
        for (int i = 0; i < n; ++i) {
            Max = max(Max, ((double)d - k[i]) / s[i]);
        }
        cout << fixed << setprecision(7) << (double)d / Max << '\n';
    }
    return 0;
}

