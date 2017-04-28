#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
pair<int, int> p[maxn];
int n, m, k;

int bs(int, int);
bool check(int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    int ub = 0;
    for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second, ub = max({ ub, p[i].first, p[i].second });
    cout << bs(0, ub + 1) << '\n';
    return 0;
}

int bs(int l, int r) {
    if (r - l == 1) return l;
    int m = l + r >> 1;
    if (check(m)) return bs(m, r);
    return bs(l, m);
}

bool check(int x) {
    int cnt[2] = {0, 0};
    for (int i = 0; i < n; ++i) {
        if (p[i].first < x && p[i].second < x) ++cnt[1];
        else if (p[i].first < x || p[i].second < x) ++cnt[0];
    }
    int kk = 2 * m - k, mm = 0;
    while (kk > 0 && cnt[1]) {
        kk -= 2; cnt[1]--;
        ++mm;
    }
    while (kk > 0 && cnt[0]) {
        kk--, cnt[0]--;
        ++mm;
    }
    return mm <= m;
}
