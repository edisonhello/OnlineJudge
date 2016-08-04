//
// Created by Wayne Tu on 4/28/16.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int gcd(int a, int b) {
    if (a == 0) {
        printf("one zero\n");
        return b;
    }
    else if (b == 0) {
        printf("one zero\n");
        return a;
    }
    else if (a % 2 == 0 && b % 2 == 0) {
        printf("both even\n");
        return 2 * gcd(a / 2, b / 2);
    }
    else if (a % 2 == 1 && b % 2 == 1) {
        printf("both odd\n");
        if (a > b) {
            return gcd(a - b, b);
        }
        else {
            return gcd(b - a, a);
        }
    }
    else {
        printf("one odd\n");
        if (a % 2 == 0) {
            return gcd(a / 2, b);
        }
        else if (b % 2 == 0) {
            return gcd(b / 2, a);
        }
    }
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", gcd(a, b));
    return 0;
}