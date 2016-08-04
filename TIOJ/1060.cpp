//
// Created by Wayne Tu on 3/27/16.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int g(int z) {
    if (z <= 2) {
        return z * z - 1;
    }

    else {
        return 2;
    }
}

int h(int y) {
    if (y < 2) {
        return -1;
    }

    else {
        return 2 + h(y - 1) + h(y - 2);
    }
}

int f(int x) {
    if (x > h(x)) {
        return f(x - 1) - h(x);
    }

    else if (x < h(x)) {
        return f(g(x)) - g(x);
    }

    else {
        return 1;
    }
}

int main(int argc, char* argv[]) {
    int x;
    int count = 1;
    while (x = stdin) {
        cout << "Sample Output #" << count << ":\n";
        cout << f(x) << '\n';
        count++;
    }

    return 0;
}