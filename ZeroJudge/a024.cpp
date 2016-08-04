//
// Created by Wayne Tu on 3/31/16.
//

#include <iostream>

using namespace std;

int gcd(int x, int y) {
    if (x == 0) {
        return y;
    }

    else if (y == 0) {
        return x;
    }

    else if (x > y) {
        x = x % y;
        return gcd(x, y);
    }

    else {
        y = y % x;
        return gcd(x, y);
    }
}

int main() {
    int x, y;
    while (cin >> x >> y) {
        cout << gcd(x, y) << '\n';
    }

    return 0;
}