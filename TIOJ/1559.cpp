#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    double x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        double vx = x2 - x1, vy = y2 - y1;
        double vx_ = cos(pi / 3) * vx - sin(pi / 3) * vy;
        double vy_ = sin(pi / 3) * vx + cos(pi / 3) * vy;
        double x11 = x1 + vx_, y11 = y1 + vy_;
        vx_ = cos(-pi / 3) * vx - sin(-pi / 3) * vy;
        vy_ = sin(-pi / 3) * vx + cos(-pi / 3) * vy;
        double x22 = x1 + vx_, y22 = y1 + vy_;
        if (x11 < x22) cout << fixed << setprecision(3) << x11 << ' ' << y11 << ' ' << x22 << ' ' << y22 << '\n';
        else if (x11 > x22) cout << fixed << setprecision(3) << x22 << ' ' << y22 << ' ' << x11 << ' ' << y11 << '\n';
        else {
            if (y11 < y22) cout << fixed << setprecision(3) << x11 << ' ' << y11 << ' ' << x22 << ' ' << y22 << '\n';
            else  cout << fixed << setprecision(3) << x22 << ' ' << y22 << ' ' << x11 << ' ' << y11 << '\n';
        }
    }
    return 0;
}
