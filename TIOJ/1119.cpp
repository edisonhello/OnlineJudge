#include <bits/stdc++.h>
using namespace std;

const int maxn = 15;
int c[maxn];

int go(int n) {
    if (n == 0) return 0;
    if (c[n] == 1) return 2 * go(n - 1) + 1;
    return 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        for (int i = 1; i <= n; ++i) cin >> c[i];
        cout << go(n) << endl;
    }
    return 0;
}
