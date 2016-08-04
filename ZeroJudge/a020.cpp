//
// Created by Wayne Tu on 3/31/16.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;

int number(string num) {
    int k = 8;
    int number = 0;
    for (int i = 1; i < 9; i++) {
        number += ((num[i] - '0') * k);
        k--;
    }

    return number;
}

int charNumber(char c) {
    switch(c) {
        case 'A':
            return 1;
        case 'B':
            return 10;
        case 'C':
            return 19;
        case 'D':
            return 28;
        case 'E':
            return 37;
        case 'F':
            return 46;
        case 'G':
            return 55;
        case 'H':
            return 64;
        case 'I':
            return 39;
        case 'J':
            return 73;
        case 'K':
            return 82;
        case 'L':
            return 2;
        case 'M':
            return 11;
        case 'N':
            return 20;
        case 'O':
            return 48;
        case 'P':
            return 29;
        case 'Q':
            return 38;
        case 'R':
            return 47;
        case 'S':
            return 56;
        case 'T':
            return 65;
        case 'U':
            return 74;
        case 'V':
            return 83;
        case 'W':
            return 21;
        case 'X':
            return 3;
        case 'Y':
            return 12;
        case 'Z':
            return 30;
    }
}

bool solve(string num) {
    int sum = 0;
    sum += charNumber(num[0]);

    sum += number(num);
    sum += num[9] - '0';
    if (sum % 10 == 0) {
        return true;
    }

    else {
        return false;
    }

}
int main() {
    string num;

    while (cin >> num) {
        if (solve(num)) {
            cout << "real\n";
        }

        else {
            cout << "fake\n";
        }
    }
}
