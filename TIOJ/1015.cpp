//
// Created by Wayne Tu on 4/12/16.
//

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    long long int m, n;
    while (scanf("%lld %lld", &m, &n)) {
        if (m == 0 && n == 0) break;
        long long int sum;
        if (m < n) swap(m, n);
        sum = m * n * (n + 1) - n * (n + 1) / 2 * (m + n) + n * (n + 1) * (2 * n + 1) / 6;
        printf("%lld\n", sum);
    }
    return 0;
}
