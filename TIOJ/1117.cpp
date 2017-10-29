#include <bits/stdc++.h>
using namespace std;

bool go(int n, int i, int j) {
    if (n == 0) return true;
    int b = (1 << n) >> 1;
    if (i > b && j > b) return !go(n - 1, i - b, j - b);
    if (i > b && j <= b) return go(n - 1, i - b, j);
    if (i <= b && j > b) return go(n - 1, i, j - b);
    if (i <= b && j <= b) return go(n - 1, i, j);
}

int main() {
    int n, i, a, b; while (cin >> n >> i >> a >> b) {
        for (int j = a; j <= b; ++j) cout << (go(n, i, j) ? '-' : '+') << 1 << ' ';
        cout << endl;
    }
    return 0;
}
