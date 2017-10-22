#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e14;
int f, t, t0, a1, t1, p1, a2, t2, p2;


int main() {
    cin >> f >> t >> t0 >> a1 >> t1 >> p1 >> a2 >> t2 >> p2;
    long long d = inf, ans = inf; while (d < inf) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
}
