//
// Created by Wayne Tu on 4/15/16.
//

//
// Created by Wayne Tu on 4/6/16.
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
    int count;
    cin >> count;
    for (int i = 0; i < count; i++) {
        int x, y;
        cin >> x >> y;
        cout << gcd(x, y) << '\n';
    }

    return 0;
}
