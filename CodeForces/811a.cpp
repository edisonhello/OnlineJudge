#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b; cin >> a >> b;
    int aa = 0, bb = 0, t = 1, tt = 2;
    while (a > 0) {
        if (a >= t) a -= t;
        else a = 0;
        t += 2;
        ++aa;
    }
    while (b) {
        if (b >= tt) b -= tt;
        else b = 0;
        tt += 2;
        ++bb;
    }
    if (aa <= bb) cout << "Valera\n";
    else cout << "Vladik\n";
    return 0;
}
