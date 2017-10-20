#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;
int a[maxn];

int go(int l, int r) {
    if (l > r) return 0;
    int m = inf;
    for (int i = l; i <= r; ++i) m = min(m, a[i]);
    for (int i = l; i <= r; ++i) a[i] -= m;
    int p = l, ret = 0;
    while (p <= r && a[p] == 0) ++p;
    int ptr = p;
    while (ptr <= r) {
        while (p <= r && a[p] == 0) ++p;
        ptr = p;
        while (ptr <= r && a[ptr] > 0) ++ptr;
        ret += go(p, ptr - 1);
        p = ptr + 1;
    }
    return ret + 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i]; 
    cout << go(0, n - 1) << endl;
    return 0;
}
