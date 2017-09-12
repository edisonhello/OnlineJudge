#include <bits/stdc++.h>
using namespace std;

const int maxn = 1200 + 10, inf = 1e9 + 1;
int f[maxn], win[maxn][maxn]; // 1: N, 0: M
pair<int, int> dp[maxn][maxn], t[maxn][maxn];

void go(int n, int m, int last = -1) {
    if (n == 0 || m == 0) {
        win[n][m] = (n == 0 ? 1 : 0);
        return;
    }
    if (dp[n][m].first) return;
    dp[n][m] = make_pair(inf, inf);
    if (n > m) {
        for (int i = 1; i <= m; ++i) {
            go(n - i, m, 1);
            if (dp[n - i][m].first + f[i] <= dp[n][m].first) {
                dp[n][m] = make_pair(dp[n - i][m].first + f[i], dp[n - i][m].second);
                t[n][m] = make_pair(n - i, m);
                win[n][m] = win[n - i][m];
            }
        }
    } else if (n < m) {
        for (int i = 1; i <= n; ++i) {
            go(n, m - i, 0);
            if (dp[n][m - i].second + f[i] <= dp[n][m].first) {
                dp[n][m] = make_pair(dp[n][m - i].first, dp[n][m - i].second + f[i]);
                t[n][m] = make_pair(n, m - i);
                win[n][m] = win[n][m - i];
            }
        }
    } else {
        if (last == 1) {
            for (int i = 1; i <= n; ++i) {
                go(n, m - i, 0);
                if (dp[n][m - i].second + f[i] <= dp[n][m].first) {
                    dp[n][m] = make_pair(dp[n][m - i].first, dp[n][m - i].second + f[i]);
                    t[n][m] = make_pair(n, m - i);
                    win[n][m] = win[n][m - i];
                }
            }   
        } else {
            for (int i = 1; i <= m; ++i) {
                go(n - i, m, 1);
                if (dp[n - i][m].first + f[i] <= dp[n][m].first) {
                    dp[n][m] = make_pair(dp[n - i][m].first + f[i], dp[n - i][m].second);
                    t[n][m] = make_pair(n - i, m);
                    win[n][m] = win[n - i][m];
                }
            }   
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= min(n, m); ++i) cin >> f[i];
    go(n, m);
    if (win[n][m] == 1) cout << "Dalu" << endl;
    else cout << "bc4iaaa" << endl;
    cout << dp[n][m].first << ' ' << dp[n][m].second << endl;
    pair<int, int> cur = make_pair(n, m);
    vector<int> ans;
    while (cur.first && cur.second) {
        pair<int, int> tr = t[cur.first][cur.second];
        ans.push_back(max(cur.first - tr.first, cur.second - tr.second));
        // cout << max(cur.first - tr.first, cur.second - tr.second);
        cur = tr;
    }
    cout << ans.size() << endl;
    for (int i : ans) cout << i << endl;
    return 0;
}
