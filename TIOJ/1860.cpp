#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include "lib1860.h"
using namespace std;

const long double e = 2.7182818284590452353602;

int main() {
    int t = Start_The_Loli_Dream();
    while (t--) {
        int n = Count_How_Many_Loli();
        int r = ceil((long double)n / e);
        int Max = INT_MIN, cnt = n;
        for (int i = 0; i < r; ++i, --cnt) {
            int p = Get_Loli_Moeness();
            Max = max(Max, p);
        }
        bool ans = false;
        while (cnt-- && !ans) {
            int p = Get_Loli_Moeness();
            if (p > Max) You_Choose_This_Loli(), ans = true;
        }
        if (!ans) You_Choose_This_Loli();
    }
    return 0;
}
