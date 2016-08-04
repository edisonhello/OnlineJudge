//
// Created by Wayne Tu on 4/6/16.
//

#include <iostream>
using namespace std;

void solve(int num) {
    int k = 1;
    int t = 0;
    while (k <= num) {
        k *= 2;
        t++;
    }

    k /= 2;
    t--;

    while (t >= 0) {
        if (k <= num) {
            num -= k;
            k /= 2;
            t--;
            cout << "1";
        }

        else {
            k /= 2;
            t--;
            cout << "0";
        }
    }
}

int main() {
    int num;
    while (cin >> num) {
        solve(num);
        cout << '\n';
    }

    return 0;
}