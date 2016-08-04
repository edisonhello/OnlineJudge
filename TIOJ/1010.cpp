//
// Created by Wayne Tu on 4/22/16.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char p[1500]; int pn;
char q[1500]; int qn;
string P, Q;

int main() {
    int ans = 0;
    scanf("%s %s", p, q);
    pn = strlen(p);
    qn = strlen(q);
    for (int i = 0; i < min(pn, qn); ++i) {
	    P += p[i];
	    Q = q[qn - i - 1] + Q;
	    if (P == Q) ans = i + 1;
    }
    printf("%d\n", ans);
    return 0;
}
