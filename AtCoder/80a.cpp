#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int t = 0;
        while (a[i] % 2 == 0) a[i] >>= 1, ++t;
        a[i] = t;
    }
    int z = 0, o = 0, t = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) ++z;
        else if (a[i] == 1) ++o;
        else ++t;
    }
    // if (z > t) return cout <<
    --z;
    if (z > t) return cout << "No" << endl, 0;
    if (z == t) {
        if (o) return cout << "No" << endl, 0;
        else return cout << "Yes" << endl, 0;
    }
    cout << "Yes" << endl;
    return 0;
}
