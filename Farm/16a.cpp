#include <bits/stdc++.h>
using namespace std;

int da[4], db[4];

int main() {
    int a, b, c; cin >> a >> b >> c;
    int ta = a, tb = b, ma = -1, mb = -1;
    for (int i = 0; i < 4; ++i) {
        da[i] = ta % 10;
        if (da[i] == 0) ma = i;
        ta /= 10;
    }
    for (int i = 0; i < 4; ++i) {
        db[i] = tb % 10;
        if (db[i] == 0) mb = i;
        tb /= 10;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (i == ma - 1 && j == 0) continue;
            int t = da[i]; da[i] = j;
            int aa = da[0] + da[1] * 10 + da[2] * 100;
            if (aa < 100) continue;
            if (aa * b == c) {
                cout << aa << ' ' << b << endl;
                return 0;
            }
            da[i] = t;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (i == mb - 1 && j == 0) continue;
            int t = db[i]; db[i] = j;
            int bb = db[0] + db[1] * 10 + db[2] * 100;
            if (bb < 100) continue;
            if (a * bb == c) {
                cout << a << ' ' << bb << endl;
                return 0;
            }
            db[i] = t;
        }
    }
    return 0;
}
