#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set<pair<int, int>> s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(nullptr));
    freopen("in.txt", "w", stdout);
    cout << 80 << ' ' << 50 << endl;
    cout << 2000 << endl;
    for (int i = 0; i < 2000; ++i) {
        int a = rand() % 80 + 1, b = rand() % 80 + 1;
        while (s.count(make_pair(a, b))) a = rand() % 80 + 1, b = rand() % 80 + 1;
        int c = rand() % 100 + 1;
        cout << a << ' ' << b << ' ' << c << endl;
        s.insert(make_pair(a, b));
    }
    return 0;
}
