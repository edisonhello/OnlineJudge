//
// Created by Wayne Tu on 4/28/16.
//

#include <iostream>
#include <stdio.h>
using namespace std;

void calc(double r1, double i1, char c, double r2, double i2) {
    switch(c) {
        case '+': {
            Answer(r1 + r2, i1 + i2);
            break;
        }
        case '-': {
            Answer(r1 - r2, i1 - i2);
            break;
        }
        case '*': {
            Answer(r1 * r2 - i1 * i2, r1 * i2 + r2 * i1);
            break;
        }
        case '/': {
            double d = r2 * r2 + i2 * i2;
            double r3 = r2 * r1 - i2 * i1 * -1;
            double i3 = r1 * i2 * -1 + r2 * i1;
            Answer(r3 / d, i3 / d);
            break;
        }
    }
}