#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(nullptr));
    freopen("in.txt", "w", stdout);
    cout << 200000 << endl;
    for (int i = 1; i <= 200000; ++i) {
        cout << (long long)rand() * (long long)rand() % 200000 + 1 << ' ';
    }
    for (int i = 2; i <= 200000; ++i) {
        cout << rand() % (i - 1) + 1 << ' ' << i << endl;
    }
}
