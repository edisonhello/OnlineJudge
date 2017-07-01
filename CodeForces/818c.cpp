#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

struct Sofa {
    int x1, y1, x2, y2;
} s[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int d, n, m; cin >> d >> n >> m;
    for (int i = 1; i <= d; ++i) cin >> s[i].x1 >> s[i].y1 >> s[i].x2 >> s[i].y2;
    int cntl, cntr, cntt, cntb; cin >> cntl >> cntr >> cntt >> cntb;
        
    return 0;
}
