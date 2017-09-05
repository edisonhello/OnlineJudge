#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(nullptr));
    freopen("in.txt", "w", stdout);
    cout << 200000 << ' ' << 10487 << ' ' << 17788 << endl;
    for (int i = 0; i < 200000; ++i) {
        cout << (long long)rand() * (long long)rand() % 1000000 + 1 << ' ';
    }
    cout << endl;
    return 0;
}
