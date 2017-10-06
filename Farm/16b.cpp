#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    if (k == n - 1) {
        cout << n * k / 2 << endl;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                cout << i << ' ' << j << endl;
            }
        }
        return 0;
    }
    if (n % 2 == 1 && k % 2 == 1) return cout << "Oops!" << endl, 0;
    if (k == 1) {
        cout << n / 2 << endl;
        for (int i = 1; i <= n; i += 2) {
            cout << i << ' ' << i + 1 << endl;
        }
        return 0;
    } 
    cout << n * k / 2 << endl;
    set<pair<int, int>> ed;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k / 2; ++j) {
            int t = (i + j) % n;
            if (t == 0) t = n;
            if (ed.count(minmax(i, t)) == 0) 
                cout << i << ' ' << t << endl, ed.insert(minmax(i, t));
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k / 2; ++j) {
            int t = (i - j + n) % n;
            if (t == 0) t = n;
            if (ed.count(minmax(t, i)) == 0) 
                cout << t << ' ' << i << endl, ed.insert(minmax(t, i));
        }
    }
    if (k & 1) {
        for (int i = 1; i <= n / 2; ++i) {
            cout << i << ' ' << i + n / 2 << endl;
        }
    }
    return 0;
}
