#include <bits/stdc++.h>
using namespace std;

const int N = 50000, Q = 10000;

int main() {
    srand(time(NULL));
    freopen("in.txt", "w", stdout);
    cout << 1 << '\n';
    cout << N << ' ' << Q << '\n';
    for (int i = 1; i <= N; ++i) cout << (long long)rand() * (long long)rand() % INT_MAX + 1 << ' ';
    cout << '\n';
    for (int i = 0; i < Q; ++i) {
        int tp = rand() % 3 + 1;
        cout << tp << ' ';
        if (tp == 1) {
            int l = rand() % N + 1, r = rand() % (N - l + 1), k = rand() % (r + 1) + 1;
            cout << l << ' ' << l + r << ' ' << k << '\n';
        }
        if (tp == 2) {
            int x = rand() % N + 1, k = (long long)rand() * (long long)rand() % INT_MAX + 1;
            cout << x << ' ' << k << '\n';
        }
        if (tp == 3) {
            cout << 1 << ' ' << 2 << '\n';
        }
    }
    return 0;
}
