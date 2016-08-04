//
// Created by Wayne Tu on 5/27/16.
//

#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
struct dinner {
    int c;
    int e;
};
int main() {
    int n;
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        dinner *Dinner;
        Dinner = new dinner[n];
        int *E = new int[n];
        int t = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &Dinner[i].c, &Dinner[i].e);
            E[i] = Dinner[i].e;
            t += Dinner[i].c;
        }
        sort(E, E + n);
        t += E[0];
        printf("%d\n", t);
        delete Dinner;
    }
    return 0;
}