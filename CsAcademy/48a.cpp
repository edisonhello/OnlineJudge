#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b; cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        int k; cin >> k; a += k;
    }
    for (int i = 0; i < n; ++i) {
        int k; cin >> k; b += k;
    }
    if (a > b) cout << "1" << endl;
    else if (b > a) cout << "2" << endl;
    else cout << "0" << endl;
    return 0;
}
