//
// Created by Wayne Tu on 3/30/16.
//

#include <iostream>

using namespace std;

bool year(int y) {
    if (y % 4 == 0 && y % 100 != 0) {
        return true;
    }

    else if (y % 400 == 0) {
        return true;
    }

    else {
        return false;
    }
}

int main() {
    int y;
    while (cin >> y) {
        if (year(y)) cout << "a leap year\n";
        else cout << "a normal year\n";
    }

    return 0;
}