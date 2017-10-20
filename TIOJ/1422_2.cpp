#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 120, k = 14;
int n, m, ans;

void go(bitset<maxn> s, int now) {
    if (1.0 * clock() / CLOCKS_PER_SEC >= 5.999) return;
    if (s.count() && now >= ans - 1) return;
    if (s.count() == 0) {
        ans = min(ans, now);
        return;
    }
    for (int u = s._Find_first(), cnt = 0; u < n * m && cnt < k; u = s._Find_next(u + 1), ++cnt) {
        bitset<maxn> nxt = s;
        int r = u / m, c = u % m;
        for (int i = 0; i < n; ++i) nxt[i * m + c] = false;
        for (int i = 0; i < m; ++i) nxt[r * m + i] = false;
        for (int i = 0; ; ++i) {
            if ((r - i < 0 || c - i < 0) && (r - i < 0 || c + i >= m) && (r + i >= n || c - i < 0) && (r + i >= n || c + i >= m)) break;
            if (r - i >= 0 && c - i >= 0) nxt[(r - i) * m + c - i] = false;
            if (r - i >= 0 && c + i < m) nxt[(r - i) * m + c + i] = false;
            if (r + i < n && c - i >= 0) nxt[(r + i) * m + c - i] = false;
            if (r + i < n && c + i < m) nxt[(r + i) * m + c + i] = false;
        }
        go(nxt, now + 1);
    } 
}

int main() {
    clock();
    cin >> n >> m; 
    bitset<maxn> s;
    ans = min(n, m);
    for (int i = 0; i < n * m; ++i) s[i] = true;
    go(s, 0);
    cout << ans << endl;
    return 0;
}
