#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1);

int main() {
    double n, l;
    while (cin >> n >> l) {
        double th = 2 * pi / n;
        cout << fixed << setprecision(3) << l / sin(th / 2) / 2 << endl;
    }
    return 0;
}
