#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t; while (t--) {
        int a, b, c; cin >> a >> b >> c;
        if ((a + b + c) % 2) {
            cout << "-1" << endl;
            continue;
        }
        int s = (a + b + c) / 2;
        // int x1 = 0, y1 = 1, x2 = 0, y2 = 0;
        // c = b, b = a;
        // if (b - 1 <= s - 1) {
            // x1 = b - 1; y1 = 1;
            // if (c <= s - b) x2 = b - 1 + c, y2 = 1;
            // else if (c == s - b + 1) x2 = s - 1, y2 = 0;
            // else x2 = s - 1 - (c - (s - b) - 1), y2 = 0;
        // } else if (b - 1 == s) {
            // x1 = s - 1, y1 = 0;
            // x2 = s - 1 - c, y2 = 0;
        // } else {
            // x1 = s - 1 - (b - 1 - s + 1 - 1), y1 = 0;
            // x2 = x1 - c; y2 = 0;
        // }
        vector<int> v = { a, b, c };
        sort(v.begin(), v.end());
        a = v[0]; b = v[1]; c = v[2];
        if (c > s) {
            cout << "-1" << endl;
            continue;
        }
        int x1, y1, x2, y2;
        int n = c + a - s;
        int m = s - n;
        x1 = c - n; y1 = n;
        y2 = n - (a - (m - (c - n)));
        x2 = m;
        cout << 0 << ' ' << 0 << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    }
    return 0;
}
