//
// Created by Wayne Tu on 4/25/16.
//

#include <stdio.h>

int main() {
    int p, q;
    scanf("%d%d", &p, &q);
    if (p > q) {
        if (p % q == 0) {
            printf("Y\n");
        }
        else {
            printf("N\n");
        }
    }
    else {
        if (q % p == 0) {
            printf("Y\n");
        }
        else {
            printf("N\n");
        }
    }
    return 0;
}