#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
const double inf = 1e9;
int cnt[2][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 1; i <= n; ++i) {
        int c = s[i - 1] - '0';
        cnt[c][i] = cnt[c][i - 1] + 1;
        cnt[c ^ 1][i] = cnt[c ^ 1][i - 1];
    }
    double m = inf; int ans = -1;
    for (int i = 1; i < n; ++i) {
        long long l = (long long)cnt[0][i] * (long long)(i - cnt[0][i]) + (long long)cnt[1][i] * (long long)(i - cnt[1][i]);
        long long r = (long long)(cnt[0][n] - cnt[0][i]) * (long long)(n - i - cnt[0][n] + cnt[0][i]) + 
                      (long long)(cnt[1][n] - cnt[1][i]) * (long long)(n - i - cnt[1][n] + cnt[1][i]);
        if ((double)r / (double)(n - i) + (double)l / (double)i < m) ans = i, m = (double)r / (double)(n - i) + (double)l / (double)i;
    }
    cout << ans << endl;
    return 0;
}
