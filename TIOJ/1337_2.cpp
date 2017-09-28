#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
pair<int, int> p[maxn];
bool v[maxn];
int n, k;

bool check(int lim) {
    memset(v, false, sizeof(v));
    int now = 0, use = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq2;
    for (int i = 0; i < n; ++i) {
        while (pq1.size() && pq1.top().first < p[i].first) {
            if (!v[pq1.top().second]) v[pq1.top().second] = true, --now;
            pq1.pop();
        }
        pq1.push(make_pair(p[i].second, i)); pq2.push(make_pair(p[i].second, i));
        ++now;
        if (now > lim) {
            while (pq2.size() && v[pq2.top().second]) pq2.pop();
            ++use; --now; 
            v[pq2.top().second] = true; pq2.pop();
        }
    }
    return use <= k;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second, --p[i].second;
    sort(p, p + n);
    int d = 1, ans = n; while (d <= n) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    cout << ans << endl;
    return 0;
}
