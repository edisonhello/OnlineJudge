//
// Created by Wayne Tu on 4/28/16.
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
        return gcd(x % y, y);
    }
    else {
        return gcd(y % x, x);
    }
}

int main() {
    int x, y;
    cin >> x >> y;
    if (x == 0 || y == 0) {
        int ans = x == 0 ? y + 1 : x + 1;
        cout << ans << '\n';
        return 0;
    }
    int g = gcd(x, y);
    int a = x / g;
    int b = y / g;
    int i = 0; int j = 0;
    int sprout = 0;
    while (i <= x && j <= y) {
        if (i * b == j * a) {
            sprout++;
            i++;
            j++;
        }
        else if (i * b > j * a) {
            j++;
        }
        else {
            i++;
        }
    }
    cout << sprout << '\n';
    return 0;
}