#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    long long sum, tag;
    SegmentTree(int L, int R) {
        lc = rc = nullptr; sum = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    return 0;
}
