//
// Created by Wayne Tu on 5/18/16.
//

#include <stdio.h>

unsigned long long DP[100][20];
int n, m;
int main() {
    DP[0][0] = 1;
    DP[1][0] = 1;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        unsigned long long sum = DP[i][0];
        for (int j = 1; j <= n; ++j) {
            DP[i][j] = DP[i - 1][j - 1];
            sum += DP[i][j];
        }
        if (i == m) {
            printf("%llu\n", sum);
        }
        else {
            DP[i + 1][0] = sum;
        }
    }
    return 0;
}