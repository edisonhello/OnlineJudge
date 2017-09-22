#include <bits/stdc++.h>
#define int long long 
using namespace std;

int cal(int a, int b) {
    int x = 0;
    while (true) {
        if (a == 0 && b == 0) return !(x & 1);
        if (a == 0) return (b & 1) ^ (x & 1);
        if (b == 0) return (a & 1) ^ (x & 1);
        if (a == b) return 1;
        if (a % 2 == 1) {
            if (b & 1) return (x & 1);
            else return !(x & 1);
        }
        if (b % 2 == 1) {
            if (a & 1) return (x & 1);
            return !(x & 1);
        }
        if (a < b) swap(a, b);
        x += a / b;
        a %= b;
    }
}

int32_t main() {
    int t, n, m; cin >> t; while (t--) {
        cin >> n >> m;
        cout << (cal(n, m) ? ">//<" : ">\\\\<") << endl;
    }
}
