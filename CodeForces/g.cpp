#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(nullptr));
    freopen("in.txt", "w", stdout);
    cout << 100000 << ' ' << 100 << endl;
    for (int i = 1; i <= 100000; ++i) {
        int t = rand() % 2;
        if (t) cout << (ll)rand() * (ll)rand() % (100000) + 1 << ' '; 
        else cout << -((ll)rand() * (ll)rand() % 100000 + 1) << ' ';
    }
    cout << endl;
    for (int i = 1; i <= 100000; ++i) {
        cout << rand() % (100000) + 1 << ' ';
    }
    cout << endl;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 2; ++j) {
            int t = rand() % 2;
            if (t) cout << (ll)rand() * (ll)rand() % (100000) + 1 << ' '; 
            else cout << -((ll)rand() * (ll)rand() % 100000 + 1) << ' ';
        }
        cout << endl;
    }
}
