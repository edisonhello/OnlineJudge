#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(nullptr));
    freopen("in.txt", "w", stdout);
    cout << 100000 << ' ' << 300 << endl;
    for (int i = 0; i < 100000; ++i) {
        cout << (long long)rand() * (long long)rand() % (1000000000) + 1 << ' ';
    }
}
