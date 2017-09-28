#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(nullptr));
    freopen("in.txt", "w", stdout);
    cout << 100 << endl;
    for (int i = 0; i < 100; ++i) {
        int t = rand() % 20 + 1;
        int d = rand() % 2000 + 1;
        int p = rand() % 20 + 1;
        cout << t << ' ' << d << ' ' << p << endl;
    }
}
