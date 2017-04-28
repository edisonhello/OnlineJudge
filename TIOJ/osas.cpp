#include <bits/stdc++.h>
using namespace std;

const int N = 10, Q = 100, C = 10;

int main() {
    freopen("in.txt", "w", stdout);
    cout << N << ' ' << Q << ' ' << C << '\n';
    for (int i = 0; i < N; ++i) cout << rand() % (1 << C) << ' ';
    for (int i = 0; i < Q; ++i) {
        int tp = rand() % 2;
        cout << tp << ' ';
        if (tp) {
            int x, y, k;
            x = rand() % N, y = rand() % N;
            if (x == y) ++y;
            if (x > y) swap(x, y);
            k = rand() % (1 << C);
            cout << x << ' ' << y << ' ' << k << '\n';
        } else {
            int p = rand() % N, k = rand() % (1 << C);
            cout << p << ' ' << k << '\n';
        }
    }
    return 0;
}
